// This file contains functions that are run only during Edittime in editor
// aka: Frave editor, Event editor etc.

#include "Common.hpp"



#ifdef EDITTIME

// Returns object info to Fusion
void FusionAPI GetObjInfos (mv* mV, EDITDATA* edPtr, LPTSTR ObjName, LPTSTR ObjAuthor, LPTSTR ObjCopyright, LPTSTR ObjComment, LPTSTR ObjHttp) {
    #pragma MFXExport

    LoadString(hInstLib, IDST_OBJNAME,ObjName, 255);        // Name
    LoadString(hInstLib, IDST_AUTHOR,ObjAuthor,255);        // Author
    LoadString(hInstLib, IDST_COPYRIGHT,ObjCopyright,255);  // Copyright
    LoadString(hInstLib, IDST_COMMENT,ObjComment,1024);     // Comment
    LoadString(hInstLib, IDST_HTTP,ObjHttp,255);            // Internet address
}

// Returns a path to help file
LPCTSTR FusionAPI GetHelpFileName() {
    #pragma MFXExport

    // Return only a file without path if your help file can be loaded by Fusion help file
    // return _T("MyHelpFile.chm");
    // Or a path to your file relative to Fusion install directory if it cant
    // return _T("Help\\MyExt.chm");

    return NULL;    // No help file
}



// Frame editor functions



// Called once when object is created or modified
// Load your icon into pIconSf surface
// Note: If this function is not implemented Fusion will load EXO_ICON automaticaly and use it.
/*
int FusionAPI MakeIconEx(mv* mV, cSurface* pIconSf, LPTSTR lpName, OI* oiPtr, EDITDATA* edPtr) {
    #pragma MFXExport
    
    int status = -1;
    if (pIconSf->LoadImage(hInstLib, EXO_ICON)) {
        status = 0;
    }

    return status;
}
*/
        


// Called when user clicks "Create new object"
// Initialize EDITDATA here.
int FusionAPI CreateObject(mv* mV, LO* loPtr, EDITDATA* edPtr) {
    #pragma MFXExport

    // Check compatibility
    if (!IS_COMPATIBLE(mV)) {
        return CREATE_OBJECT_ERROR;
    }

    // Init everything here

    return CREATE_OBJECT_OK;
}

// Called when user clicks "Edit"
BOOL FusionAPI EditObject(mv* mV, OI* oiPtr, LO* loPtr, EDITDATA* edPtr) {
    #pragma MFXExport

    // Check compatibility
    if (!IS_COMPATIBLE(mV)) {
        return FALSE;
    }

    // Do whatever you want here

    return TRUE;
}



// Called when object was resized
// If not implemented object will have a set size
/*
BOOL FusionAPI SetEditSize(mv* mv, EDITDATA* edPtr, int cx, int cy) {
    #pragma MFXExport

    // edPtr->swidth = cx;
    // edPtr->sheight = cy;
    return TRUE;
}
*/



// Called when each individual object is dropped in the frame
void FusionAPI PutObject(mv* mV, LO* loPtr, EDITDATA* edPtr, unsigned short cpt) {
    #pragma MFXExport
}

// Called when each individual object is removed from the frame
void FusionAPI RemoveObject(mv* mV, LO* loPtr, EDITDATA* edPtr, unsigned short cpt) {
    #pragma MFXExport

    // Is the last object removed?
    if (0 == cpt) {
        // Do whatever necessary to remove our data
    }
}



// Called when user clicks "Clone object"
void FusionAPI DuplicateObject(mv* mV, OI* oiPtr, EDITDATA* edPtr) {
    #pragma MFXExport
}



// Returns size of object
void FusionAPI GetObjectRect(mv* mV, RECT* rc, LO* loPtr, EDITDATA* edPtr) {
    #pragma MFXExport

    rc->right = rc->left + 32;  // edPtr->swidth;
    rc->bottom = rc->top + 32;  // edPtr->sheight;
}



// Called when object is drawn in frame editor
// Note: If this function is unimplemented Fusion will draw EXO_IMAGE bitmap as our object for us
/*
void FusionAPI EditorDisplay(mv* mV, OI* oiPtr, LO* loPtr, EDITDATA* edPtr, RECT* rc) {
    #pragma MFXExport

    // Get frame editor surface
    cSurface* ps = WinGetSurface((int)mV->mvIdEditWin);
    if (ps != NULL) {
        // Objects position and size
        int x = rc->left;
        int y = rc->top;
        int w = rc->right - rc->left;
        int h = rc->bottom - rc->top;

        // Load image into a new surface
        cSurface is;
        is.Create(0, 0, ps);	// Create a surface implementation from a prototype (frame editor surface)
        is.LoadImage(hInstLib, EXO_ICON, LI_REMAP);    // Load image and remap pallete if necessary
        is.Blit(*ps, x, y, BMODE_TRANSP, BOP_COPY, 0);  // Blit our image into frame editor surface
    }
}
*/



// True if mouse is over a transparent part of the object
extern "C" BOOL FusionAPI IsTransparent(mv* mV, LO* loPtr, EDITDATA* edPtr, int dx, int dy) {
    #pragma MFXExport
    return FALSE;
}

// Called before EDITDATA is saved to an MFA, EXE etc
void FusionAPI PrepareToWriteObject(mv* mV, EDITDATA* edPtr, OI* adoi) {
    #pragma MFXExport
}

// True if your extension uses image or sound filters(?)
BOOL FusionAPI GetFilters(mv* mV, EDITDATA* edPtr, DWORD dwFlags, LPVOID pReserved) {
    #pragma MFXExport

    // If your extension uses image filters
    // if ((dwFlags & GETFILTERS_IMAGES)) {
    //     return TRUE;
    // }

    // If your extension uses sound filters
    // if ((dwFlags & GETFILTERS_SOUNDS)) {
    //     return TRUE;
    // }

    return FALSE;
}



// Called when user drops a file onto frame
// Return true if object can be created from given file
BOOL FusionAPI UsesFile(mv* mV, LPTSTR fileName) {
    #pragma MFXExport
    return FALSE;
}

// If you can create object from that file and user selects your object this function is called
void FusionAPI CreateFromFile(mv* mV, LPTSTR fileName, EDITDATA* edPtr) {
    #pragma MFXExport

    // Initialize your extension data from the given file
    // edPtr->swidth = 32;
    // edPtr->sheight = 32;

    // Example: store the filename
    // _tcscpy(edPtr->myFileName, fileName);
}



// Event editor functions



// Internal used later
// Copy menu into another
inline void menucpy(HMENU hTargetMenu, HMENU hSourceMenu) {
    int			n, id, nMn;
    LPTSTR		strBuf;
    HMENU		hSubMenu;
    
    nMn = GetMenuItemCount(hSourceMenu);
    strBuf = (LPTSTR)calloc(80, sizeof(TCHAR));
    for (n = 0; n < nMn; n++)
    {
        if (0 == (id = GetMenuItemID(hSourceMenu, n)))
            AppendMenu(hTargetMenu, MF_SEPARATOR, 0, 0L);
        else
        {
            GetMenuString(hSourceMenu, n, strBuf, 80, MF_BYPOSITION);
            if (id != -1)
                AppendMenu(hTargetMenu, GetMenuState(hSourceMenu, n, MF_BYPOSITION), id, strBuf);
            else
            {
                hSubMenu = CreatePopupMenu();
                AppendMenu(hTargetMenu, MF_POPUP | MF_STRING, (unsigned int)hSubMenu, strBuf);
                menucpy(hSubMenu, GetSubMenu(hSourceMenu, n));
            }
        }
    }
    free(strBuf);
}


// Load ACE menus from resources
// If you want you can disable enable some menu options
inline HMENU GetPopupMenu(short mn) {
    HMENU	hMn, hSubMenu, hPopup = NULL;

    if ((hMn = LoadMenu(hInstLib, MAKEINTRESOURCE(mn))) != NULL)
    {
        if ((hSubMenu = GetSubMenu(hMn, 0)) != NULL)
        {
            if ((hPopup = CreatePopupMenu()) != NULL)
                menucpy(hPopup, hSubMenu);
        }
        DestroyMenu(hMn);
    }
    return hPopup;
}


HMENU FusionAPI GetActionMenu(mv* mV, OI* oiPtr, EDITDATA* edPtr) {
    #pragma MFXExport

    // Check compatibility
    if (IS_COMPATIBLE(mV)) {
        return GetPopupMenu(MN_ACTIONS);
    }
    
    return NULL;
}

HMENU FusionAPI GetConditionMenu(mv* mV, OI* oiPtr, EDITDATA* edPtr) {
    #pragma MFXExport

    // Check compatibility
    if (IS_COMPATIBLE(mV)) {
        return GetPopupMenu(MN_CONDITIONS);
    }

    return NULL;
}

HMENU FusionAPI GetExpressionMenu(mv* mV, OI* oiPtr, EDITDATA* edPtr) {
    #pragma MFXExport

    // Check compatibility
    if (IS_COMPATIBLE(mV)) {
        return GetPopupMenu(MN_EXPRESSIONS);
    }

    return NULL;
}



// Return ACE parameter title to Fusion (Window title of a popup where you enter ACE parameter)
inline static eventInformations2* GetEventInformations(eventInformations2* eiPtr, short code) {
    while(eiPtr->infos.code != code)
        eiPtr = EVINFO2_NEXT(eiPtr);
    
    return eiPtr;
}


inline void GetCodeTitle(eventInformations2* eiPtr, short code, short param, short mn, LPTSTR strBuf, WORD maxLen) {
    HMENU hMn;
    eiPtr = GetEventInformations(eiPtr, code);      // Finds event in array

    // If a special string is to be returned
    short strID = EVINFO2_PARAMTITLE(eiPtr, param); 

    if (strID != 0) {
        LoadString(hInstLib, strID, strBuf, maxLen);
    } else {
        // Otherwise, returns the menu option
        if ((hMn = LoadMenu(hInstLib, MAKEINTRESOURCE(mn)))) {
            GetMenuString(hMn, eiPtr->menu, strBuf, maxLen, MF_BYCOMMAND);
            DestroyMenu(hMn);
        }
    }
}


void FusionAPI GetActionTitle(mv* mV, short code, short param, LPTSTR strBuf, short maxLen) {
    #pragma MFXExport
    GetCodeTitle((eventInformations2*)actionsInfos, code, param, MN_ACTIONS, strBuf, maxLen);
}

void FusionAPI GetConditionTitle(mv* mV, short code, short param, LPTSTR strBuf, short maxLen) {
    #pragma MFXExport
    GetCodeTitle((eventInformations2*)conditionsInfos, code, param, MN_CONDITIONS, strBuf, maxLen);
}

void FusionAPI GetExpressionTitle(mv* mV, short code, LPTSTR strBuf, short maxLen) {
    #pragma MFXExport
    GetCodeTitle((eventInformations2*)expressionsInfos, code, 0, MN_EXPRESSIONS, strBuf, maxLen);
}



// Return ACE ID from a Menu ID
inline short GetACECodeFromMenu(short* infos, int count, mv* mV, short menuID) {
    eventInformations2* eiPtr;
    int n;

    for (n = count, eiPtr = (eventInformations2*)infos; n > 0 && eiPtr->menu!=menuID; n--) {
        eiPtr = EVINFO2_NEXT(eiPtr);
    }
    if (n > 0) {
        return eiPtr->infos.code;
    }
    
    return -1;
}


short FusionAPI GetActionCodeFromMenu(mv* mV, short menuID) {
    #pragma MFXExport
    return GetACECodeFromMenu(actionsInfos, ACT_LAST, mV, menuID);
}

short FusionAPI GetConditionCodeFromMenu(mv* mV, short menuID) {
    #pragma MFXExport
    return GetACECodeFromMenu(conditionsInfos, CND_LAST, mV, menuID);
}

short FusionAPI GetExpressionCodeFromMenu(mv* mV, short menuID) {
    #pragma MFXExport
    return GetACECodeFromMenu(expressionsInfos, EXP_LAST, mV, menuID);
}



// Returns infosEvents from ACE ID
infosEventsV2* FusionAPI GetActionInfos(mv* mV, short code) {
    #pragma MFXExport
    return &GetEventInformations((eventInformations2*)actionsInfos, code)->infos;
}

infosEventsV2* FusionAPI GetConditionInfos(mv* mV, short code) {
    #pragma MFXExport
    return &GetEventInformations((eventInformations2*)conditionsInfos, code)->infos;
}

infosEventsV2* FusionAPI GetExpressionInfos(mv* mV, short code) {
    #pragma MFXExport
    return &GetEventInformations((eventInformations2*)expressionsInfos, code)->infos;
}



// Returns ACE string displayed in event editor
void FusionAPI GetActionString(mv* mV, short code, LPTSTR strPtr, short maxLen) {
    #pragma MFXExport

    // Check compatibility
    if (IS_COMPATIBLE(mV)) {
        LoadString(hInstLib, GetEventInformations((eventInformations2*)actionsInfos, code)->string, strPtr, maxLen);
    }
}

void FusionAPI GetConditionString(mv* mV, short code, LPTSTR strPtr, short maxLen) {
    #pragma MFXExport

    // Check compatibility
    if (IS_COMPATIBLE(mV)) {
        LoadString(hInstLib, GetEventInformations((eventInformations2*)conditionsInfos, code)->string, strPtr, maxLen);
    }
}

void FusionAPI GetExpressionString(mv* mV, short code, LPTSTR strPtr, short maxLen) {
    #pragma MFXExport

    // Check compatibility
    if (IS_COMPATIBLE(mV)) {
        LoadString(hInstLib, GetEventInformations((eventInformations2*)expressionsInfos, code)->string, strPtr, maxLen);
    }
}



// Returns the parameter name to display in the expression editor
void FusionAPI GetExpressionParam(mv* mV, short code, short param, LPTSTR strBuf, short maxLen) {
    #pragma MFXExport

    short strID;

    // Finds event in array
    eventInformations2* eiPtr = GetEventInformations((eventInformations2*)expressionsInfos, code);

    // If a special string is to be returned
    strID = EVINFO2_PARAMTITLE(eiPtr, param);
    if (strID != 0) {
        LoadString(hInstLib, strID, strBuf, maxLen);
    } else {
        *strBuf=0;
    }
}



// Custom Parameters



// Initialize the parameter.
void FusionAPI InitParameter(mv* mV, short code, paramExt* pExt) {
    #pragma MFXExport

    // Example
    // _tcscpy(&pExt->pextData[0], _T("Parameter Test"));
    // pExt->pextSize = sizeof(paramExt) + (_tcslen(pExt->pextData)+1)*sizeof(TCHAR);
}

/*
BOOL CALLBACK SetupProc(HWND hDlg, UINT msgType, WPARAM wParam, LPARAM lParam) {
    paramExt*			pExt;

    switch (msgType)
    {
        case WM_INITDIALOG: // Init dialog
            // Save edptr
            SetWindowLong(hDlg, DWL_USER, lParam);
            pExt=(paramExt*)lParam;

            SetDlgItemText(hDlg, IDC_EDIT, pExt->pextData);
            return TRUE;

        case WM_COMMAND: // Command
            // Retrieve edptr
            pExt = (paramExt *)GetWindowLong(hDlg, DWL_USER);

            switch (wmCommandID)
            {
            case IDOK:	// Exit
                GetDlgItemText(hDlg, IDC_EDIT, pExt->pextData, 500);
                pExt->pextSize=sizeof(paramExt)+(_tcslen(pExt->pextData)+1)*sizeof(TCHAR);
                EndDialog(hDlg, TRUE);
                return TRUE;

                default:
                    break;
            }
            break;

        default:
            break;
    }
    return FALSE;
}
*/

// Edit the parameter.
void FusionAPI EditParameter(mv* mV, short code, paramExt* pExt) {
    #pragma MFXExport

    // Example
    // DialogBoxParam(hInstLib, MAKEINTRESOURCE(DB_TRYPARAM), mV->mvHEditWin, SetupProc, (LPARAM)(LPBYTE)pExt);
}

// Initialize the parameter.
void FusionAPI GetParameterString(mv* mV, short code, paramExt* pExt, LPTSTR pDest, short size) {
    #pragma MFXExport
    
    // Example
    // wsprintf(pDest, "Super parameter %s", pExt->pextData);

}

#endif // EDITTIME
