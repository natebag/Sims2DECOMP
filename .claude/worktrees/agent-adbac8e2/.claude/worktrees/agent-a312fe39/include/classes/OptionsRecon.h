#ifndef OPTIONSRECON_H
#define OPTIONSRECON_H

#include "types.h"

// OptionsRecon - struct layout extracted from assembly analysis
// Estimated minimum size: 0xF4 (244 bytes)
// 34 known fields (1 named), 27 methods

class OptionsRecon {
public:
    // Constructors / Destructors
    OptionsRecon(void)  // 0x80117754
    OptionsRecon(OptionsRecon &)  // 0x801177AC

    // Methods
    void ResetToDefaults(void);  // 0x8011780C (184B)
    void operator=(OptionsRecon &);  // 0x8011875C (380B)
    void DoStream(ReconBuffer *, int);  // 0x801178C4 (924B)
    void WriteOut(void);  // 0x80117C60 (388B)
    void WriteToMemoryCard(char *, unsigned char);  // 0x80117DE4 (156B)
    void ReadIn(int);  // 0x80117E80 (448B)
    void ReadFromMemoryCard(char *, unsigned char);  // 0x80118040 (156B)
    void PreservePreferences(void);  // 0x801180DC (156B)
    void PreservePrefsForOnline(void);  // 0x80118178 (52B)
    void RestorePreferences(void);  // 0x801181AC (280B)
    void RestorePrefsForOnline(void);  // 0x801182C4 (176B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (PreservePreferences, ReadIn, RestorePreferences, ...)
    u32 m_field_004;  // 0x004 [R/W] (PreservePreferences, ReadIn, RestorePreferences, ...)
    u32 m_field_008;  // 0x008 [R/W] (PreservePreferences, RestorePreferences, WriteOut, ...)
    u32 m_field_00C;  // 0x00C [W] (operator=)
    u32 m_field_010;  // 0x010 [R/W] (PreservePreferences, RestorePreferences, operator=)
    u32 m_field_014;  // 0x014 [R/W] (PreservePreferences, RestorePreferences, operator=)
    u32 m_field_018;  // 0x018 [R/W] (PreservePreferences, RestorePreferences, operator=)
    u8 m_field_01C;  // 0x01C [R/W] (DoStream, PreservePreferences, RestorePreferences, ...)
    u8 m_field_01D;  // 0x01D [R/W] (DoStream, PreservePreferences, RestorePreferences, ...)
    u8 m_field_01E;  // 0x01E [R/W] (DoStream, PreservePreferences, RestorePreferences, ...)
    u8 m_field_01F;  // 0x01F [R/W] (PreservePreferences, RestorePreferences, operator=)
    u8 m_field_020;  // 0x020 [R/W] (PreservePreferences, ReadIn, RestorePreferences, ...)
    u8 _pad_021[3];  // 0x021
    u32 m_field_024;  // 0x024 [R/W] (PreservePreferences, RestorePreferences, operator=)
    u8 m_field_028;  // 0x028 [R/W] (DoStream, PreservePreferences, RestorePreferences, ...)
    u8 m_field_029;  // 0x029 [R/W] (DoStream, PreservePreferences, RestorePreferences, ...)
    u8 _pad_02A[2];  // 0x02A
    u32 m_field_02C;  // 0x02C [R/W] (PreservePreferences, RestorePreferences, operator=)
    u32 m_field_030;  // 0x030 [R/W] (PreservePreferences, RestorePreferences, operator=)
    u32 m_field_034;  // 0x034 [R/W] (PreservePreferences, RestorePreferences, operator=)
    u32 m_field_038;  // 0x038 [R/W] (PreservePreferences, RestorePreferences, operator=)
    u32 m_field_03C;  // 0x03C [R/W] (PreservePreferences, RestorePreferences, operator=)
    u32 m_field_040;  // 0x040 [R/W] (PreservePreferences, RestorePreferences, operator=)
    u32 m_field_044;  // 0x044 [R/W] (PreservePreferences, RestorePreferences, operator=)
    u8 m_field_048;  // 0x048 [R/W] (PreservePreferences, RestorePreferences, operator=)
    u8 m_field_049;  // 0x049 [R/W] (PreservePreferences, RestorePreferences, operator=)
    u8 m_field_04A;  // 0x04A [R/W] (PreservePreferences, RestorePreferences, operator=)
    u8 m_field_04B;  // 0x04B [R/W] (PreservePreferences, RestorePreferences, operator=)
    u8 m_field_04C;  // 0x04C [R/W] (PreservePreferences, RestorePreferences, operator=)
    u8 m_field_04D;  // 0x04D [R/W] (PreservePreferences, RestorePreferences, operator=)
    u8 m_field_04E;  // 0x04E [R/W] (PreservePreferences, RestorePreferences, operator=)
    u8 _pad_04F[1];  // 0x04F
    u32 m_field_050;  // 0x050 [W] (operator=)
    u8 m_field_054;  // 0x054 [W] (operator=)
    u8 _pad_055[0x93];  // 0x055
    u32 m_field_0E8;  // 0x0E8 [W] (operator=)
    u32 m_field_0EC;  // 0x0EC [W] (operator=)
    u32 m_field_0F0;  // 0x0F0 [W] (operator=)
};

#endif // OPTIONSRECON_H
