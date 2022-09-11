#include "../Common.hpp"


// Cheatsheet: content of the eventInformations arrays
// ---------------------------------------------------
// Menu ID
// String ID
// Code
// Flags
// Number_of_parameters
// Parameter_type [Number_of_parameters]
// Parameter_TitleString [Number_of_parameters]

short conditionsInfos[] = {
    IDMN_CONDITION, M_CONDITION, CND_CONDITION, EVFLAGS_ALWAYS, 3, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION, M_CND_P1, M_CND_P2, M_CND_P3,
};



long FusionAPI Condition(RUNDATA* rdPtr, long param1, long param2) {
//  **** Still use this method for 1 or 2 parameters ****	
//	if (param1==param2)	
//		return TRUE;

    long p1 = CNC_GetParameter(rdPtr);
    long p2 = CNC_GetParameter(rdPtr);
    long p3 = CNC_GetParameter(rdPtr);

    if ((p1 + p2)==p3)
        return TRUE;
         
    return FALSE;
}



long (FusionAPI * ConditionJumps[])(RUNDATA* rdPtr, long param1, long param2) = { 
    Condition,
    0
};