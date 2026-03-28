#ifndef ESTREAM_H
#define ESTREAM_H

#include "types.h"

// EStream - struct layout extracted from assembly analysis
// Estimated minimum size: 0x48 (72 bytes)
// 13 known fields (0 named), 20 methods

class EStream {
public:
    // Constructors / Destructors
    EStream(void)  // 0x8076C354
    ~EStream(void);  // 0x8076C390

    // Methods
    void WriteStructure(EStorable &);  // 0x80769D3C (2784B)
    bool IsStreamingStructure(void);  // 0x8076C448 (44B)
    void ReadStructure(unsigned int);  // 0x8076A81C (1040B)
    void ReadString(char *, int);  // 0x8076AE34 (332B)
    void WriteString(char *);  // 0x8076AF80 (264B)
    /* ? */ GetFile(void);  // 0x8076B088 (40B)
    void ReadU16String(unsigned short *, int);  // 0x8076B0B0 (236B)
    void WriteU16String(unsigned short *);  // 0x8076B19C (280B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_field_000;  // 0x000 [R/W] (ReadStructure, WriteStructure)
    u8 _pad_001[3];  // 0x001
    u32 m_field_004;  // 0x004 [R/W] (WriteStructure)
    u32 m_field_008;  // 0x008 [R/W] (WriteStructure)
    u8 _pad_00C[4];  // 0x00C
    s16 m_field_010;  // 0x010 [R/W] (WriteStructure)
    u8 _pad_012[2];  // 0x012
    u32 m_field_014;  // 0x014 [R/W] (ReadStructure, WriteStructure)
    u16 m_field_016;  // 0x016 [W] (ReadStructure)
    u32 m_field_018;  // 0x018 [R] (ReadString, ReadStructure, ReadU16String, ...)
    u8 _pad_01C[0xC];  // 0x01C
    s16 m_field_028;  // 0x028 [R] (WriteStructure)
    u8 _pad_02A[2];  // 0x02A
    u32 m_field_02C;  // 0x02C [R] (WriteStructure)
    u8 _pad_030[8];  // 0x030
    s16 m_field_038;  // 0x038 [R] (WriteStructure)
    u8 _pad_03A[2];  // 0x03A
    u32 m_field_03C;  // 0x03C [R] (WriteStructure)
    s16 m_field_040;  // 0x040 [R] (WriteStructure)
    u8 _pad_042[2];  // 0x042
    u32 m_field_044;  // 0x044 [R] (WriteStructure)
};

#endif // ESTREAM_H
