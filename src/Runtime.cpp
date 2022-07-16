// This file contains functions that are used during runtime
// eg: Object creation, destruction, drawing object etc.

#include "Common.hpp"



// Returns size of RUNDATA
unsigned short FusionAPI GetRunObjectDataSize(RunHeader* rhPtr, EDITDATA* edPtr) {
    #pragma MFXExport

    return sizeof(RUNDATA);
}


// Called for each object when its created, each object has its own RUNDATA and EDITDATA
// Copy everything you need from EDITDATA to RUNDATA because you cannot access it later
short FusionAPI CreateRunObject(RUNDATA* rdPtr, EDITDATA* edPtr, createObjectInfo* cobPtr) {
    #pragma MFXExport
    
    // OK
    return 0;
}

// Called for each object when its destroyed, free any memory you allocated in RUNDATA.
short FusionAPI DestroyRunObject(RUNDATA* rdPtr, long fast) {
    #pragma MFXExport
    
    // OK
    return 0;
}



// Called every loop for each object
// If you dont do anything in here return 
short FusionAPI HandleRunObject(RUNDATA* rdPtr) {
    #pragma MFXExport

    // If your extension will draw something to screen you should
    // check if anything about its display has changed
    // if(rdPtr->rc.rcChanged) {
    //     return REFLAG_DISPLAY;
    // } else {
    //     return 0;
    // }

    // You will need to change this flag whenever you want to redraw your object
    // rdPtr->rc.rcChanged = 1;

    // If your extension wont draw anything but still needs to do something each loop use:
    // return 0;

    // If you dont use:
    // return REFLAG_ONESHOT;

    // If you return REFLAG_ONESHOT you still can handle your object, call this:
    // callRun-timeFunction(rdPtr, RFUNCTION_REHANDLE, 0, 0);
    
    // Will not be called next loop
    return REFLAG_ONESHOT;
}

// Called when you return REFLAG_DISPLAY in HandleRunObject
// Draw to screen surface that you can get using WinGetSurface()
short FusionAPI DisplayRunObject(RUNDATA* rdPtr) {
    #pragma MFXExport

    // Example:
    // Fill the screen with nice blue color
    // NOTE: Many cSurface functions are unimplemented in Direct3D mode, expect nothing to be drawn on the screen all the time.
    // cSurface* s = WinGetSurface((int)rdPtr->rHo.hoAdRunHeader->rhIdEditWin);
    // s->Fill(0,100,255);

    // OK
    return 0;
}

// If you want your extension to support Shaders (Effects) and transistions
// comment out DisplayRunObject and implement this function instead.
// NOTE: You can have shaders and transitions with DisplayRunObject but this function will implement this for you.
/*
cSurface* FusionAPI GetRunObjectSurface(RUNDATA* rdPtr) {
    #pragma MFXExport
    
    return NULL;
}
*/



// Impement this function if you support fine collision mode (OEPREFS_FINECOLLISIONS)
// or if its a background object with obstacle properties.
// Return NULL if object is not transparent.
/*
LPSMASK FusionAPI GetRunObjectCollisionMask(RUNDATA* rdPtr, LPARAM lParam) {
    #pragma MFXExport

    // Typical example for active objects
    // ----------------------------------
    // Opaque? collide with box
    if ( (rdPtr->rs.rsEffect & EFFECTFLAG_TRANSPARENT) == 0 )	// Note: only if your object has the OEPREFS_INKEFFECTS option
        return NULL;

    // Transparent? Create mask
    LPSMASK pMask = rdPtr->m_pColMask;
    if ( pMask == NULL )
    {
        if ( rdPtr->m_pSurface != NULL )
        {
            DWORD dwMaskSize = rdPtr->m_pSurface->CreateMask(NULL, lParam);
            if ( dwMaskSize != 0 )
            {
                pMask = (LPSMASK)calloc(dwMaskSize, 1);
                if ( pMask != NULL )
                {
                    rdPtr->m_pSurface->CreateMask(pMask, lParam);
                    rdPtr->m_pColMask = pMask;
                }
            }
        }
    }

    // Note: for active objects, lParam is always the same.
    // For background objects (OEFLAG_BACKGROUND), lParam maybe be different if the user uses your object
    // as obstacle and as platform. In this case, you should store 2 collision masks
    // in your data: one if lParam is 0 and another one if lParam is different from 0.

    return pMask;
}
*/



// Called when application is paused.
short FusionAPI PauseRunObject(RUNDATA* rdPtr) {
    #pragma MFXExport

    return 0;
}

// Called when application is unpaused.
short FusionAPI ContinueRunObject(RUNDATA* rdPtr) {
    #pragma MFXExport

    return 0;
}




// Called when application shoud be saved to disc.
// Eg: When using save action.
// hf is file handle where you should save data using WinAPI functions.
BOOL FusionAPI SaveRunObject(RUNDATA* rdPtr, HANDLE hf) {
    #pragma MFXExport

    BOOL bOK = FALSE;

    // Save the object's data here

    // OK
    bOK = TRUE;
    return bOK;
}

// Called when application shoud be loaded from disc.
// Eg: When using load action.
// hf is file handle where you should load data using WinAPI functions.
BOOL FusionAPI LoadRunObject(RUNDATA* rdPtr, HANDLE hf) {
    #pragma MFXExport

    BOOL bOK=FALSE;

    // Load the object's data here

    // OK
    bOK = TRUE;
    return bOK;
}



// Called when the application starts or restarts.
// Useful for storing global data
void FusionAPI StartApp(mv* mV, CRunApp* pApp) {
    #pragma MFXExport

    // Example
    // -------
    // Delete global data (if restarts application)
    // CMyData* pData = (CMyData*)mV->mvGetExtUserData(pApp, hInstLib);
    // if(pData != NULL) {
    //     delete pData;
    //     mV->mvSetExtUserData(pApp, hInstLib, NULL);
    // }
}

// Called when the application ends.
void FusionAPI EndApp(mv* mV, CRunApp* pApp) {
    #pragma MFXExport

    // Example
    // -------
    // Delete global data
    // CMyData* pData = (CMyData*)mV->mvGetExtUserData(pApp, hInstLib);
    // if(pData != NULL) {
    //     delete pData;
    //     mV->mvSetExtUserData(pApp, hInstLib, NULL);
    // }
}


// Called when the frame starts or restarts.
void FusionAPI StartFrame(mv* mV, DWORD dwReserved, int nFrameIndex) {
    #pragma MFXExport
}

// Called when the frame ends.
void FusionAPI EndFrame(mv* mV, DWORD dwReserved, int nFrameIndex) {
    #pragma MFXExport
}



/* TEXT STUFF

// Return the font used by the object.
void FusionAPI GetRunObjectFont(RUNDATA* rdPtr, LOGFONT* pLf) {
    #pragma MFXExport

    // Example
    // -------
    // GetObject(rdPtr->m_hFont, sizeof(LOGFONT), pLf);
}

// Change the font used by the object.
void FusionAPI SetRunObjectFont(RUNDATA* rdPtr, LOGFONT* pLf, RECT* pRc) {
    #pragma MFXExport

    // Example
    // -------
    // HFONT hFont = CreateFontIndirect(pLf);
    // if ( hFont != NULL ) {
    //     if (rdPtr->m_hFont!=0) {
    //          DeleteObject(rdPtr->m_hFont);
    //     }
    //     rdPtr->m_hFont = hFont;
    //     SendMessage(rdPtr->m_hWnd, WM_SETFONT, (WPARAM)rdPtr->m_hFont, FALSE);
    // }

}

// Return the text color of the object.
COLORREF FusionAPI GetRunObjectTextColor(RUNDATA* rdPtr) {
    #pragma MFXExport

    return 0;   // rdPtr->m_dwColor;
}

// Change the text color of the object.
void FusionAPI SetRunObjectTextColor(RUNDATA* rdPtr, COLORREF rgb) {
    #pragma MFXExport

    // Example
    // -------
    rdPtr->m_dwColor = rgb;
    InvalidateRect(rdPtr->m_hWnd, NULL, TRUE);
}

*/



// INTERCEPTION OF WINDOW MESSAGES
// Get the pointer to the object's data from its window handle
// Note: the object's window must have been subclassed with a
// callRunTimeFunction(rdPtr, RFUNCTION_SUBCLASSWINDOW, 0, 0);
// See the documentation and the Simple Control example for more info.

/*
RUNDATA* GetRdPtr(HWND hwnd, LPRH rhPtr) {
    return (RUNDATA*)GetProp(hwnd, (LPCSTR)rhPtr->rh4.rh4AtomRd);
}

// Called from the window proc of hMainWin and hEditWin.
// You can intercept the messages and/or tell the main proc to ignore them.
LRESULT CALLBACK WindowProc(LPRH rhPtr, HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam) {
    #pragma MFXExport

    RUNDATA* rdPtr = NULL;

    switch (nMsg) {

    // Example
    case WM_CTLCOLORSTATIC:
        {
            // Get the handle of the control
            HWND hWndControl = (HWND)lParam;

            // Get a pointer to the RUNDATA structure (see GetRdptr function above for more info)
            rdPtr = GetRdPtr(hWndControl, rhPtr);

            // Check if the rdPtr pointer is valid and points to an object created with this extension
            if ( rdPtr == NULL || rdPtr->rHo.hoIdentifier != IDENTIFIER )
                break;

            // OK, intercept the message
            HDC hDC = (HDC)wParam;
            SetBkColor(hDC, rdPtr->backColor);
            SetTextColor(hDC, rdPtr->fontColor);
            rhPtr->rh4.rh4KpxReturn = (long)rdPtr->hBackBrush;
            return REFLAG_MSGRETURNVALUE;
        }
        break;
    }

    return 0;
}

*/
