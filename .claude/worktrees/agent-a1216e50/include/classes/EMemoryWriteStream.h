#ifndef EMEMORYWRITESTREAM_H
#define EMEMORYWRITESTREAM_H

#include "types.h"

// EMemoryWriteStream - struct layout extracted from assembly analysis
// Estimated minimum size: 0x24 (36 bytes)
// 4 known fields (0 named), 20 methods

class EMemoryWriteStream {
public:
    // Constructors / Destructors
    EMemoryWriteStream(void)  // 0x80796064
    ~EMemoryWriteStream(void);  // 0x807960C4

    // Methods
    void AllocAndCopyToBuffer(void);  // 0x807966EC (176B)
    void FreeBuffer(void *);  // 0x8079679C (68B)
    /* ? */ GetPos(void);  // 0x807975B4 (44B)
    void operator[](int);  // 0x807965F4 (248B)
    void WriteToStream(EStream &, int, int);  // 0x807967E0 (284B)
    void Write(void *, int);  // 0x8079612C (968B)
    void Read(void *, int);  // 0x807975E0 (148B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_field_000;  // 0x000 [W] (EMemoryWriteStream, Write)
    u8 _pad_001[0x17];  // 0x001
    u32 m_field_018;  // 0x018 [W] (EMemoryWriteStream, ~EMemoryWriteStream)
    u32 m_field_01C;  // 0x01C [R/W] (AllocAndCopyToBuffer, EMemoryWriteStream, Write)
    u32 m_field_020;  // 0x020 [R] (Write, WriteToStream)
};

#endif // EMEMORYWRITESTREAM_H
