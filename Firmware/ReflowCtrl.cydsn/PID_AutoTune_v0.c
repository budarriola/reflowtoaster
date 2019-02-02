
#include "PID_AutoTune_v0.h"



uint8_t isMax, isMin;
	float *input, *output;
	float setpoint;
	float noiseBand;
	int controlType;
	uint8_t running;
	unsigned long peak1, peak2, lastTime,sampleTime,now;
    float oStep;
	int nLookBack;
	int peakType;
	float lastInputs[101];
    float peaks[10];
	int peakCount;
	uint8_t justchanged;
	uint8_t justevaled;
	float absMax, absMin;
	float outputStart;
	float Ku, Pu;
    
    unsigned int runtimeIntrivalms = 0;
    
    void PID_ATune_SetRuntimeIntrival(unsigned int ms){
        runtimeIntrivalms = ms;
    }
    
    
void PID_ATune(float* Input, float* Output)
{
    #warning "change start perams"
	input = Input;
	output = Output;
	controlType =1 ; //default to PI
	noiseBand = 0.5;
	running = 0;
    oStep = 30;
	PID_ATune_SetLookbackSec(10);
	lastTime = 0;
    now=0;
	
}



void PID_ATune_Cancel()
{
	running = 0;
} 
 
int PID_ATune_Runtime()
{
	justevaled=0;
	if(peakCount>9 && running)
	{
		running = 0;
		PID_ATune_FinishUp();
		return 1;
	}
	now += runtimeIntrivalms;
	
	if((now-lastTime)<sampleTime) return 0;
	lastTime = now;
	float refVal = *input;
	justevaled=1;
	if(!running)
	{ //initialize working variables the first time around
		peakType = 0;
		peakCount=0;
		justchanged=0;
		absMax=refVal;
		absMin=refVal;
        #warning "the setpoint for autotuneing is here"
		setpoint = 100;
		running = 1;
		outputStart = *output;
		*output = outputStart+oStep;
	}
	else
	{
		if(refVal>absMax)absMax=refVal;
		if(refVal<absMin)absMin=refVal;
	}
	
	//oscillate the output base on the input's relation to the setpoint
	
	if(refVal>setpoint+noiseBand){
        *output = outputStart-oStep;
    }
	else if (refVal<setpoint-noiseBand){
        *output = outputStart+oStep;
    }
	
	
  //uint_8 isMax=1, isMin=1;
  isMax=1;isMin=1;
  //id peaks
  for(int i=nLookBack-1;i>=0;i--)
  {
    float val = lastInputs[i];
    if(isMax) isMax = refVal>val;
    if(isMin) isMin = refVal<val;
    lastInputs[i+1] = lastInputs[i];
  }
  lastInputs[0] = refVal;  
  if(nLookBack<9)
  {  //we don't want to trust the maxes or mins until the inputs array has been filled
	return 0;
	}
  
  if(isMax)
  {
    if(peakType==0)peakType=1;
    if(peakType==-1)
    {
      peakType = 1;
      justchanged=1;
      peak2 = peak1;
    }
    peak1 = now;
    peaks[peakCount] = refVal;
   
  }
  else if(isMin)
  {
    if(peakType==0)peakType=-1;
    if(peakType==1)
    {
      peakType=-1;
      peakCount++;
      justchanged=1;
    }
    
    if(peakCount<10)peaks[peakCount] = refVal;
  }
  
  if(justchanged && peakCount>2)
  { //we've transitioned.  check if we can autotune based on the last peaks
    float avgSeparation = (fabs(peaks[peakCount-1]-peaks[peakCount-2])+fabs(peaks[peakCount-2]-peaks[peakCount-3]))/2;
    if( avgSeparation < 0.05*(absMax-absMin))
    {
		PID_ATune_FinishUp();
      running = 0;
	  return 1;
	 
    }
  }
   justchanged=0;
	return 0;
}
void PID_ATune_FinishUp()
{
	  *output = outputStart;
      //we can generate tuning parameters!
      Ku = 4*(2*oStep)/((absMax-absMin)*3.14159);
      Pu = (float)(peak1-peak2) / 1000;
}

float PID_ATune_GetKp()
{
	return 0.6 * Ku;
}

float PID_ATune_GetKi()
{
	return 1.2*Ku / Pu;  // Ki = Kc/Ti
}

float PID_ATune_GetKd()
{
	return 0.075 * Ku * Pu;  //Kd = Kc * Td
}

void PID_ATune_SetNoiseBand(float Band)
{
	noiseBand = Band;
}

float PID_ATune_GetNoiseBand()
{
	return noiseBand;
}

void PID_ATune_SetLookbackSec(int value)
{
    if (value<1) value = 1;
	
	if(value<25)
	{
		nLookBack = value * 4;
		sampleTime = 250;
	}
	else
	{
		nLookBack = 100;
		sampleTime = value*10;
	}
}

int PID_ATune_GetLookbackSec()
{
	return nLookBack * sampleTime / 1000;
}


void PID_ATune_SetOutputStep(float Step)
{
	oStep = Step;
}

float PID_ATune_GetOutputStep()
{
	return oStep;
}