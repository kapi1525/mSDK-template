#pragma once


// Minimum Fusion version that is required by your extension
// #define TGFEXT   // The Games Factory, Fusion Standard and Fusion Developer
#define	MMFEXT      // Fusion Standard and Fusion Developer
// #define PROEXT   // Only Fusion Developer


// Minimum required Fusion build
#ifdef _UNICODE
#define	MINBUILD	249
#else
#define	MINBUILD	243
#endif

// General includes
#include "CommonSDK.hpp"
#include "Ccxhdr.h"
#include "Surface.hpp"

// Specific to this cox
#include "resource.h"
#include "Main.hpp"
#include "TigsExt.hpp"
// #include "FileIO.hpp"           // File reading/writing functions
// #include "Filters.hpp"          // Image and sound filters for loading and saving image/sound files


// Globals and Prototypes
extern HINSTANCE hInstLib;
extern short actionsInfos[];
extern short conditionsInfos[];
extern short expressionsInfos[];

extern short (WINAPI * ActionJumps[])(RUNDATA* rdPtr, long param1, long param2);
extern long (WINAPI * ConditionJumps[])(RUNDATA* rdPtr, long param1, long param2);
extern long (WINAPI * ExpressionJumps[])(RUNDATA* rdPtr, long param);


// Used to ensure the MMF version is 1.5, you can safely ignore this
#ifdef MMFEXT
#define	IS_COMPATIBLE(v) (v->mvGetVersion != NULL && (v->mvGetVersion() & MMFBUILD_MASK) >= MINBUILD && (v->mvGetVersion() & MMFVERSION_MASK) >= MMFVERSION_20 && ((v->mvGetVersion() & MMFVERFLAG_MASK) & MMFVERFLAG_HOME) == 0)
#elif defined(PROEXT)
#define IS_COMPATIBLE(v) (v->mvGetVersion != NULL && (v->mvGetVersion() & MMFBUILD_MASK) >= MINBUILD && (v->mvGetVersion() & MMFVERSION_MASK) >= MMFVERSION_20 && ((v->mvGetVersion() & MMFVERFLAG_MASK) & MMFVERFLAG_PRO) != 0)
#else
#define	IS_COMPATIBLE(v) (v->mvGetVersion != NULL && (v->mvGetVersion() & MMFBUILD_MASK) >= MINBUILD && (v->mvGetVersion() & MMFVERSION_MASK) >= MMFVERSION_20)
#endif
