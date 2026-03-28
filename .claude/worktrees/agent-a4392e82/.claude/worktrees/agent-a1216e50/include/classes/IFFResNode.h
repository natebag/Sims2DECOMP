#ifndef IFFRESNODE_H
#define IFFRESNODE_H

#include "types.h"

// IFFResNode - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 4 known fields (0 named), 5 methods

class IFFResNode {
public:
    // Constructors / Destructors
    IFFResNode(void)  // 0x80258BBC
    IFFResNode(IFFResNode &)  // 0x80258A7C

    // Methods
    void DoStream(ReconBuffer *, int);  // 0x80250318 (176B)
    void operator=(IFFResNode &);  // 0x80258AF4 (124B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[4];  // 0x000
    u32 m_field_004;  // 0x004 [W] (DoStream)
    s16 m_field_006;  // 0x006 [R] (DoStream)
    u16 m_field_008;  // 0x008 [W] (DoStream)
    u16 m_field_00A;  // 0x00A [R] (DoStream)
};

#endif // IFFRESNODE_H
