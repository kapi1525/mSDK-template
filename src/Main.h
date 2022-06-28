// Object identifier "SAM3"
// #pragma message ("************************ WARNING ****************************")
// #pragma message ("***** Do not forget to change the IDENTIFIER in Main.h! *****")
// #pragma message ("*************************************************************")

#define IDENTIFIER	MAKEID(S,A,M,3)		// REQUIRED: you MUST replace the letters in the MAKEID macro by others
                                        // and then remove the #pragma message above. If you do not do this, MMF2
                                        // could confuse your object with another in the event editor.


// ACEs IDs
// DEFINITION OF ACTIONS CODES
#define	ACT_ACTION          0
#define	ACT_LAST            1

// DEFINITION OF CONDITIONS CODES
#define	CND_CONDITION       0
#define	CND_LAST            1

// DEFINITION OF EXPRESSIONS CODES
#define	EXP_EXPRESSION      0
#define EXP_EXPRESSION2     1
#define EXP_EXPRESSION3     2
#define	EXP_LAST            3



// EDITDATA stores data that can be modified in editor by user
struct EDITDATA_v1 {
    extHeader eHeader; // Required, must be first.

    // Objects editor data
    // short swidth;
    // short sheight;
};

// When modyfing EDITDATA and you care about backwards compatibility create new version of EDITDATA and dont remove old version
// then implement UpdateEditStructure() function to update old EDITDATA into new one
using EDITDATA = EDITDATA_v1;


// Object versions
#define	KCX_CURRENT_VERSION 1


// Objects rundata
// During runtime rundata is unique data for every object
// Initialize it in CreateRunObject()
// Free any alocated memory in DestroyRunObject()
// Note: You need to manualy call constructors and destructors of C++ objects that you store here.
struct RUNDATA {
    headerObject rHo; // Required, must be first.

    // Optional structures - depend on object flags bellow
    // rCom rc;    // Movements and animations
    // rMvt rm;    // Movements
    // rSpr rs;    // Sprite
    // rVal rv;    // Alterable values

    // Objects runtime data
};


// Maximum EDITDATA size.
#define	MAX_EDITSIZE sizeof(EDITDATA)


// Object flags, look at help file for more info.
#define	OEFLAGS 0
#define	OEPREFS 0


// If you want to intercept window messages, set priority of WindowProc
// 0 = low    100 = normal    255 = very high
#define	WINDOWPROC_PRIORITY 100
