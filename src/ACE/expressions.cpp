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

short expressionsInfos[] = {
    IDMN_EXPRESSION, M_EXPRESSION, EXP_EXPRESSION, 0, 3, EXPPARAM_LONG, EXPPARAM_LONG, EXPPARAM_LONG, 0, 0, 0,

    //Note in the following.  If you are returning a string, you set the EXPFLAG_STRING.	
    IDMN_EXPRESSION2, M_EXPRESSION2, EXP_EXPRESSION2, EXPFLAG_STRING, 1, EXPPARAM_STRING, 0,

    //Note in the following.  If you are returning a float, you set the EXPFLAG_DOUBLE
    IDMN_EXPRESSION3, M_EXPRESSION3, EXP_EXPRESSION3, EXPFLAG_DOUBLE, 1, EXPPARAM_LONG, 0,
};



long FusionAPI Expression(RUNDATA* rdPtr,long param1) {
    long p1 = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
    long p2 = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
    long p3 = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);

    // Performs the wonderfull calculation
    return p1+p2+p3;
}


//Reverse the string passed in.
long FusionAPI Expression2(RUNDATA* rdPtr,long param1) {
    char *temp;

    long p1 = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_STRING);

    //I'm storing the string pointer returned into a char *
    temp = (LPSTR)p1;

    //Reversing the string.
    _strrev(temp);
    
    //Setting the HOF_STRING flag lets MMF know that you are a string.
    rdPtr->rHo.hoFlags |= HOF_STRING;
    
    //This returns a pointer to the string for MMF.
    return (long)temp;
}


//Divide the float by 2.
long FusionAPI Expression3(RUNDATA* rdPtr,long param1) {
    long p1 = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_FLOAT);

    //Floats are tricky.  If you want to pass in a float, you must do the
    //following to convert the long to a true float, but only when you use
    //TYPE_FLOAT.
    float fp1 = *(float *)&p1;

    //Just doing simple math now.
    fp1 /=2;

    //Setting the HOF_FLOAT flag lets MMF know that you are returning a float.
    rdPtr->rHo.hoFlags |= HOF_FLOAT;

    //Return the float without conversion
    return *((int*)&fp1);
}



long (FusionAPI * ExpressionJumps[])(RUNDATA* rdPtr, long param) = {     
    Expression,
    Expression2,
    Expression3,
    0
};