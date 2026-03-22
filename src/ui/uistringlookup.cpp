// uistringlookup.cpp - UI string lookup tables
// Part of the Sims 2 GC decompilation
// Original: u2_ngc_release_dvd(uistringlookup.obj)
//
// Small functions (<=64 bytes) - mostly BSS/SBSS globals and global ctors.
// These are string table pointers used by the UI system.

#include "types.h"
#include "stub_classes.h"

// All 56 "small functions" in this obj file are actually BSS globals
// (static string pointers) and global ctor/dtor pairs, not real functions.

// String table pointers (all initially NULL, set during init)
void* _sHoursLookup = 0;
void* _sHours24Lookup = 0;
void* _sMinLookup = 0;
void* _sAM_PMLookup = 0;
void* _sNum = 0;
void* _sAmount = 0;
void* _sName = 0;
void* _sLiquidate = 0;
void* _sDlrSgn = 0;
void* _s1000s = 0;
void* _s100s = 0;
void* _sColon = 0;
void* _sComma = 0;
void* _sPeriod = 0;
void* _sMinus = 0;
void* _sSlash = 0;
void* _sPercent = 0;
void* _sDay = 0;
void* _sMonthName = 0;
void* _sYearNum = 0;
void* _sSeasonName = 0;
void* _sWeekdayName = 0;
void* _sTimeOfDayName = 0;
