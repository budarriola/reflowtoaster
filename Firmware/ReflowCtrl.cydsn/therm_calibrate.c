/******************************************************************************
* File Name: initialize.c
*  Version 1.0
*
* Description:
*  This file contains the code that calibrates the thermocouple
*
* Note:
*
********************************************************************************
* Copyright (2018), Cypress Semiconductor Corporation. All Rights Reserved.
********************************************************************************
* This software is owned by Cypress Semiconductor Corporation (Cypress)
* and is protected by and subject to worldwide patent protection (United
* States and foreign), United States copyright laws and international treaty
* provisions. Cypress hereby grants to licensee a personal, non-exclusive,
* non-transferable license to copy, use, modify, create derivative works of,
* and compile the Cypress Source Code and derivative works for the sole
* purpose of creating custom software in support of licensee product to be
* used only in conjunction with a Cypress integrated circuit as specified in
* the applicable agreement. Any reproduction, modification, translation,
* compilation, or representation of this software except as specified above 
* is prohibited without the express written permission of Cypress.
*
* Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH 
* REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes without further notice to the 
* materials described herein. Cypress does not assume any liability arising out 
* of the application or use of any product or circuit described herein. Cypress 
* does not authorize its products for use as critical components in life-support 
* systems where a malfunction or failure may reasonably be expected to result in 
* significant injury to the user. The inclusion of Cypress' product in a life-
* support systems application implies that the manufacturer assumes all risk of 
* such use and in doing so indemnifies Cypress against all charges. 
*
* Use of this Software may be limited by and subject to the applicable Cypress
* software license agreement. 
*******************************************************************************/




#include "therm_calibrate.h"
#include "usbUart.h"
#include "removeOffsetNoise.h"
#include "usbUart.h"



/* Calibration input in microvolts */
#warning "set this to the calculated value of 1.25v"
#define REFFRENCE_UV						1250000



int32 OcorTC1;
float GcorTC1;
int32 OcorTC2;
float GcorTC2;



    


int32 getOcor(uint8 tcNumber){
    if (tcNumber == TC2){
        return OcorTC2;
    }else{
     return OcorTC1;
    }
}

float getGcor(uint8 tcNumber){
   
    if (tcNumber == TC2){
        return GcorTC2;
    }else{
     return GcorTC1;
    }
}


void Calibrate(uint8 tcNumber)
{
    
    
	/* Counter variable for 'for loop' */ 
	uint8 count;
	
	/* Variables that store ADC offset, signal chain offset and ADC reading for calibration voltage */
	int32 offsetADC, offsetSC, fullscale;
	

	
	/* Gain correction factor */
	float gcor = 1.0;
	

	

	
	/* Measure signal chain offset */
	ADCMux_Select(ADCMux_GND);
	ADC_SelectConfiguration(ADC_TC_Config,1);
    
	offsetSC = 0;
	for(count = 0; count < 16; count++)
	{
		ADC_StartConvert();
		ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
		ADC_StopConvert();
		offsetSC += ADC_GetResult32();
	}
	offsetSC >>= 4;
	
    /*Measure ADC Offset*/
	offsetADC = 0;
	for(count = 0; count < 16; count++)
	{
		
		offsetADC += MeasureOffset();
	}
	offsetADC >>= 4;

	
	/* Measure Calibration voltage */
	ADCMux_Select(ADCMux_VREFF);
	fullscale = 0;
	for (count = 0; count < 16; count++)
	{
		ADC_StartConvert();
	   	ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
	   	ADC_StopConvert();
		fullscale += ADC_GetResult32();
	}
	fullscale >>= 4; //devide by 16 (avrage of 16 samples)
    
    /*Subtract off ADC offset measured earlier*/
	fullscale -= offsetSC;
	
	/* Find the gain correction factor */
	gcor = (float)REFFRENCE_UV / ADC_CountsTo_uVolts(fullscale);
	
	/* Display the computed offset and gain correction factors */			
	
    if (tcNumber == TC2){
        GcorTC2 = gcor;
    }else{
        GcorTC1 = gcor;
    }

    #ifdef DEBUG
        sprintf(temp_string, "TC%d Gain correction factor : %6.5f\n\r", tcNumber+1, gcor);
        writeStringToHost(temp_string);
    #endif
	
	if (tcNumber == TC2){
        OcorTC2 = offsetSC;
    }else{
        OcorTC1 = offsetSC;
    }
    #ifdef DEBUG
        sprintf(temp_string, "TC%d Computed Offset : %ld \n\r", tcNumber+1, offsetSC);
        writeStringToHost(temp_string);
    #endif


	
    



}

/* [] END OF FILE */
