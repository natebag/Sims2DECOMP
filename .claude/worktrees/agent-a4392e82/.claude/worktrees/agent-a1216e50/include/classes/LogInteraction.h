#ifndef LOGINTERACTION_H
#define LOGINTERACTION_H

#include "types.h"

// LogInteraction - struct layout extracted from assembly analysis
// Estimated minimum size: 0x18 (24 bytes)
// 6 known fields (1 named), 15 methods

class LogInteraction {
public:
    // Constructors / Destructors
    LogInteraction(LogPersonTracker *)  // 0x803B29FC
    LogInteraction(LogInteraction &)  // 0x803B56E0
    ~LogInteraction(void);  // 0x803B41E8

    // Methods
    void SameInteraction(LogPersonTracker *);  // 0x803B2C10 (132B)
    void AddSample(LogInteractionSample &);  // 0x803B2C94 (68B)
    void PrintHeader(void);  // 0x803B2CD8 (88B)
    void Print(void);  // 0x803B2D30 (228B)
    bool HasObject(void);  // 0x803B4264 (60B)
    void operator=(LogInteraction &);  // 0x803B6548 (148B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (AddSample, LogInteraction)
    u32 m_field_004;  // 0x004 [R/W] (AddSample, LogInteraction)
    u32 m_field_008;  // 0x008 [W] (AddSample)
    u32 m_field_00C;  // 0x00C [W] (AddSample)
    u32 m_field_010;  // 0x010 [R/W] (AddSample, LogInteraction, Print)
    u32 m_field_014;  // 0x014 [W] (AddSample, LogInteraction)
};

#endif // LOGINTERACTION_H
