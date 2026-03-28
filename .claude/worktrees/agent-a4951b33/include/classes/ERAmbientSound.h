#ifndef ERAMBIENTSOUND_H
#define ERAMBIENTSOUND_H

#include "types.h"

// ERAmbientSound - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 15 known fields (1 named), 9 methods

class ERAmbientSound {
public:
    // Constructors / Destructors
    ERAmbientSound(void)  // 0x80832CD8
    ERAmbientSound(ERAmbientSound &)  // 0x80834BFC
    ~ERAmbientSound(void);  // 0x80832DD0

    // Methods
    void Load(EFile *);  // 0x80832E30 (1408B)
    void operator=(ERAmbientSound &);  // 0x808356CC (228B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (ERAmbientSound)
    u32 m_field_004;  // 0x004 [R/W] (ERAmbientSound, Load)
    u32 m_field_008;  // 0x008 [W] (ERAmbientSound)
    u32 m_field_00C;  // 0x00C [W] (ERAmbientSound)
    u8 _pad_010[8];  // 0x010
    u8 m_field_018;  // 0x018 [W] (ERAmbientSound)
    u8 m_field_019;  // 0x019 [W] (ERAmbientSound)
    u8 m_field_01A;  // 0x01A [W] (ERAmbientSound)
    u8 m_field_01B;  // 0x01B [W] (ERAmbientSound)
    u8 m_field_01C;  // 0x01C [W] (ERAmbientSound)
    u8 m_field_01D;  // 0x01D [W] (ERAmbientSound)
    u8 m_field_01E;  // 0x01E [W] (ERAmbientSound)
    u8 m_field_01F;  // 0x01F [W] (ERAmbientSound)
    u8 m_field_020;  // 0x020 [W] (ERAmbientSound)
    u8 m_field_021;  // 0x021 [W] (ERAmbientSound)
    u8 _pad_022[2];  // 0x022
    u32 m_field_024;  // 0x024 [R/W] (ERAmbientSound, Load, ~ERAmbientSound)
};

#endif // ERAMBIENTSOUND_H
