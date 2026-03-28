#ifndef TEXTFORMATMEMBERSINDEX_H
#define TEXTFORMATMEMBERSINDEX_H

#include "types.h"

// TextFormatMembersIndex - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8 (8 bytes)
// 3 known fields (0 named), 3 methods

class TextFormatMembersIndex {
public:
    // Methods
    void in_word_set(char *, unsigned int);  // 0x806FFA68 (220B)
    void hash(char *, unsigned int);  // 0x80700A18 (288B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_field_000;  // 0x000 [R] (in_word_set)
    u8 _pad_001[4];  // 0x001
    u8 m_field_005;  // 0x005 [R] (in_word_set)
    u8 _pad_006[1];  // 0x006
    u8 m_field_007;  // 0x007 [R] (in_word_set)
};

#endif // TEXTFORMATMEMBERSINDEX_H
