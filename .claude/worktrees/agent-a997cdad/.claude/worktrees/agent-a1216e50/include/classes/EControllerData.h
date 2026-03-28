#ifndef ECONTROLLERDATA_H
#define ECONTROLLERDATA_H

#include "types.h"

// EControllerData - struct layout extracted from assembly analysis
// Estimated minimum size: 0x7C (124 bytes)
// 11 known fields (1 named), 16 methods

class EControllerData {
public:
    // Constructors / Destructors
    EControllerData(void)  // 0x807F67C4
    ~EControllerData(void);  // 0x807F6808

    // Methods
    void Reset(bool);  // 0x8090E1CC (528B)
    void operator=(EControllerData &);  // 0x8090E3DC (756B)
    void Clear(bool);  // 0x8090DFB4 (536B)
    /* ? */ GetGotEvent(unsigned int);  // 0x8090DE8C (80B)
    void SetPressedFirst(unsigned int, bool);  // 0x8090DEDC (108B)
    void SetGotEvent(unsigned int, bool);  // 0x8090DF48 (108B)
    /* ? */ GetPressedFirst(unsigned int);  // 0x8090DE3C (80B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (Clear, operator=)
    u32 m_field_004;  // 0x004 [W] (Clear, operator=)
    u32 m_field_008;  // 0x008 [R/W] (Clear, Reset, operator=)
    u32 m_field_00C;  // 0x00C [W] (Clear, Reset, operator=)
    u32 m_field_010;  // 0x010 [R/W] (Clear, Reset, operator=)
    u32 m_field_014;  // 0x014 [W] (Clear, Reset, operator=)
    u32 m_field_018;  // 0x018 [R/W] (Clear, Reset, operator=)
    u32 m_field_01C;  // 0x01C [W] (Clear, Reset, operator=)
    u32 m_field_020;  // 0x020 [R/W] (Clear, Reset, operator=)
    u32 m_field_024;  // 0x024 [W] (Clear, Reset, operator=)
    u8 _pad_028[0x50];  // 0x028
    u32 m_field_078;  // 0x078 [W] (Clear, Reset)
};

#endif // ECONTROLLERDATA_H
