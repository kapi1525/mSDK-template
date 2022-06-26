#include "../common.h"


// Cheatsheet: content of the eventInformations arrays
// ---------------------------------------------------
// Menu ID
// String ID
// Code
// Flags
// Number_of_parameters
// Parameter_type [Number_of_parameters]
// Parameter_TitleString [Number_of_parameters]

short actionsInfos[] = {
    IDMN_ACTION, M_ACTION,	ACT_ACTION,	0, 0,
};



short WINAPI DLLExport Action(RUNDATA* rdPtr, long param1, long param2) {
    // Actions work just like Conditions

    // Use directly param1 and/or param2 if this action has 1 or 2 parameters

    // Use this if this action has 3 parameters or more
//	long p1 = CNC_GetParameter(rdPtr);
//	long p2 = CNC_GetParameter(rdPtr);
//	long p3 = CNC_GetParameter(rdPtr);
//	etc.

    return 0;
}



short (WINAPI * ActionJumps[])(RUNDATA* rdPtr, long param1, long param2) = {
    Action,
    0
};