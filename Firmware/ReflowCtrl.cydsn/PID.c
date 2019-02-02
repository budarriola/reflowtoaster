/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * https://tutorial.cytron.io/2012/06/22/pid-for-embedded-design/
 * ========================================
*/
#include "PID.h"



float runPid(pidCtrl* pid, float input, float target){
    float output;
    float derivative;
    float error;
    
    error = target - input;
    pid->runningIntigral += error;
    derivative = error - pid->lastError;
    output = (pid->p * error) + (pid->i * pid->runningIntigral) + (pid->d * derivative);
    pid->lastError=error;
    
    return output;
    
}



/* [] END OF FILE */
