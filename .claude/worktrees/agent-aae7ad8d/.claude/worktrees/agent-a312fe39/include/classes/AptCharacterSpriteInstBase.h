#ifndef APTCHARACTERSPRITEINSTBASE_H
#define APTCHARACTERSPRITEINSTBASE_H

#include "types.h"

// AptCharacterSpriteInstBase - struct layout extracted from assembly analysis
// Estimated minimum size: 0x30 (48 bytes)
// 10 known fields (1 named), 12 methods

class AptCharacterSpriteInstBase {
public:
    // Constructors / Destructors
    AptCharacterSpriteInstBase(void)  // 0x806C9E58
    ~AptCharacterSpriteInstBase(void);  // 0x806C9FB0

    // Methods
    void PreDestroy(void);  // 0x806CA030 (60B)
    void SetClipAction(int);  // 0x806D22F0 (60B)
    void RemoveClipAction(int);  // 0x806D232C (64B)
    bool HasClipAction(int);  // 0x806D236C (56B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (AptCharacterSpriteInstBase)
    u8 _pad_004[4];  // 0x004
    u32 m_field_008;  // 0x008 [R/W] (AptCharacterSpriteInstBase, ~AptCharacterSpriteInstBase)
    u32 m_field_00C;  // 0x00C [R/W] (AptCharacterSpriteInstBase, ~AptCharacterSpriteInstBase)
    u32 m_field_010;  // 0x010 [W] (AptCharacterSpriteInstBase)
    u32 m_field_014;  // 0x014 [W] (AptCharacterSpriteInstBase, ~AptCharacterSpriteInstBase)
    u32 m_field_018;  // 0x018 [W] (AptCharacterSpriteInstBase)
    u32 m_field_01C;  // 0x01C [R/W] (AptCharacterSpriteInstBase)
    u32 m_field_020;  // 0x020 [W] (AptCharacterSpriteInstBase)
    u8 _pad_024[4];  // 0x024
    u32 m_field_028;  // 0x028 [W] (AptCharacterSpriteInstBase)
    u32 m_field_02C;  // 0x02C [R/W] (AptCharacterSpriteInstBase, ~AptCharacterSpriteInstBase)
};

#endif // APTCHARACTERSPRITEINSTBASE_H
