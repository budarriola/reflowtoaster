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

/* [] END OF FILE */
#ifndef PID_H
#define PID_H
    
    #include <stdio.h>
    #include "project.h"
    #include "main.h"
    
    typedef struct pidctrl{
        float runningIntigral,lastError;
        float p,i,d;
    }pidCtrl;
    
    float runPid(pidCtrl* pid, float input, float target);
    
#endif