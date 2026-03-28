#ifndef TEXTMEMBERSINDEX_H
#define TEXTMEMBERSINDEX_H

#include "types.h"

// TextMembersIndex - struct layout extracted from assembly analysis
// Estimated minimum size: 0x9 (9 bytes)
// 3 known fields (0 named), 3 methods

class TextMembersIndex {
public:
    // Methods
    void in_word_set(char *, unsigned int);  // 0x806C9B24 (220B)
    void hash(char *, unsigned int);  // 0x806D2514 (288B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_field_000;  // 0x000 [R] (in_word_set)
    u8 m_field_001;  // 0x001 [R] (in_word_set)
    u8 _pad_002[6];  // 0x002
    u8 m_field_008;  // 0x008 [R] (in_word_set)
};

#endif // TEXTMEMBERSINDEX_H
