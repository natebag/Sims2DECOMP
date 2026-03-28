#ifndef RECONBUFFER_H
#define RECONBUFFER_H

#include "types.h"

// ReconBuffer - struct layout extracted from assembly analysis
// Estimated minimum size: 0xA2 (162 bytes)
// 19 known fields (0 named), 45 methods

class ReconBuffer {
public:
    // Constructors / Destructors
    ReconBuffer(void *, int, ReconBuffer::Mode, bool)  // 0x8039349C
    ReconBuffer(void)  // 0x803935C4
    ~ReconBuffer(void);  // 0x8039364C

    // Methods
    bool IsReading(void);  // 0x8005DFA4 (56B)
    /* ? */ GetPosition(void);  // 0x800E1B68 (44B)
    /* ? */ GetMode(void);  // 0x800E1B3C (44B)
    bool IsWriting(void);  // 0x80278744 (56B)
    bool IsCounting(void);  // 0x8028DFCC (56B)
    void Recon32(int *, int);  // 0x80394508 (1016B)
    void Recon16(short *, int);  // 0x803940E8 (876B)
    void ReconString(BString &);  // 0x80395228 (588B)
    void ReconInt(int *, int);  // 0x80394454 (180B)
    void ReconBool(bool *);  // 0x80394074 (116B)
    void EnableCompression(void);  // 0x80393880 (40B)
    void Recon8(signed char *, int);  // 0x80393DA0 (724B)
    void ReconString(StringBuffer2 &);  // 0x80395B78 (1024B)
    void ReconFloat(float *, int);  // 0x80394900 (1128B)
    void ReconString(BString2 &);  // 0x80395474 (1236B)
    void ReconString(StringBuffer &);  // 0x80395948 (560B)
    void ReconMark(void);  // 0x80394D68 (768B)
    void ReadToNextMark(void);  // 0x80395068 (448B)
    void UseStringTable(unsigned int, unsigned int, short);  // 0x80393700 (384B)
    void ReconCmprInt(int *, Scheme *);  // 0x803938A8 (364B)
    void ReconBits(int, int *);  // 0x80393A14 (868B)
    void PadBits(void);  // 0x80393D78 (40B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_field_000;  // 0x000 [R/W] (Recon16, Recon32, Recon8, ...)
    u8 m_field_001;  // 0x001 [W] (ReconMark)
    u8 _pad_002[2];  // 0x002
    u32 m_field_004;  // 0x004 [R] (ReconString)
    u8 m_field_008;  // 0x008 [R/W] (ReadToNextMark, Recon16, Recon32, ...)
    u8 m_field_009;  // 0x009 [R] (ReconMark)
    u8 m_field_00A;  // 0x00A [R] (ReconMark)
    u8 m_field_00B;  // 0x00B [R] (ReconMark)
    u32 m_field_00C;  // 0x00C [R] (ReadToNextMark, Recon16, Recon32, ...)
    u32 m_field_010;  // 0x010 [R] (Recon16, Recon32, ReconFloat, ...)
    u32 m_field_014;  // 0x014 [R/W] (ReconString, UseStringTable)
    u32 m_field_018;  // 0x018 [R] (ReadToNextMark, Recon16, Recon32, ...)
    u32 m_field_01C;  // 0x01C [R/W] (ReconString, UseStringTable, ~ReconBuffer)
    u32 m_field_020;  // 0x020 [R/W] (ReconString)
    u8 _pad_024[4];  // 0x024
    u32 m_field_028;  // 0x028 [R/W] (ReconBits)
    u8 m_field_02C;  // 0x02C [R/W] (ReadToNextMark, ReconMark)
    u8 m_field_02D;  // 0x02D [W] (ReconMark)
    u8 m_field_02E;  // 0x02E [W] (ReconMark)
    u8 m_field_02F;  // 0x02F [W] (ReconMark)
    u8 _pad_030[0x70];  // 0x030
    s16 m_field_0A0;  // 0x0A0 [R] (ReconString)
};

#endif // RECONBUFFER_H
