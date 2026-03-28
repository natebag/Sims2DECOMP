#ifndef STDRESFILE_H
#define STDRESFILE_H

#include "types.h"

// StdResFile - struct layout extracted from assembly analysis
// Estimated minimum size: 0xD4 (212 bytes)
// 2 known fields (0 named), 8 methods

class StdResFile {
public:
    // Constructors / Destructors
    StdResFile(void)  // 0x803C66C8
    ~StdResFile(void);  // 0x803C6C44

    // Methods
    void Open(StringBuffer &);  // 0x803C6798 (680B)
    void _dyncastimpl(SCID);  // 0x803C6D04 (92B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0xC];  // 0x000
    u32 m_field_00C;  // 0x00C [R/W] (Open, StdResFile)
    u8 _pad_010[0xC0];  // 0x010
    u32 m_field_0D0;  // 0x0D0 [W] (StdResFile)
};

#endif // STDRESFILE_H
