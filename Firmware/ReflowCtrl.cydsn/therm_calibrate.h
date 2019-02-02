#ifndef THERM_CALIBRATE_H
#define THERM_CALIBRATE_H
    
    #include <stdio.h>
    #include "project.h"
    #include "main.h"
    

    
    
    
    /* Function prototype for initial offset and gain calibration */
    void Calibrate(uint8 tcNumber);
    int32 getOcor(uint8 tcNumber);
    float getGcor(uint8 tcNumber);
#endif