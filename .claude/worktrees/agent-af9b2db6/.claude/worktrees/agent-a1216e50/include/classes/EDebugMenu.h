#ifndef EDEBUGMENU_H
#define EDEBUGMENU_H

#include "types.h"

// EDebugMenu - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1C (28 bytes)
// 6 known fields (0 named), 12 methods

class EDebugMenu {
public:
    // Constructors / Destructors
    EDebugMenu(void)  // 0x8080C344

    // Methods
    void Add(EDebugMenuItem &);  // 0x8080C3A8 (88B)
    void Remove(EDebugMenuItem &);  // 0x8080C400 (224B)
    void ComputeMaxWidth(ERFont *);  // 0x8080C4E0 (344B)
    void Draw(void);  // 0x8080C638 (1112B)
    void Update(void);  // 0x8080CA90 (776B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (Draw, Update)
    f32 m_field_004;  // 0x004 [R/W] (ComputeMaxWidth, Draw)
    u32 m_field_008;  // 0x008 [R/W] (Add, ComputeMaxWidth, Draw, ...)
    u32 m_field_00C;  // 0x00C [R/W] (Add, ComputeMaxWidth, Draw, ...)
    u8 _pad_010[4];  // 0x010
    u32 m_field_014;  // 0x014 [R/W] (Draw, Remove, Update)
    u32 m_field_018;  // 0x018 [R/W] (Add, Remove, Update)
};

#endif // EDEBUGMENU_H
