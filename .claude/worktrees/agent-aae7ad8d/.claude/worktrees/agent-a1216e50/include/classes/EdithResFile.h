#ifndef EDITHRESFILE_H
#define EDITHRESFILE_H

#include "types.h"

// EdithResFile - struct layout extracted from assembly analysis
// Estimated minimum size: 0xD4 (212 bytes)
// 2 known fields (0 named), 6 methods

class EdithResFile {
public:
    // Constructors / Destructors
    EdithResFile(void)  // 0x803C6A40
    ~EdithResFile(void);  // 0x803C6C84

    // Methods
    void Open(StringBuffer &);  // 0x803C6AA8 (104B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0xC];  // 0x000
    u32 m_field_00C;  // 0x00C [W] (EdithResFile)
    u8 _pad_010[0xC0];  // 0x010
    u32 m_field_0D0;  // 0x0D0 [W] (EdithResFile)
};

#endif // EDITHRESFILE_H
