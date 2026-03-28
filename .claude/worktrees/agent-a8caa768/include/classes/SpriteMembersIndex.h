#ifndef SPRITEMEMBERSINDEX_H
#define SPRITEMEMBERSINDEX_H

#include "types.h"

// SpriteMembersIndex - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8 (8 bytes)
// 4 known fields (0 named), 3 methods

class SpriteMembersIndex {
public:
    // Methods
    void in_word_set(char *, unsigned int);  // 0x806FC864 (220B)
    void hash(char *, unsigned int);  // 0x806FC940 (320B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_field_000;  // 0x000 [R] (in_word_set)
    u8 m_field_001;  // 0x001 [R] (in_word_set)
    u8 _pad_002[3];  // 0x002
    u8 m_field_005;  // 0x005 [R] (in_word_set)
    u8 _pad_006[1];  // 0x006
    u8 m_field_007;  // 0x007 [R] (in_word_set)
};

#endif // SPRITEMEMBERSINDEX_H
