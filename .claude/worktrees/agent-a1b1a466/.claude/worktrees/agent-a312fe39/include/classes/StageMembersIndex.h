#ifndef STAGEMEMBERSINDEX_H
#define STAGEMEMBERSINDEX_H

#include "types.h"

// StageMembersIndex - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8 (8 bytes)
// 4 known fields (0 named), 3 methods

class StageMembersIndex {
public:
    // Methods
    void in_word_set(char *, unsigned int);  // 0x806FCA80 (272B)
    void hash(char *, unsigned int);  // 0x806FCB90 (288B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_field_000;  // 0x000 [R] (in_word_set)
    u8 m_field_001;  // 0x001 [R] (in_word_set)
    u8 _pad_002[1];  // 0x002
    u8 m_field_003;  // 0x003 [R] (in_word_set)
    u8 _pad_004[3];  // 0x004
    u8 m_field_007;  // 0x007 [R] (in_word_set)
};

#endif // STAGEMEMBERSINDEX_H
