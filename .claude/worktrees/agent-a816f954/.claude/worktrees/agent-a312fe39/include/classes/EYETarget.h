#ifndef EYETARGET_H
#define EYETARGET_H

#include "types.h"

// EYETarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0xD8 (216 bytes)
// 37 known fields (3 named), 24 methods

class EYETarget {
public:
    // Constructors / Destructors
    EYETarget(int)  // 0x805670CC
    ~EYETarget(void);  // 0x805686D0

    // Methods
    void EyeToyUnplugCallback(int);  // 0x80566E38 (64B)
    void SaveCurrentSetting(void);  // 0x80566EDC (296B)
    void RestorePreviousSetting(void);  // 0x80567004 (200B)
    void RenderCallback(ERC *, structDrawCBparams *);  // 0x80568E44 (1172B)
    void AddSetVar(SetVar *);  // 0x80568648 (68B)
    void AddGetVar(GetVar *);  // 0x8056868C (68B)
    void SetVariable(char *, char *);  // 0x80568AC4 (348B)
    /* ? */ GetVariable(char *);  // 0x80568C20 (460B)
    void Update(void);  // 0x80568DEC (88B)
    void SetState(EYETarget::eState);  // 0x8059398C (40B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_variable;  // 0x000 [R/W] (EYETarget, GetVariable, ~EYETarget)
    u8 _pad_001[3];  // 0x001
    f32 m_field_004;  // 0x004 [R/W] (EYETarget, RenderCallback, ~EYETarget)
    u32 m_field_008;  // 0x008 [R/W] (EYETarget, ~EYETarget)
    u32 m_field_00C;  // 0x00C [R/W] (EYETarget, ~EYETarget)
    u16 m_field_010;  // 0x010 [R/W] (EYETarget, ~EYETarget)
    u16 m_field_012;  // 0x012 [R] (EYETarget)
    u32 m_field_014;  // 0x014 [R/W] (EYETarget, ~EYETarget)
    u32 m_field_018;  // 0x018 [R/W] (EYETarget, ~EYETarget)
    u32 m_field_01C;  // 0x01C [R/W] (EYETarget, ~EYETarget)
    u32 m_field_020;  // 0x020 [R/W] (EYETarget, ~EYETarget)
    u32 m_field_024;  // 0x024 [R/W] (EYETarget, ~EYETarget)
    u32 m_field_028;  // 0x028 [W] (EYETarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (EYETarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (EYETarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (EYETarget, ~EYETarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (EYETarget, ~EYETarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [R/W] (EYETarget)
    u32 m_field_07C;  // 0x07C [R/W] (EYETarget, ~EYETarget)
    u32 m_field_080;  // 0x080 [W] (EYETarget, ~EYETarget)
    u32 m_field_084;  // 0x084 [W] (EYETarget)
    u32 m_field_088;  // 0x088 [R/W] (EYETarget, SaveCurrentSetting)
    u32 m_field_08C;  // 0x08C [W] (EYETarget)
    u32 m_field_090;  // 0x090 [W] (EYETarget)
    u32 m_field_094;  // 0x094 [W] (EYETarget)
    u32 m_field_098;  // 0x098 [R/W] (EYETarget, SaveCurrentSetting)
    u32 m_field_09C;  // 0x09C [R/W] (EYETarget, ~EYETarget)
    u32 m_field_0A0;  // 0x0A0 [R/W] (EYETarget, ~EYETarget)
    f32 m_field_0A4;  // 0x0A4 [W] (EYETarget, SaveCurrentSetting)
    u32 m_field_0A8;  // 0x0A8 [W] (EYETarget, SaveCurrentSetting)
    u32 m_field_0AC;  // 0x0AC [W] (EYETarget)
    u32 m_field_0B0;  // 0x0B0 [W] (EYETarget)
    u32 m_field_0B4;  // 0x0B4 [R/W] (EYETarget, ~EYETarget)
    u32 m_field_0B8;  // 0x0B8 [R/W] (EYETarget)
    u32 m_field_0BC;  // 0x0BC [R/W] (EYETarget)
    u32 m_field_0C0;  // 0x0C0 [R/W] (EYETarget, RenderCallback)
    u32 m_variable_0C4;  // 0x0C4 [R/W] (AddGetVar, EYETarget, GetVariable, ...)
    u8 _pad_0C8[0xC];  // 0x0C8
    u32 m_variable_0D4;  // 0x0D4 [R/W] (AddSetVar, EYETarget, SetVariable, ...)
};

#endif // EYETARGET_H
