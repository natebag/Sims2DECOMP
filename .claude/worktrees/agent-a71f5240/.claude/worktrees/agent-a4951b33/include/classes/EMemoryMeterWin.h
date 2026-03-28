#ifndef EMEMORYMETERWIN_H
#define EMEMORYMETERWIN_H

#include "types.h"

// EMemoryMeterWin - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 10 known fields (2 named), 16 methods

class EMemoryMeterWin {
public:
    // Constructors / Destructors
    EMemoryMeterWin(void)  // 0x8010C030
    ~EMemoryMeterWin(void);  // 0x8010C0CC

    // Methods
    void Init(void);  // 0x8010C120 (32B)
    void PollMemoryLevels(void);  // 0x8010C214 (812B)
    void Reset(void);  // 0x8010C140 (32B)
    void SetState(Panelstateman::Panelstate);  // 0x8010C160 (60B)
    /* ? */ GetAffordable(ObjSelector *);  // 0x8010C19C (120B)
    void SetEvent(Panelstateman::PanelEvent, unsigned int);  // 0x80110690 (40B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (EMemoryMeterWin)
    u32 m_field_004;  // 0x004 [R/W] (EMemoryMeterWin, PollMemoryLevels, ~EMemoryMeterWin)
    f32 m_affordable;  // 0x008 [R/W] (EMemoryMeterWin, GetAffordable, PollMemoryLevels)
    f32 m_field_00C;  // 0x00C [W] (PollMemoryLevels)
    f32 m_field_010;  // 0x010 [W] (EMemoryMeterWin, PollMemoryLevels)
    u32 m_field_014;  // 0x014 [W] (EMemoryMeterWin, PollMemoryLevels)
    f32 m_field_018;  // 0x018 [W] (EMemoryMeterWin, PollMemoryLevels)
    u32 m_field_01C;  // 0x01C [W] (EMemoryMeterWin, PollMemoryLevels)
    f32 m_field_020;  // 0x020 [W] (EMemoryMeterWin, PollMemoryLevels)
    u32 m_field_024;  // 0x024 [W] (EMemoryMeterWin, PollMemoryLevels)
};

#endif // EMEMORYMETERWIN_H
