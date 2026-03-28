#ifndef INTERACTIONHELPER_H
#define INTERACTIONHELPER_H

#include "types.h"

// InteractionHelper - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1C (28 bytes)
// 6 known fields (1 named), 13 methods

class InteractionHelper {
public:
    // Constructors / Destructors
    InteractionHelper(void)  // 0x8059483C
    ~InteractionHelper(void);  // 0x804C2060

    // Methods
    void Init(InteractionList &);  // 0x804C21B0 (316B)
    void AddUnique(Interaction *);  // 0x804C22EC (936B)
    /* ? */ GetCount(IHRecord *);  // 0x804C2694 (160B)
    /* ? */ GetNext(IHRecord *);  // 0x804C2734 (92B)
    void FindRecord(int);  // 0x804C2790 (484B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddUnique, FindRecord, Init, ...)
    u32 m_field_004;  // 0x004 [R/W] (AddUnique, FindRecord, Init, ...)
    s16 m_field_008;  // 0x008 [R/W] (AddUnique, FindRecord)
    u8 _pad_00A[2];  // 0x00A
    u32 m_field_00C;  // 0x00C [R/W] (AddUnique, FindRecord, ~InteractionHelper)
    u32 m_field_010;  // 0x010 [W] (AddUnique)
    u8 _pad_014[4];  // 0x014
    u32 m_field_018;  // 0x018 [R/W] (AddUnique, ~InteractionHelper)
};

#endif // INTERACTIONHELPER_H
