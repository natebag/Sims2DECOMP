#ifndef OBJRESFILE_H
#define OBJRESFILE_H

#include "types.h"

// ObjResFile - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 2 known fields (0 named), 8 methods

class ObjResFile {
public:
    // Constructors / Destructors
    ObjResFile(void)  // 0x8032E3EC
    ~ObjResFile(void);  // 0x8032E4BC

    // Methods
    void Open(StringBuffer &);  // 0x8032E544 (156B)
    void _dyncastimpl(SCID);  // 0x8032E780 (92B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (Open)
    u8 _pad_004[8];  // 0x004
    u32 m_field_00C;  // 0x00C [W] (ObjResFile, ~ObjResFile)
};

#endif // OBJRESFILE_H
