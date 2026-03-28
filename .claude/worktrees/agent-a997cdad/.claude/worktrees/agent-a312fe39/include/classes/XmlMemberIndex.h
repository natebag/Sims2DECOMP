#ifndef XMLMEMBERINDEX_H
#define XMLMEMBERINDEX_H

#include "types.h"

// XmlMemberIndex - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8 (8 bytes)
// 4 known fields (0 named), 3 methods

class XmlMemberIndex {
public:
    // Methods
    void in_word_set(char *, unsigned int);  // 0x8071F308 (220B)
    void hash(char *, unsigned int);  // 0x8071F3E4 (288B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_field_000;  // 0x000 [R] (in_word_set)
    u8 m_field_001;  // 0x001 [R] (in_word_set)
    u8 _pad_002[3];  // 0x002
    u8 m_field_005;  // 0x005 [R] (in_word_set)
    u8 _pad_006[1];  // 0x006
    u8 m_field_007;  // 0x007 [R] (in_word_set)
};

#endif // XMLMEMBERINDEX_H
