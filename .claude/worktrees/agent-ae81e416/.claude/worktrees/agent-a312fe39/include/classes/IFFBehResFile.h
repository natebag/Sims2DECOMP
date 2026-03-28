#ifndef IFFBEHRESFILE_H
#define IFFBEHRESFILE_H

#include "types.h"

// IFFBehResFile - struct layout extracted from assembly analysis
// Estimated minimum size: 0x148 (328 bytes)
// 9 known fields (1 named), 9 methods

class IFFBehResFile {
public:
    // Constructors / Destructors
    IFFBehResFile(void)  // 0x803B1824
    ~IFFBehResFile(void);  // 0x802585C4

    // Methods
    void Open(StringBuffer &);  // 0x80255F90 (2028B)
    void RefreshBufferWithBehavior(void);  // 0x80256878 (1576B)
    void IFFNodeSize(unsigned short, unsigned int);  // 0x8025677C (252B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (IFFNodeSize, Open, RefreshBufferWithBehavior)
    u32 m_field_004;  // 0x004 [W] (Open)
    u16 m_field_008;  // 0x008 [W] (Open)
    u16 m_field_00A;  // 0x00A [W] (Open)
    u32 m_field_00C;  // 0x00C [R/W] (Open, RefreshBufferWithBehavior)
    u32 m_field_010;  // 0x010 [W] (Open)
    u8 _pad_014[0x124];  // 0x014
    u32 m_field_138;  // 0x138 [R/W] (IFFNodeSize, Open, RefreshBufferWithBehavior)
    u8 _pad_13C[4];  // 0x13C
    u32 m_field_140;  // 0x140 [W] (Open)
    u32 m_field_144;  // 0x144 [W] (Open)
};

#endif // IFFBEHRESFILE_H
