#ifndef EMEMORYBUFFERWRITESTREAM_H
#define EMEMORYBUFFERWRITESTREAM_H

#include "types.h"

// EMemoryBufferWriteStream - struct layout extracted from assembly analysis
// Estimated minimum size: 0x24 (36 bytes)
// 3 known fields (0 named), 10 methods

class EMemoryBufferWriteStream {
public:
    // Constructors / Destructors
    EMemoryBufferWriteStream(void *)  // 0x80797498
    ~EMemoryBufferWriteStream(void);  // 0x80797218

    // Methods
    void Write(void *, int);  // 0x80795EE4 (384B)
    /* ? */ GetPos(void);  // 0x807974F4 (44B)
    void Read(void *, int);  // 0x80797520 (148B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_field_000;  // 0x000 [W] (Write)
    u8 _pad_001[0x1B];  // 0x001
    u32 m_field_01C;  // 0x01C [R] (Write)
    u32 m_field_020;  // 0x020 [R/W] (Write)
};

#endif // EMEMORYBUFFERWRITESTREAM_H
