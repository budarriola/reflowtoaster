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
#ifndef PROFILE_H
#define PROFILE_H
    
    #include <stdio.h>
    #include "project.h"
    #include "main.h"
    #include "PID.h"
    
    typedef enum profilestate {OFF,PREHEAT,SOAK,REFLOW}profileState;
    
    typedef struct tempprofile{
        float preheatDegreesPerS;
        float soakStart;
        float soakTarget;
        unsigned int soakTime;
        
        float reflowTarget;
        unsigned int reflowTime;
        unsigned int msElapsed;
        float lastTemp;
        profileState state;
        //number of steps to take in ramping soak temp.
        unsigned int soakSteps;
    }tempProfile;
    
    extern const tempProfile profile_snPb;
    extern const tempProfile profile_lf;
    
    //returns target temp
    float runProfile(tempProfile* myProfile, float currentTemp, unsigned int msElapsed);
    
    void endProfile(tempProfile* myProfile);
    void setupProfiles();
#endif
/* [] END OF FILE */
