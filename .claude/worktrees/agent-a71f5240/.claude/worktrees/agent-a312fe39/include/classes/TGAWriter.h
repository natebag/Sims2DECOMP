#ifndef TGAWRITER_H
#define TGAWRITER_H

#include "types.h"

// TGAWriter - struct layout extracted from assembly analysis
// Estimated minimum size: 0x2C (44 bytes)
// 9 known fields (0 named), 16 methods

class TGAWriter {
public:
    // Constructors / Destructors
    TGAWriter(void)  // 0x80443378
    ~TGAWriter(void);  // 0x80443310

    // Methods
    void Write(char *, ETexture *, bool, bool, TDF_INFO *);  // 0x8082B724 (564B)
    void Init(char *, void *, void *, ETextureDef &);  // 0x8082B3EC (124B)
    void Write(void);  // 0x8082B694 (144B)
    void WriteTGA(void);  // 0x8082B958 (756B)
    void WriteTDF(TDF_INFO *);  // 0x8082BC4C (3072B)
    void WriteSDF(void);  // 0x8082C84C (1032B)
    void WriteFile(char *, void *, unsigned int);  // 0x8082CC54 (396B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (WriteSDF, WriteTDF, WriteTGA)
    u8 _pad_004[6];  // 0x004
    u16 m_field_00A;  // 0x00A [R] (WriteTGA)
    u8 m_field_00C;  // 0x00C [R] (WriteTGA)
    u8 _pad_00D[5];  // 0x00D
    u16 m_field_012;  // 0x012 [R/W] (Init, WriteTDF, WriteTGA)
    u16 m_field_014;  // 0x014 [R/W] (Init, WriteTDF, WriteTGA)
    u8 m_field_016;  // 0x016 [R] (WriteTGA)
    u8 _pad_017[1];  // 0x017
    u32 m_field_018;  // 0x018 [R/W] (Init, WriteTGA)
    u32 m_field_01C;  // 0x01C [R/W] (Init, WriteTGA)
    u8 _pad_020[8];  // 0x020
    u32 m_field_028;  // 0x028 [R] (WriteFile)
};

#endif // TGAWRITER_H
