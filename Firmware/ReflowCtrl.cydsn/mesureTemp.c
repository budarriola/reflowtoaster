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


#include "main.h"
#include "mesureTemp.h"
#include "therm_calibrate.h"
#include "removeOffsetNoise.h"
#include "usbUart.h"

/* Calibration Flag */
uint8 calibFlag=0;

//this value is -1 when idle
int8 tcMesurementInProgress = -1;
/* TC hot junction ADC count measurement */
    int32 hotJnCount;
/* VSSA reference voltage */
    int32 offset;

enum mesurmentState state = TC_IDLE;

enum mesurmentState getTCState(){
    return state;
}





//returns 1 on failure
uint8 startMesureTC_nonBlocking(uint8 tcNumber)
{
    if (state == TC_IDLE){
        if (!calibFlag){
            return 1;
        }
            
        /* Read thermocouple hot junction voltage */
        if (tcNumber==TC2)    {
            ADCMux_Select(ADCMux_THERM_2);
        }else{
            ADCMux_Select(ADCMux_THERM_1);
        }
        ADC_SelectConfiguration(ADC_TC_Config,1);
        state = TC_STARTED;
        isr_eoc_ClearPending();
        isr_eoc_StartEx(EOCIsrHandler);
        ADC_StartConvert();
        tcMesurementInProgress = tcNumber;
        return 0;
    }
    return 1;
}

//returns a temp
void continueMesureTCResult(){
    
    if(tcMesurementInProgress >=0)
    {
        hotJnCount = ADC_GetResult32();

        //start mesureing the offset voltage
    	
	    ADCMux_Select(ADCMux_GND);
        state = TC_OFFSET;
        isr_eoc_StartEx(EOCIsrHandler);
	    ADC_StartConvert();
    }
        
}


float getTcTemp(uint8 *tcNumber ){
    
    /* Thermocouple volt calculated from ADC hot Jn count */
    int32 tcHotJnuVolt;
    
    /* TC hot junction temperature */
    float tcTemp;
    *tcNumber = tcMesurementInProgress;
    if(tcMesurementInProgress >=0)
    {
        state = TC_IDLE;
        
    	/* Read ground reference voltage */
        offset = ADC_GetResult32();

    	
    	/* Correlated double sampling to remove ADC offset */
        hotJnCount -= offset;
    	
        //get themocouple temp in uv
        tcHotJnuVolt = (int32)((float)(ADC_CountsTo_uVolts(hotJnCount) - getOcor(tcMesurementInProgress)) * getGcor(tcMesurementInProgress));


    	/* Convert thermo-emf to temperature */
        tcTemp =(((float)tcHotJnuVolt-(float)1250000)/(float)5000.0);//amp returns 5mv a degree c

        
    	/* If thermocouple is broken, display broken alert, else display thermocouple temperature */
    	if (tcHotJnuVolt < BROKEN_TC_THRESHOLD)
    	{
            #ifdef DEBUG
                writeStringToHost("TC. Broken\n\r");
            #endif
    	}
        else
    	{
    		
            #ifdef DEBUG2
                sprintf(temp_string, "TC Temp : %5.2fC\n\r", tcTemp);
                writeStringToHost(temp_string);
            #endif
    	}
        tcMesurementInProgress = -1;
        return tcTemp;
    }
    
    return 0;

}




//if errror == 1 there was an error
float mesureTC_Blocking(uint8 tcNumber, uint8* error)
{
    /* TC hot junction temperature */
    float tcTemp;
    
    /* TC hot junction ADC count measurement */
    int32 hotJnCount;

    /* Filtered hot junction count */
    int32 filHotJnCount;

    /* VSSA reference voltage */
    int32 offset;

    /* Thermocouple volt calculated from ADC hot Jn count */
    int32 tcHotJnuVolt;
    
    error = 0;
    
    if (state == TC_IDLE){
        if (!calibFlag){
            Calibrate(TC1);
            Calibrate(TC2);
            calibFlag = 1;
        }
        
        /* Read thermocouple hot junction voltage */
        if (tcNumber==TC2)    {
            ADCMux_Select(ADCMux_THERM_2);
        }else{
            ADCMux_Select(ADCMux_THERM_1);
        }
        
    	ADC_SelectConfiguration(ADC_TC_Config,1);
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        ADC_StopConvert();
        hotJnCount = ADC_GetResult32();

    	
    	/* Read ground reference voltage */
        offset = MeasureOffset();

    	
    	/* Correlated double sampling to remove ADC offset */
        hotJnCount -= offset;
    	
    	/* Filter signal */
        filHotJnCount = FilterSignal(hotJnCount,tcNumber);
    	

        //get themocouple temp in uv
        tcHotJnuVolt = (int32)((float)(ADC_CountsTo_uVolts(filHotJnCount) - getOcor(tcNumber)) * getGcor(tcNumber));


    	/* Convert thermo-emf to temperature */
        tcTemp =(((float)tcHotJnuVolt-(float)1250000)/(float)5000.0);//amp returns 5mv a degree c

        
    	/* If thermocouple is broken, display broken alert, else display thermocouple temperature */
    	if (tcHotJnuVolt < BROKEN_TC_THRESHOLD)
    	{
            #ifdef DEBUG
                writeStringToHost("TC. Broken\n\r");
            #endif
    	}
        else
    	{
    		
            #ifdef DEBUG2
                sprintf(temp_string, "TC Temp : %5.2fC\n\r", tcTemp);
                writeStringToHost(temp_string);
            #endif
    	}
        return tcTemp;
    }
    *error = 1;
    return 0;
}
    
    
    
    
    
    

        
    
    
/* [] END OF FILE */
