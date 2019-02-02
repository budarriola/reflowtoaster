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

#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include "project.h"
    
    
    #define ADCMux_THERM_1   0
    #define ADCMux_THERM_2   1
    #define ADCMux_VREFF     2
    #define ADCMux_GND       3
    
    /* Number of sensors that require filtering. In this project, its 2 (thermocouple and IC) */
    #define NUM_TC						2
    #define TC1 0
    #define TC2 1
    
    /* Voltage threshold (in uV) based on which broken thermocouple alert is made*/
    #define BROKEN_TC_THRESHOLD				-10000
    
    
    CY_ISR_PROTO(EOCIsrHandler);
    CY_ISR_PROTO(IsrHandler_500ms);
    CY_ISR_PROTO(IsrHandler_reset);
    
    
#endif
/* [] END OF FILE */
