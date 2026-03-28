#ifndef TGA_INFO_H
#define TGA_INFO_H

#include "types.h"

// TGA_INFO - struct layout extracted from assembly analysis
// Estimated minimum size: 0x14 (20 bytes)
// 12 known fields (0 named), 6 methods

class TGA_INFO {
public:
    // Constructors / Destructors
    TGA_INFO(void)  // 0x8044350C
    ~TGA_INFO(void);  // 0x804434C0

    // Methods
    void WriteHeaderToBuffer(void *);  // 0x8082B468 (372B)
    void WriteFooterToBuffer(void *);  // 0x8082B5DC (184B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_field_000;  // 0x000 [R] (WriteHeaderToBuffer)
    u8 m_field_001;  // 0x001 [R] (WriteHeaderToBuffer)
    u8 m_field_002;  // 0x002 [R] (WriteHeaderToBuffer)
    u8 _pad_003[1];  // 0x003
    u16 m_field_004;  // 0x004 [R] (WriteHeaderToBuffer)
    u16 m_field_006;  // 0x006 [R] (WriteHeaderToBuffer)
    u8 m_field_008;  // 0x008 [R] (WriteHeaderToBuffer)
    u8 _pad_009[1];  // 0x009
    u16 m_field_00A;  // 0x00A [R] (WriteHeaderToBuffer)
    u16 m_field_00C;  // 0x00C [R] (WriteHeaderToBuffer)
    u16 m_field_00E;  // 0x00E [R] (WriteHeaderToBuffer)
    u16 m_field_010;  // 0x010 [R] (WriteHeaderToBuffer)
    u8 m_field_012;  // 0x012 [R] (WriteHeaderToBuffer)
    u8 m_field_013;  // 0x013 [R] (WriteHeaderToBuffer)
};

#endif // TGA_INFO_H
