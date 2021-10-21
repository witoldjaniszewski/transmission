#include "transmission.h"

#define REDLINE 4500
#define STALL 600

shift_t getShift(int RPM, double slope, int* status)
{
	double effective_RPM = (double)RPM * (1-slope);
	
	// Non-sensical slope
	if(slope > 1 || slope < 0)
	{
		*status = WARNING;	// Bad but non-critical failure
		return ERROR;
	}
	
	// Non-sensical RPM
	if(RPM < 0)
	{
		*status = FAILURE;	// Critical state
		return ERROR;
	}
	
	// Prevent Redlining
	if(RPM > REDLINE){
		return UP;
	}
	
	// Prevent Stall
	if(RPM < 600)
	{
		return DOWN;
	}	
	
	// Regulate RPM
	if(effective_RPM > 2500){
		return UP;
	}
	
	if(effective_RPM < 1000){
		return DOWN;
	}
	
	// No need to regulate RPM
	else{
		return NONE;
	}
}


