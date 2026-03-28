#ifndef SIMLOG_H
#define SIMLOG_H

#include "types.h"

// SimLog - struct layout extracted from assembly analysis
// Estimated minimum size: 0x18 (24 bytes)
// 6 known fields (6 named), 16 methods

class SimLog {
public:
    // Constructors / Destructors
    SimLog(void)  // 0x803B2E14
    ~SimLog(void);  // 0x803B3F64

    // Methods
    /* ? */ GetLog(void);  // 0x8037A990 (40B)
    bool IsLogging(void);  // 0x8037A9B8 (44B)
    void SimTickCompleted(cXPerson *);  // 0x803B2EB0 (800B)
    /* ? */ GetTracker(cXPerson *);  // 0x803B31D0 (380B)
    /* ? */ GetLog(LogPersonTracker *);  // 0x803B334C (396B)
    void BeginLogging(void);  // 0x803B34D8 (40B)
    void EndLogging(void);  // 0x803B3500 (160B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (EndLogging, GetTracker, SimTickCompleted)
    u32 m_tracker_004;  // 0x004 [R/W] (EndLogging, GetLog, GetTracker, ...)
    u32 m_tracker_008;  // 0x008 [R/W] (GetTracker)
    u32 m_tracker_00C;  // 0x00C [R/W] (GetTracker)
    u32 m_tracker_010;  // 0x010 [R/W] (EndLogging, GetLog, GetTracker, ...)
    u32 m_tracker_014;  // 0x014 [R/W] (EndLogging, GetTracker, ~SimLog)
};

#endif // SIMLOG_H
