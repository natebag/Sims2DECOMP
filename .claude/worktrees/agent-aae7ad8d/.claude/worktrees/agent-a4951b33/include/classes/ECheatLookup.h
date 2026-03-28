#ifndef ECHEATLOOKUP_H
#define ECHEATLOOKUP_H

#include "types.h"

// ECheatLookup - struct layout extracted from assembly analysis
// Estimated minimum size: 0x60 (96 bytes)
// 8 known fields (0 named), 20 methods

class ECheatLookup {
public:
    // Constructors / Destructors
    ECheatLookup(int, char *, CheatType, void *, char *, bool, bool)  // 0x80055A2C
    ECheatLookup(void)  // 0x800559C0

    // Methods
    /* ? */ GetName(void);  // 0x800568CC (44B)
    /* ? */ GetType(void);  // 0x800568F8 (44B)
    /* ? */ GetVarPointer(void);  // 0x80056924 (44B)
    /* ? */ GetIndex(void);  // 0x800568A0 (44B)
    void WriteCheat(EFile *, int &);  // 0x80055B7C (908B)
    void AddToMenu(void);  // 0x80056950 (44B)
    void SetDebugMenuItem(ECheatDMI *);  // 0x8005697C (40B)
    /* ? */ GetDebugMenuItem(void);  // 0x800569A4 (44B)
    void hash(void);  // 0x80055F08 (80B)
    void hash(char *);  // 0x80055F58 (76B)
    void compare(char *);  // 0x80055FA4 (100B)
    void destroy(void);  // 0x8005714C (56B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[4];  // 0x000
    u32 m_field_004;  // 0x004 [W] (ECheatLookup)
    u8 _pad_008[0x3F];  // 0x008
    u8 m_field_047;  // 0x047 [W] (ECheatLookup)
    u32 m_field_048;  // 0x048 [R/W] (ECheatLookup, WriteCheat)
    u32 m_field_04C;  // 0x04C [R/W] (ECheatLookup, WriteCheat)
    u32 m_field_050;  // 0x050 [R/W] (ECheatLookup, WriteCheat)
    u32 m_field_054;  // 0x054 [W] (ECheatLookup)
    u32 m_field_058;  // 0x058 [R/W] (ECheatLookup, WriteCheat)
    u32 m_field_05C;  // 0x05C [W] (ECheatLookup)
};

#endif // ECHEATLOOKUP_H
