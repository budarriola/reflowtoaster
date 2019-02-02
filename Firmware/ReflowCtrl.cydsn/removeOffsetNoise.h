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
#ifndef REMOVEOFFSETNOISE_H
#define REMOVEOFFSETNOISE_H
    
#include <stdio.h>
#include "project.h"
#include "main.h"
    
/* Function prototype for IIR filter */
int32 FilterSignal(int32 ADCSample, uint8 tcNumber);

/* Function prototype to measure offset voltage */
int32 MeasureOffset(void);

#endif
/* [] END OF FILE */
