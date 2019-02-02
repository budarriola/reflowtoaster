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


#ifndef MESURETEMP_H
#define MESURETEMP_H
    
    #include <stdio.h>
    #include "project.h"
    #include "main.h"
    
    enum mesurmentState {TC_IDLE, TC_STARTED,TC_OFFSET };
    
    enum mesurmentState getTCState();
    
    //errorreturns 1 on failure
    float mesureTC_Blocking(uint8 tcNumber, uint8* error);
    


    
    //returns 1 on failure
    uint8 startMesureTC_nonBlocking(uint8 tcNumber);
    
    void continueMesureTCResult();
        //returns a temp
    //returns the thermocouple number that was mesured, or -1 if the mesurement failed
    float getTcTemp(uint8 *tcNumber );

#endif
/* [] END OF FILE */
