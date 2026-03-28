#ifndef PLAYERCHEATS_H
#define PLAYERCHEATS_H

#include "types.h"

// PlayerCheats - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1C (28 bytes)
// 3 known fields (0 named), 13 methods

class PlayerCheats {
public:
    // Constructors / Destructors
    PlayerCheats(void)  // 0x8000E538
    ~PlayerCheats(void);  // 0x8000E5B0

    // Methods
    void StartClock(void);  // 0x8000E5FC (112B)
    void Capture(EController *);  // 0x80009BB8 (924B)
    bool IsSingleButton(unsigned short);  // 0x80009FC0 (168B)
    void PurgeBtnMemory(void);  // 0x8000A068 (112B)
    void CreateBtnMask(void);  // 0x8000A0D8 (132B)
    /* ? */ GetNextIndex(int &);  // 0x80009F54 (108B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0x10];  // 0x000
    f32 m_field_010;  // 0x010 [R/W] (Capture)
    u32 m_field_014;  // 0x014 [R] (Capture)
    u32 m_field_018;  // 0x018 [R/W] (Capture)
};

#endif // PLAYERCHEATS_H
