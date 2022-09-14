#include "project.h"
#include <stdio.h>
#include "main.h"
#include "usbUart.h"
#include "therm_calibrate.h"
#include "removeOffsetNoise.h"
#include "mesureTemp.h"
#include "therm_calibrate.h"
#include "PID.h"
#include "Profile.h"
#include "PID_AutoTune_v0.h"
#include <stdlib.h> // Header file containing strtof function 



typedef enum maintcmesurementstatus {tcIdle,tc1Started,tc2Started} mainTcMesurementStatus;

#ifdef AUTOTUNE
#warning "maybe change this"
#define PID_AUTO_TUNE_OUTPUT_STEP 65535
#define PID_AUTO_TUNE_LOOKBACKSEC 300
#endif


#define MESUREMENT_PERIOD_MS 2179


#define FIRSTCOMMAND 'A'
#define LASTCOMMAND 'Z'
#define USB_COMMAND_SET_P 'P'
#define USB_COMMAND_SET_I 'I'
#define USB_COMMAND_SET_D 'D'
#define USB_COMMAND_GET_PID 'G'
#define USB_COMMAND_START_REFLOW 'S'
#define USB_COMMAND_STOP_REFLOW 'A'
#define USB_COMMAND_SET_TARGET 'T'

void handleHostMessages();
void processCommand();
uint8 rxString[16]={0};
uint8 rxStringNextIndex=0;

void handleNewTempReady();
void runMyProfile(float targetTemp);

mainTcMesurementStatus TcMesurementStatus = tcIdle; //says witch tc is being mesured
uint8 newTempReady = 0; //says if there is a new mesurement ready
float tc_1_temp,tc_2_temp;//says if

float pidResult=0;

uint8_t mainbootlock = 1;

pidCtrl heater1;

uint8_t runningProfile=0;

tempProfile currentProfile;

//set temp in C
float target = 100;

int main(void)
{
    int8 status;
    
    int16 dieTemp;
    
    
    
    #ifdef AUTOTUNE
    uint8_t tuning=1;
    #endif
    
    
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    Opamp_1_Start();
    usbUart_Start();
    ADCMux_Start();
    ADC_Start();
    PWM_Heater_Start();
    PWM_Heater_WriteCompare(0);//turn heater off
    ADCMux_Select(0);
    
    
    
    
    
    heater1.p = 10000;
    heater1.i = 0;
    heater1.d = 5000;
    heater1.lastError = 0;
    
    
    
    
    
    /* Sets up interrupts and enable */
    
    
    isr_reset_StartEx(IsrHandler_reset);
    writeStringToHost("Oven Controler------------\n\r");
    DieTemp_GetTemp(&dieTemp);
    sprintf(temp_string, "Psoc Die Temp is : %d C\n\r",dieTemp);
    writeStringToHost(temp_string);
    
    
    
    #ifdef DEBUG
        sprintf(temp_string, "TC1 : %5.2fC\n\r", mesureTC_Blocking(TC1,(uint8*)&status));
        writeStringToHost(temp_string);
    #endif
    
    #ifdef DEBUG
        sprintf(temp_string, "TC2 : %5.2fC\n\r", mesureTC_Blocking(TC2,(uint8*)&status));
        writeStringToHost(temp_string);
    #endif
    

    
    for(;;)
    {
        serviceUsb();
        
        
        handleHostMessages();
        
        if (usb_Ready()){
            //the usb device has receved atleast one chariter
            
            if(mainbootlock == 1){
                mainbootlock = 0;
                //this is run the first time loop starts after the serial port has started and a key has been pressed
                
                #ifdef AUTOTUNE
                    /*
                if(tuning)
                {
                    tuning=0;
                    //link auto tuneing to the real inputs and outputs
                    PID_ATune(&tc_1_temp, &pidResult);
                    PID_ATune_SetRuntimeIntrival(2179);
                    PID_ATune_SetNoiseBand(.5);  //there may be 2 degrees of noise
                    PID_ATune_SetOutputStep(PID_AUTO_TUNE_OUTPUT_STEP);
                    PID_ATune_SetLookbackSec((int)PID_AUTO_TUNE_LOOKBACKSEC);
                    tuning = 1;
                }
                    */
                #endif
                
                
                isr_500ms_StartEx(IsrHandler_500ms);
            }
            
            handleNewTempReady();
            
            
        }
    
    }
}


void handleNewTempReady(){
    static uint8 tcNumber;
    if (newTempReady == 1){
                newTempReady = 0;
                if ( TcMesurementStatus == tc1Started ){
                    
                    tc_1_temp = getTcTemp(&tcNumber );
                    if(tcNumber == TC1){
                        TcMesurementStatus = tc2Started;
                        startMesureTC_nonBlocking(TC2);
                    }else{
                        sprintf(temp_string, "Mesurement Error\n\r");
                        writeStringToHost(temp_string);
                    }
                }else if (TcMesurementStatus == tc2Started){
                    
                    tc_2_temp= getTcTemp(&tcNumber );
                    if(tcNumber == TC2){
                        
                        sprintf(temp_string, "TC1 : %5.2fC\n\r", tc_1_temp);
                        writeStringToHost(temp_string);
                        sprintf(temp_string, "TC2 : %5.2fC\n\r", tc_2_temp);
                        writeStringToHost(temp_string);
                        
                        if (runningProfile){
                            
                            runMyProfile(target);
                        }else{
                            runMyProfile(0);
                        }
                        
                    }else{
                        sprintf(temp_string, "Mesurement Error\n\r");
                        writeStringToHost(temp_string);
                    }
                    
                        TcMesurementStatus = tcIdle;
                }
            }
}


void handleHostMessages(){
    
    
    //handle incomeing strings from the host--------
    if (rxStringNextIndex == sizeof(rxString)/sizeof(rxString[0])){
        //if there was a string verflow start from the begining
        rxStringNextIndex=0;
    }
    if(getByteFromHost(&rxString[rxStringNextIndex])!=0){
        if (rxStringNextIndex == 0){
            //if this is the first byte of the command
            if((rxString[0]>=FIRSTCOMMAND) && (rxString[0]<=LASTCOMMAND)){
                //if the first char was a valid command
                
                rxStringNextIndex++;
            }
        } else{
            //if this is not the first byte in the command
            
            if ((rxString[rxStringNextIndex]=='\r')||(rxString[rxStringNextIndex]=='\n')){
                //end of command
                processCommand();
                rxStringNextIndex=0;
            }else{
               rxStringNextIndex++;
            }
        
        }
        
        
        
    }
    
    
}


void runMyProfile(float targetTemp){
    float myPTarget;
    #ifdef AUTOTUNE
        /*
    if(tuning)
        {
            uint8_t val = (PID_ATune_Runtime());
            if (val!=0)
            {
                tuning = 0;
            }
            if(!tuning)
            { //we're done, set the tuning parameters
                heater1.p = PID_ATune_GetKp();
                heater1.i = PID_ATune_GetKi();
                heater1.d = PID_ATune_GetKd();
            }
        }
        */
    #endif
    
    
    #warning "i left off here with the profile, cleanup the profile stop sequence"
    
    if (targetTemp!=0){
        myPTarget = runProfile(&currentProfile,tc_1_temp,MESUREMENT_PERIOD_MS);
        sprintf(temp_string, "Target Temp : %5.2f\n\r", myPTarget);
        writeStringToHost(temp_string);
    }else{
        //clear the profile state and set target temp to 0
        endProfile(&currentProfile);
        myPTarget=0;
    }
    
    if (myPTarget==0){
        runningProfile=0;
        endProfile(&currentProfile);
    }
    
    pidResult = runPid(&heater1, tc_1_temp, myPTarget);

    
    //make sure pid value is in correct range
    if (pidResult > PWM_Heater_ReadPeriod()){
       pidResult = PWM_Heater_ReadPeriod();
    }else if (pidResult < 0){
        pidResult = 0;
    }
    sprintf(temp_string, "Pid Result : %5.2f\n\r", pidResult);
    writeStringToHost(temp_string);
    
    
    //send result to heater
    PWM_Heater_WriteCompare(pidResult);
    
}

void processCommand(){
/*
#define USB_COMMAND_SET_P 250
#define USB_COMMAND_SET_I 251
#define USB_COMMAND_SET_D 252
#define USB_COMMAND_START_REFLOW 128
*/
    switch(rxString[0]){

        case USB_COMMAND_SET_P:
            heater1.p = strtof(&rxString[1],NULL);
            sprintf(temp_string, "Set PID P = %.2f\n\r",heater1.p);
            writeStringToHost(temp_string);
            break;
            
        case USB_COMMAND_SET_I:
            heater1.i = strtof(&rxString[1],NULL);
            sprintf(temp_string, "Set PID I = %.2f\n\r",heater1.i);
            writeStringToHost(temp_string);
            break;
            
        case USB_COMMAND_SET_D:
            heater1.d = strtof(&rxString[1],NULL);
            sprintf(temp_string, "Set PID D = %.2f\n\r",heater1.d);
            writeStringToHost(temp_string);
            break;
            
        case USB_COMMAND_GET_PID:
            sprintf(temp_string, "PID P = %.2f\n\r    I = %.2f\n\r    D = %.2f\n\r    Target = %.2f\n\r",heater1.p,heater1.i,heater1.d,target);
            writeStringToHost(temp_string);
            break;
            
        case USB_COMMAND_START_REFLOW:
            if (!runningProfile){
                switch(atoi((const char*)&rxString[1])){
                    case(1):
                        memcpy(&currentProfile, &profile_snPb,sizeof(profile_snPb));
                        break;
                    case(2):
                        memcpy(&currentProfile, &profile_lf,sizeof(profile_lf));
                        break;
                    default:
                    return;
                        sprintf(temp_string, "bad profile, 1 for snpb, 2 for leadfree\n\r");                
                        writeStringToHost(temp_string);
                        break;
                }
                runningProfile=1;
                
                sprintf(temp_string, "Running Pid Profile\n\r");                
                writeStringToHost(temp_string);
            }
            break;
        
        case USB_COMMAND_STOP_REFLOW:
            if (runningProfile){
                runningProfile=0;
                
                //reset intigral so the pid can start agian fresh next time
                heater1.runningIntigral=0;
                sprintf(temp_string, "Stoping Pid Profile\n\r");
                writeStringToHost(temp_string);
            }
            break;
            
        
        case USB_COMMAND_SET_TARGET:
            target = strtof(&rxString[1],NULL);
            sprintf(temp_string, "Set target temp to %.2fC\n\r",target);
            writeStringToHost(temp_string);
            break;
            
        default:
            break;
    }
    
    
    
}



//tc mesurement cycle is complete
CY_ISR(EOCIsrHandler)
{

    /* Clear pending Interrupt */
    isr_eoc_ClearPending();
    isr_eoc_Stop();

    switch (getTCState()){
        case TC_STARTED:
            continueMesureTCResult();
        break;
        
        case TC_OFFSET:
            newTempReady=1;
        break;
        
        case TC_IDLE:
            #ifdef DEBUG
            sprintf(temp_string, "eoc error\n\r");
            writeStringToHost(temp_string);
            #endif
        break;
    }
    
}



//pwm heater pearod over
CY_ISR(IsrHandler_500ms)
{
    

    isr_500ms_ClearPending();
    
    if ((getTCState() == TC_IDLE) && (newTempReady == 0) && (TcMesurementStatus == tcIdle))
    {
        //start a new mesurement every time the pwm cycle is over
        TcMesurementStatus = tc1Started;
        startMesureTC_nonBlocking(TC1);
   
    }else{
        sprintf(temp_string, "something odd happened here\n\r");
        writeStringToHost(temp_string);
    }
}

CY_ISR(IsrHandler_reset)
{
    isr_reset_ClearPending();
    PWM_Heater_Stop();
    
    CySoftwareReset();

}

/* [] END OF FILE */
