// Functions in this file are used internaly by Fusion, you probably dont need to change them.
#include	"common.h"

HINSTANCE hInstLib;



// DLL entry point
BOOL WINAPI DllMain(HINSTANCE hDLL, DWORD dwReason, LPVOID lpReserved) {
    switch (dwReason) {
    case DLL_PROCESS_ATTACH:
        hInstLib = hDLL; 	// Store HINSTANCE, it will be needed when loading resources from rc file.
        break;
    
    default:
        break;
    }
    
    return TRUE;
}



// Called when extension is loaded into memory
extern "C" int WINAPI DLLExport Initialize(mv* mV, int quiet) {
    return 0;
}

// Called just before extension is unloaded
extern "C" int WINAPI DLLExport Free(mv* mV) {
    return 0;
}



// This function tells Fusion some basic information about your extension
extern "C" DWORD WINAPI DLLExport GetInfos(int info) {
    switch (info)
    {
    case KGI_VERSION:
        return EXT_VERSION2;			// Do not change
    
    case KGI_PLUGIN:
        return EXT_PLUGIN_VERSION1;		// Do not change
    
    case KGI_PRODUCT:
        #ifdef PROEXT
        return PRODUCT_VERSION_DEV;			// Fusion Developer 
        #else
        return PRODUCT_VERSION_STANDARD;	// Fusion Standard and above
        #endif

    case KGI_BUILD:
        return MINBUILD;                // Required Fusion build
    
    case KGI_UNICODE:
        #ifdef UNICODE
        return TRUE;
        #else
        return FALSE;
        #endif

    default:
        return 0;
    }
}

// Tells Fusion everything about your extension
// Actions Condition Expressions etc
short WINAPI DLLExport GetRunObjectInfos(mv _far *mV, fpKpxRunInfos infoPtr)
{
    infoPtr->conditions = (LPBYTE)ConditionJumps;
    infoPtr->actions = (LPBYTE)ActionJumps;
    infoPtr->expressions = (LPBYTE)ExpressionJumps;

    infoPtr->numOfConditions = CND_LAST;
    infoPtr->numOfActions = ACT_LAST;
    infoPtr->numOfExpressions = EXP_LAST;

    infoPtr->editDataSize = MAX_EDITSIZE;
    infoPtr->editFlags= OEFLAGS;

    infoPtr->windowProcPriority = WINDOWPROC_PRIORITY;

    // See doc
    infoPtr->editPrefs = OEPREFS;

    // Identifier, for run-time identification
    infoPtr->identifier = IDENTIFIER;
    
    // Current version
    infoPtr->version = KCX_CURRENT_VERSION;
    
    return TRUE;
}



// List of external modules
LPCTSTR szDep[] = {
    // _T("MyDll.dll"),
    NULL
};

// This function returns names of external modules(eg: DLLs) that should be included with built applications
LPCTSTR* WINAPI DLLExport GetDependencies() {
    return szDep;	// szDep;
}



// Called for each object when its read from MFA or EXE file
int	WINAPI DLLExport LoadObject(mv* mV, LPCSTR fileName, EDITDATA* edPtr, int reserved) {
    return 0;
}

// Counter part of above function
// Called before object is deleted from frame
void WINAPI DLLExport UnloadObject(mv* mV, EDITDATA* edPtr, int reserved) {
}



// Called when objects editdata must be updated to neewer version
// OldEdPtr is old editdata, extension header is allways first use it to get old editdata version
// Called both in editor and at runtime
HGLOBAL WINAPI DLLExport UpdateEditStructure(mv __far *mV, void __far * OldEdPtr) {
    // We do nothing here
    return 0;
}

// If you store file names in editdata they have to be updated when application is moved to different directory
// Call lpfnUpdate() to update them
// Called both in editor and at runtime
void WINAPI DLLExport UpdateFileNames(mv _far *mV, LPTSTR appName, EDITDATA* edPtr, void (WINAPI * lpfnUpdate)(LPTSTR, LPTSTR))
{
}



// Uncomment this function if you need to store an image in editdata
// Note: do not forget to enable the function in the .def file 
// if you remove the comments below.
/*
int WINAPI DLLExport EnumElts (mv __far *mV, EDITDATA* edPtr, ENUMELTPROC enumProc, ENUMELTPROC undoProc, LPARAM lp1, LPARAM lp2)
{  
    int error = 0;

    // Replace wImgIdx with the name of the WORD variable you create within the edit structure
  
    // Enum images  
    if ( (error = enumProc(&edPtr->wImgIdx, IMG_TAB, lp1, lp2)) != 0 )
    {
        // Undo enum images      
        undoProc (&edPtr->wImgIdx, IMG_TAB, lp1, lp2);    
    }  

    return error;
}
*/
