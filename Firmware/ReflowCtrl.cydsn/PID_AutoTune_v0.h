#ifndef PID_AutoTune_v0
#define PID_AutoTune_v0
#define LIBRARY_VERSION	0.0.1
#include "project.h"
#include "math.h"



  //commonly used functions **************************************************************************
    
    //input is the temp we are sending to the pid
    //output is the result from the pid to be sent to the heater
    void PID_ATune(float* Input, float* Output);                       	// * Constructor.  links the Autotune to a given PID
    
    
    int PID_ATune_Runtime();						   			   	// * Similar to the PID Compue function, returns non 0 when done
    
    void PID_ATune_SetRuntimeIntrival(unsigned int ms);
    
	void PID_ATune_Cancel();									   	// * Stops the AutoTune	
	
	void PID_ATune_SetControlType(int); 						   	// * Determies if the tuning parameters returned will be PI (D=0)
	int PID_ATune_GetControlType();							   	//   or PID.  (0=PI, 1=PID)			
	
    void PID_ATune_SetOutputStep(float);						   	// * how far above and below the starting value will the output step?	
	float PID_ATune_GetOutputStep();							   	// 
    
	void PID_ATune_SetLookbackSec(int);							// * how far back are we looking to identify peaks
	int PID_ATune_GetLookbackSec();								//
	
	void PID_ATune_SetNoiseBand(float);							// * the autotune will ignore signal chatter smaller than this value
	float PID_ATune_GetNoiseBand();								//   this should be acurately set
	
	float PID_ATune_GetKp();										// * once autotune is complete, these functions contain the
	float PID_ATune_GetKi();										//   computed tuning parameters.  
	float PID_ATune_GetKd();										//
	

    void PID_ATune_FinishUp();
    
	

#endif

