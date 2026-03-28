#ifndef EMEMORYREADSTREAM_H
#define EMEMORYREADSTREAM_H

#include "types.h"

// EMemoryReadStream - struct layout extracted from assembly analysis
// Estimated minimum size: 0x24 (36 bytes)
// 2 known fields (0 named), 10 methods

class EMemoryReadStream {
public:
    // Constructors / Destructors
    EMemoryReadStream(void *)  // 0x8079737C
    ~EMemoryReadStream(void);  // 0x807971D8

    // Methods
    void Read(void *, int);  // 0x80795D50 (404B)
    /* ? */ GetPos(void);  // 0x807973D8 (44B)
    void Write(void *, int);  // 0x80797404 (148B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0x1C];  // 0x000
    u32 m_field_01C;  // 0x01C [R] (Read)
    u32 m_field_020;  // 0x020 [R/W] (Read)
};

#endif // EMEMORYREADSTREAM_H
