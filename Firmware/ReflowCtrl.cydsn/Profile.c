/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "Profile.h"
#include "PID.h"

#include "usbUart.h"

const tempProfile profile_snPb={
    .preheatDegreesPerS=3,
    .soakStart=100,
    .soakTarget=150,
    .soakTime=90000,
    .reflowTarget=225,
    .reflowTime=5000,
    .msElapsed=0,
    .lastTemp=25,
    .state=OFF,
    .soakSteps=4,
};

const tempProfile profile_lf={
    .preheatDegreesPerS=3,
    .soakStart=150,
    .soakTarget=200,
    .soakTime=110000,
    .reflowTarget=245,
    .reflowTime=5000,
    .msElapsed=0,
    .lastTemp=25,
    .state=OFF,
    .soakSteps=4,
};

//returns target temp or 0 if the cycle has completed
float runProfile(tempProfile* myProfile, float currentTemp, unsigned int msElapsed){
    float ret;
    
    
    switch(myProfile->state){
        case OFF:
            myProfile->msElapsed+=msElapsed;
            myProfile->lastTemp=currentTemp;
            myProfile->state=PREHEAT;
            ret = myProfile->soakStart;
            
            break;
        
        case PREHEAT:
            myProfile->msElapsed+=msElapsed;
            sprintf(temp_string, "Preheating\n\r");
            writeStringToHost(temp_string);
            //allow 25% faster than speced rize time if nessary
            if ((myProfile->lastTemp + ((myProfile->preheatDegreesPerS/1000*msElapsed)*1.25)) < (currentTemp)){
                //if the temp rise was more than 25% faster than desired
                //set the target to be only one step higher, (where it should be next round exactly)
                ret = myProfile->lastTemp + (myProfile->preheatDegreesPerS/1000*msElapsed)*2;
            }else{
                //if we are not heating too quickly
                //set the target to the soakTarget
                ret = myProfile->soakStart;
            }
            if (currentTemp>=myProfile->soakStart*0.95){
                //if we are within 95% of our soak target, start the soak
                myProfile->state=SOAK;
                myProfile->msElapsed=0;
            }
            break;
        
        case SOAK:
            myProfile->msElapsed+=msElapsed;
            sprintf(temp_string, "Soaking\n\r");
            writeStringToHost(temp_string);
            //there will be 4 steps up in temp for soak if the start and stop temp are not the same
            #warning "there is something wrong with this equation"

            float soakRange = myProfile->soakTarget - myProfile->soakStart;
            float soakTempStepSizeC = soakRange / myProfile->soakSteps;
            unsigned int timeStepSize = myProfile->soakTime / myProfile->soakSteps;
            unsigned int timeIndex = myProfile->msElapsed / timeStepSize;
            ret = myProfile->soakStart + (soakTempStepSizeC * (timeIndex+1));
            
            if(myProfile->msElapsed>=myProfile->soakTime){
                myProfile->msElapsed=0;
                myProfile->state=REFLOW;
            }
            break;
        
        case REFLOW:
            if(currentTemp>=myProfile->reflowTarget*.95){
                //only increment time while in the reflow temp range
                myProfile->msElapsed+=msElapsed;   
            }
            sprintf(temp_string, "Reflowing\n\r");
            writeStringToHost(temp_string);
            ret=myProfile->reflowTarget;
            if(myProfile->msElapsed>=myProfile->reflowTime){
                ret=0;
                myProfile->state=OFF;
            }
            break;
           
                
            
        
    }
    myProfile->lastTemp = currentTemp;
    return ret;
    
}

void endProfile(tempProfile* myProfile){
    myProfile->state=OFF;
    myProfile->msElapsed=0;
}









/* [] END OF FILE */
