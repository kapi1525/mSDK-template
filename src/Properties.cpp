#include "Common.h"

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
