#include "Common.h"



#ifdef EDITTIME

// IDs of items displayed in debuger
// enum {
// Example
//     DB_CURRENTSTRING,
//     DB_CURRENTVALUE,
//     DB_CURRENTCHECK,
//     DB_CURRENTCOMBO
// };

// Items displayed in the debugger
WORD DebugTree[] = {
// Example
    // DB_CURRENTSTRING|DB_EDITABLE,
    // DB_CURRENTVALUE|DB_EDITABLE,
    // DB_CURRENTCHECK,
    // DB_CURRENTCOMBO,

    // End of table (required)
    DB_END
};



// This function returns address of DebugTree
WORD* FusionAPI GetDebugTree(RUNDATA* rdPtr) {
    #pragma MFXExport

    return DebugTree;
}

// This function returns the text of a given item.
void FusionAPI GetDebugItem(LPTSTR pBuffer, RUNDATA* rdPtr, int id) {
    #pragma MFXExport

    // Example
    // char temp[DB_BUFFERSIZE];
    //
    // switch (id) {
    // case DB_CURRENTSTRING:
    //     LoadString(hInstLib, IDS_CURRENTSTRING, temp, DB_BUFFERSIZE);
    //     wsprintf(pBuffer, temp, rdPtr->text);
    //     break;
    // case DB_CURRENTVALUE:
    //     LoadString(hInstLib, IDS_CURRENTVALUE, temp, DB_BUFFERSIZE);
    //     wsprintf(pBuffer, temp, rdPtr->value);
    //     break;
    // case DB_CURRENTCHECK:
    //     LoadString(hInstLib, IDS_CURRENTCHECK, temp, DB_BUFFERSIZE);
    //     if (rdPtr->check)
    //         wsprintf(pBuffer, temp, _T("TRUE"));
    //     else
    //         wsprintf(pBuffer, temp, _T("FALSE"));
    //     break;
    // case DB_CURRENTCOMBO:
    //     LoadString(hInstLib, IDS_CURRENTCOMBO, temp, DB_BUFFERSIZE);
    //     wsprintf(pBuffer, temp, rdPtr->combo);
    //     break;
    // }
}

// This function allows to edit editable items.
void FusionAPI EditDebugItem(RUNDATA* rdPtr, int id) {
    #pragma MFXExport
    
    // Example
    // switch (id) {
    // case DB_CURRENTSTRING:
    //     {
    //         EditDebugInfo dbi;
    //         char buffer[256];
    //
    //         dbi.pText=buffer;
    //         dbi.lText=TEXT_MAX;
    //         dbi.pTitle=NULL;
    //
    //         strcpy(buffer, rdPtr->text);
    //         long ret=callRunTimeFunction(rdPtr, RFUNCTION_EDITTEXT, 0, (LPARAM)&dbi);
    //         if (ret)
    //             strcpy(rdPtr->text, dbi.pText);
    //     }
    //     break;
    // case DB_CURRENTVALUE:
    //     {
    //         EditDebugInfo dbi;
    //
    //         dbi.value=rdPtr->value;
    //         dbi.pTitle=NULL;
    //
    //         long ret=callRunTimeFunction(rdPtr, RFUNCTION_EDITINT, 0, (LPARAM)&dbi);
    //         if (ret)
    //             rdPtr->value=dbi.value;
    //     }
    //     break;
    // }
}

#endif // EDITTIME
