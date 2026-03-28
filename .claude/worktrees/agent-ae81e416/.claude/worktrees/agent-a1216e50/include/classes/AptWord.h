#ifndef APTWORD_H
#define APTWORD_H

#include "types.h"

// AptWord - struct layout extracted from assembly analysis
// Estimated minimum size: 0x30 (48 bytes)
// 8 known fields (5 named), 18 methods

class AptWord {
public:
    // Constructors / Destructors
    AptWord(void)  // 0x80022970
    ~AptWord(void);  // 0x80022A64

    // Methods
    void Draw(ERC *, EMat4 *, EVec4 *, EVec4 *);  // 0x8001CEA0 (1832B)
    void SetWord(unsigned wchar_t *, int, EVec2 &);  // 0x8001D5C8 (376B)
    void Resize(float);  // 0x8001D740 (216B)
    void InsertSpace(void);  // 0x8001D818 (552B)
    void AddSpace(void);  // 0x8001DA40 (44B)
    void AddLineFeed(void);  // 0x8001DA6C (44B)
    void ForceFormat(AptWord *);  // 0x8001DA98 (204B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_word;  // 0x008 [R/W] (Draw, InsertSpace, Resize, ...)
    u32 m_field_00C;  // 0x00C [R/W] (Draw, ForceFormat, InsertSpace, ...)
    u32 m_field_010;  // 0x010 [R/W] (Draw, ForceFormat, InsertSpace, ...)
    u8 _pad_014[8];  // 0x014
    f32 m_word_01C;  // 0x01C [R/W] (Draw, SetWord)
    f32 m_word_020;  // 0x020 [R/W] (Draw, SetWord)
    u32 m_word_024;  // 0x024 [W] (InsertSpace, Resize, SetWord)
    u32 m_word_028;  // 0x028 [W] (InsertSpace, Resize, SetWord)
    u32 m_field_02C;  // 0x02C [W] (~AptWord)
};

#endif // APTWORD_H
