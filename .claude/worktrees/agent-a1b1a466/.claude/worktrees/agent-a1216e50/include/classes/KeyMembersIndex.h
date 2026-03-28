#ifndef KEYMEMBERSINDEX_H
#define KEYMEMBERSINDEX_H

#include "types.h"

// KeyMembersIndex - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8 (8 bytes)
// 4 known fields (0 named), 3 methods

class KeyMembersIndex {
public:
    // Methods
    void in_word_set(char *, unsigned int);  // 0x806F01E0 (276B)
    void hash(char *, unsigned int);  // 0x806F5D8C (288B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_field_000;  // 0x000 [R] (in_word_set)
    u8 m_field_001;  // 0x001 [R] (in_word_set)
    u8 _pad_002[1];  // 0x002
    u8 m_field_003;  // 0x003 [R] (in_word_set)
    u8 _pad_004[3];  // 0x004
    u8 m_field_007;  // 0x007 [R] (in_word_set)
};

#endif // KEYMEMBERSINDEX_H
