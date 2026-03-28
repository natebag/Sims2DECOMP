#ifndef LOGPERSONTRACKER_H
#define LOGPERSONTRACKER_H

#include "types.h"

// LogPersonTracker - struct layout extracted from assembly analysis
// Estimated minimum size: 0x370 (880 bytes)
// 14 known fields (9 named), 15 methods

class LogPersonTracker {
public:
    // Constructors / Destructors
    LogPersonTracker(cXPerson *)  // 0x803B27B0

    // Methods
    void SameInteraction(Interaction *);  // 0x803B2324 (340B)
    void SetInteraction(cXPerson *, Interaction *);  // 0x803B2478 (536B)
    void SamePerson(cXPerson *);  // 0x803B2690 (288B)
    void Print(void);  // 0x803B28F4 (132B)
    void PrintHeader(void);  // 0x803B2978 (132B)
    /* ? */ GetObjectGUID(void);  // 0x803B4164 (44B)
    /* ? */ GetInteractionIndex(void);  // 0x803B4190 (44B)
    /* ? */ GetSample(void);  // 0x803B41BC (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (LogPersonTracker, SamePerson, SetInteraction)
    s16 m_interaction_004;  // 0x004 [R/W] (LogPersonTracker, SamePerson, SetInteraction)
    u8 _pad_006[2];  // 0x006
    u32 m_interaction_008;  // 0x008 [R/W] (LogPersonTracker, SameInteraction, SetInteraction)
    s16 m_interaction_00C;  // 0x00C [R/W] (LogPersonTracker, SameInteraction, SetInteraction)
    u8 _pad_00E[2];  // 0x00E
    u32 m_interaction_010;  // 0x010 [R/W] (LogPersonTracker, SameInteraction, SetInteraction)
    u32 m_field_014;  // 0x014 [R] (LogPersonTracker)
    u8 _pad_018[0x24];  // 0x018
    u32 m_interaction_03C;  // 0x03C [W] (SetInteraction)
    u32 m_interaction_040;  // 0x040 [W] (SetInteraction)
    u32 m_interaction_044;  // 0x044 [W] (SetInteraction)
    u32 m_interaction_048;  // 0x048 [W] (SetInteraction)
    u8 _pad_04C[0x2DC];  // 0x04C
    s16 m_field_328;  // 0x328 [R] (SameInteraction, SamePerson)
    u8 _pad_32A[2];  // 0x32A
    u32 m_field_32C;  // 0x32C [R] (SameInteraction, SamePerson)
    u8 _pad_330[0x38];  // 0x330
    s16 m_field_368;  // 0x368 [R] (SameInteraction, SamePerson)
    u8 _pad_36A[2];  // 0x36A
    u32 m_field_36C;  // 0x36C [R] (SameInteraction, SamePerson)
};

#endif // LOGPERSONTRACKER_H
