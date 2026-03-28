#ifndef APTCHARACTERTEXTINST_H
#define APTCHARACTERTEXTINST_H

#include "types.h"

// AptCharacterTextInst - struct layout extracted from assembly analysis
// Estimated minimum size: 0x78 (120 bytes)
// 15 known fields (8 named), 8 methods

class AptCharacterTextInst {
public:
    // Constructors / Destructors
    AptCharacterTextInst(void)  // 0x806CA4F4
    ~AptCharacterTextInst(void);  // 0x806CA5EC

    // Methods
    void SetText(AptCIH *);  // 0x806CA06C (552B)
    void UpdateText(AptCIH *);  // 0x806CA294 (608B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (SetText, UpdateText)
    u16 m_text_002;  // 0x002 [R] (UpdateText)
    u8 _pad_004[4];  // 0x004
    u32 m_text_008;  // 0x008 [R] (SetText, UpdateText, ~AptCharacterTextInst)
    u32 m_text_00C;  // 0x00C [R/W] (SetText, ~AptCharacterTextInst)
    u32 m_text_010;  // 0x010 [R] (SetText)
    u32 m_field_014;  // 0x014 [W] (~AptCharacterTextInst)
    u32 m_text_018;  // 0x018 [R/W] (SetText, UpdateText, ~AptCharacterTextInst)
    u32 m_text_01C;  // 0x01C [R] (SetText, UpdateText, ~AptCharacterTextInst)
    u32 m_field_020;  // 0x020 [R/W] (~AptCharacterTextInst)
    u32 m_field_024;  // 0x024 [W] (~AptCharacterTextInst)
    u8 _pad_028[0x38];  // 0x028
    f32 m_field_060;  // 0x060 [W] (~AptCharacterTextInst)
    u32 m_field_064;  // 0x064 [W] (~AptCharacterTextInst)
    u32 m_field_068;  // 0x068 [R/W] (~AptCharacterTextInst)
    u32 m_text_06C;  // 0x06C [R/W] (UpdateText)
    u8 _pad_070[4];  // 0x070
    u32 m_field_074;  // 0x074 [R] (~AptCharacterTextInst)
};

#endif // APTCHARACTERTEXTINST_H
