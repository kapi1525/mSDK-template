#include "Common.hpp"

// Only used at EDITTIME
#ifdef EDITTIME



// Property IDs
enum {
    PROPID_SETTINGS = PROPID_EXTITEM_CUSTOM_FIRST,

    // Example
    // PROPID_TEXTTITLE
    // PROPID_TEXT
    // PROPID_CHECK
    // PROPID_COMBO
    // PROPID_COLOR
};


// Example PROPID_COMBO contents
// LPCSTR ComboList[] = {
//     0,	// reserved
//     MAKEINTRESOURCE(IDS_FIRSTOPTION),	
//     MAKEINTRESOURCE(IDS_SECONDOPTION),	
//     MAKEINTRESOURCE(IDS_THIRDOPTION),	
//     NULL
// };


// Prop definitions:
// Type
// ID
// Text
// Comment
// Options           (optional)
// Initial parameter (optional)
PropData Properties[] = {
    // Example
    // PropData_Group      (PROPID_TEXTTITLE,  IDS_PROP_TEXTTITLE, IDS_PROP_TEXTTITLE),
    // PropData_EditString (PROPID_TEXT,       IDS_PROP_TEXT,      IDS_PROP_TEXT_INFO),
    // PropData_CheckBox   (PROPID_CHECK,      IDS_PROP_CHECK,     IDS_PROP_CHECK_INFO),
    // PropData_ComboBox   (PROPID_COMBO,      IDS_PROP_COMBO,     IDS_PROP_COMBO,	ComboList),
    // PropData_Color      (PROPID_COLOR,      IDS_PROP_COLOR,     IDS_PROP_COLOR_INFO),

    // End of table (required)
    PropData_End()
};



// Called when Fusion wants to display object properties
// Call mvInsertProps to put your custom props into properties
BOOL FusionAPI GetProperties(mv* mV, EDITDATA* edPtr, BOOL bMasterItem) {
    #pragma MFXExport
    mvInsertProps(mV, edPtr, Properties, PROPID_TAB_GENERAL, TRUE);
    return TRUE;
}

// Called when props are removed from properties
// Free anything you might have allocated in GetProperties() here
void FusionAPI ReleaseProperties(mv* mV, EDITDATA* edPtr, BOOL bMasterItem) {
    #pragma MFXExport
}



// Called when prop is initialized if its lCreateParam is NULL (PropData)
// Use to eg: set default values for props if you cant do this in PropData array
LPARAM FusionAPI GetPropCreateParam(mv* mV, EDITDATA* edPtr, unsigned int nPropID) {
    #pragma MFXExport

    return NULL;
}

// Called after prop was initialized
// Free any memory allocated in GetPropCreateParam() here
void FusionAPI ReleasePropCreateParam(mv* mV, EDITDATA* edPtr, unsigned int nPropID, LPARAM lParam) {
    #pragma MFXExport
}



// Returns value of property
void* FusionAPI GetPropValue(mv* mV, EDITDATA* edPtr, unsigned int nPropID) {
    #pragma MFXExport

    // Example
    // switch (nPropID) {
    // case PROPID_COLOR:
    //     return new CPropDWordValue(edPtr->dwColor);
    // case PROPID_TEXT:
    //     return new CPropStringValue(&edPtr->szText[0]);
    // case PROPID_COMBO:
    //     return new CPropDWordValue(edPtr->nComboIndex);
    // }

    return NULL;
}

// Same as GetPropValue() but for checkboxes
BOOL FusionAPI GetPropCheck(mv* mV, EDITDATA* edPtr, unsigned int nPropID) {
    #pragma MFXExport

    return 0;
}



// Called when user modifies property value
// Use to store prop value in EDITDATA
void FusionAPI SetPropValue(mv* mV, EDITDATA* edPtr, unsigned int nPropID, void* lParam) {
    #pragma MFXExport

    // Example
    // switch (nPropID) {
    // case PROPID_COMBO:
    //     edPtr->nComboIndex = ((CPropDWordValue*)lParam)->m_dwValue;
    //     break;
    // 
    // case PROPID_TEXT: {
    //         // Get string
    //         LPTSTR pStr = (LPTSTR)((CPropStringValue*)lParam)->GetString();
    // 
    //         // If your EDITDATA has a fixed size just store it, else you have to reallocate EDITDATA:
    //         if (_tcslen(pStr) != _tcslen(edPtr->text)) {
    //             EDITDATA* pNewPtr = (EDITDATA*)mvReAllocEditData(mV, edPtr, sizeof(EDITDATA) + (_tcslen(pStr) * sizeof(TCHAR)));
    // 
    //             // Check if realloc worked
    //             if(pNewPtr) {
    //                 edPtr=pNewPtr;
    //             }
    //         }
    //         // Copy string
    //         _tcscpy(edPtr->text, pStr);
    //     } break;
    // }

    // Call this if your object has to be redrawn
    // mvInvalidateObject(mV, edPtr);

}

// Same as SetPropValue() but for checkboxes
void FusionAPI SetPropCheck(mv* mV, EDITDATA* edPtr, unsigned int nPropID, BOOL nCheck) {
    #pragma MFXExport
}



// Called when user clicks button in properties
BOOL FusionAPI EditProp(mv* mV, EDITDATA* edPtr, unsigned int nPropID) {
    #pragma MFXExport

    // Example
    // if (nPropID==PROPID_EDITCONTENT) {
    //     // Do something
    //     return TRUE;
    // }

    return FALSE;
}

// This function returns the enabled state of a property.
BOOL FusionAPI IsPropEnabled(mv* mV, EDITDATA* edPtr, unsigned int nPropID) {
    #pragma MFXExport

    // Example
    // switch (nPropID) {
    // case PROPID_CHECK:
    //     return (edPtr->nComboIndex != 0);
    // }

    return TRUE;
}

#endif // EDITTIME



// Text properties
// TODO: Check if all functions are only used at EDITTIME so i can remove them from RUNTIME extensions



// Return the text capabilities of the object under the frame editor.
DWORD FusionAPI GetTextCaps(mv* mV, EDITDATA* edPtr) {
    #pragma MFXExport

    return 0;	// TEXT_ALIGN_LEFT|TEXT_ALIGN_HCENTER|TEXT_ALIGN_RIGHT|TEXT_ALIGN_TOP|TEXT_ALIGN_VCENTER|TEXT_ALIGN_BOTTOM|TEXT_FONT|TEXT_COLOR;
}

#ifdef EDITTIME

// Return the font used by object.
BOOL FusionAPI GetTextFont(mv* mV, EDITDATA* edPtr, LOGFONT* plf, void* obsolete, int obsolete2) {
    #pragma MFXExport
    
    // Example: copy LOGFONT structure from EDITDATA
    // memcpy(plf, &edPtr->m_lf, sizeof(LOGFONT));

    return TRUE;
}

// Called when user changed font
BOOL FusionAPI SetTextFont(mv* mV, EDITDATA* edPtr, LOGFONT* plf, void* obsolete) {
    #pragma MFXExport

    // Example: copy LOGFONT structure to EDITDATA
    // memcpy(&edPtr->m_lf, plf, sizeof(LOGFONT));

    return TRUE;
}

#endif // EDITTIME



// Get the text color of the object.
COLORREF FusionAPI GetTextClr(mv* mV, EDITDATA* edPtr) {
    #pragma MFXExport

    return 0;	// edPtr->fontColor;
}

// Set the text color of the object.
void FusionAPI SetTextClr(mv* mV, EDITDATA* edPtr, COLORREF color) {
    #pragma MFXExport
    
    // Example
    //edPtr->fontColor = color;
}


#ifdef EDITTIME

// Get the text alignment of the object.
DWORD FusionAPI GetTextAlignment(mv* mV, EDITDATA* edPtr) {
    #pragma MFXExport

    DWORD dw = 0;
    // Example
    // -------
/*	if ( (edPtr->eData.dwFlags & ALIGN_LEFT) != 0 )
        dw |= TEXT_ALIGN_LEFT;
    if ( (edPtr->eData.dwFlags & ALIGN_HCENTER) != 0 )
        dw |= TEXT_ALIGN_HCENTER;
    if ( (edPtr->eData.dwFlags & ALIGN_RIGHT) != 0 )
        dw |= TEXT_ALIGN_RIGHT;
    if ( (edPtr->eData.dwFlags & ALIGN_TOP) != 0 )
        dw |= TEXT_ALIGN_TOP;
    if ( (edPtr->eData.dwFlags & ALIGN_VCENTER) != 0 )
        dw |= TEXT_ALIGN_VCENTER;
    if ( (edPtr->eData.dwFlags & ALIGN_BOTTOM) != 0 )
        dw |= TEXT_ALIGN_BOTTOM;
*/
    return dw;
}

// Set the text alignment of the object.
void FusionAPI SetTextAlignment(mv* mV, EDITDATA* edPtr, DWORD dwAlignFlags) {
    #pragma MFXExport

    // Example
    // -------
/*	DWORD dw = edPtr->eData.dwFlags;

    if ( (dwAlignFlags & TEXT_ALIGN_LEFT) != 0 )
        dw = (dw & ~(ALIGN_LEFT|ALIGN_HCENTER|ALIGN_RIGHT)) | ALIGN_LEFT;
    if ( (dwAlignFlags & TEXT_ALIGN_HCENTER) != 0 )
        dw = (dw & ~(ALIGN_LEFT|ALIGN_HCENTER|ALIGN_RIGHT)) | ALIGN_HCENTER;
    if ( (dwAlignFlags & TEXT_ALIGN_RIGHT) != 0 )
        dw = (dw & ~(ALIGN_LEFT|ALIGN_HCENTER|ALIGN_RIGHT)) | ALIGN_RIGHT;

    if ( (dwAlignFlags & TEXT_ALIGN_TOP) != 0 )
        dw = (dw & ~(ALIGN_TOP|ALIGN_VCENTER|ALIGN_BOTTOM)) | ALIGN_TOP;
    if ( (dwAlignFlags & TEXT_ALIGN_VCENTER) != 0 )
        dw = (dw & ~(ALIGN_TOP|ALIGN_VCENTER|ALIGN_BOTTOM)) | ALIGN_VCENTER;
    if ( (dwAlignFlags & TEXT_ALIGN_BOTTOM) != 0 )
        dw = (dw & ~(ALIGN_TOP|ALIGN_VCENTER|ALIGN_BOTTOM)) | ALIGN_BOTTOM;

    edPtr->eData.dwFlags = dw;
*/
}

#endif // EDITTIME
