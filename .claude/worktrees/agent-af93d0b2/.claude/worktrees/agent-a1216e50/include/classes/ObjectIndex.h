#ifndef OBJECTINDEX_H
#define OBJECTINDEX_H

#include "types.h"

// ObjectIndex - struct layout extracted from assembly analysis
// Estimated minimum size: 0x7 (7 bytes)
// 3 known fields (0 named), 3 methods

class ObjectIndex {
public:
    // Methods
    void in_word_set(char *, unsigned int);  // 0x80700F8C (424B)
    void hash(char *, unsigned int);  // 0x80708928 (288B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_field_000;  // 0x000 [R] (in_word_set)
    u8 _pad_001[3];  // 0x001
    u8 m_field_004;  // 0x004 [R] (in_word_set)
    u8 _pad_005[1];  // 0x005
    u8 m_field_006;  // 0x006 [R] (in_word_set)
};

#endif // OBJECTINDEX_H
