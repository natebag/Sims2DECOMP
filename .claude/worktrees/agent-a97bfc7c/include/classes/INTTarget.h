#ifndef INTTARGET_H
#define INTTARGET_H

#include "types.h"

// INTTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0xE0 (224 bytes)
// 32 known fields (12 named), 28 methods

class INTTarget {
public:
    // Constructors / Destructors
    INTTarget(int)  // 0x8057EF78
    ~INTTarget(void);  // 0x8057F58C

    // Methods
    void UpdateInterestMeter(void);  // 0x80580304 (320B)
    void SetInteractionDisplayValues(unsigned int, unsigned int);  // 0x80580470 (432B)
    void TriggerInteractionAnimation(unsigned int, unsigned int, unsigned int);  // 0x80580620 (544B)
    void MirrorUpArrow(bool);  // 0x80580840 (116B)
    void SetVariable(char *, char *);  // 0x8057F678 (548B)
    /* ? */ GetVariable(char *);  // 0x8057F89C (340B)
    /* ? */ GetLocalizable(char *);  // 0x8057F9F0 (900B)
    void Update(void);  // 0x8057FD74 (604B)
    void Draw(ERC *);  // 0x8057FFD0 (740B)
    void ShowInterestMeter(void);  // 0x805802B4 (40B)
    void HideInterestMeter(void);  // 0x805802DC (40B)
    bool IsInterestMeterActive(void);  // 0x80580444 (44B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_variable;  // 0x000 [R/W] (GetLocalizable, GetVariable, INTTarget, ...)
    u8 _pad_002[2];  // 0x002
    u16 m_variable_004;  // 0x004 [R/W] (GetVariable, INTTarget, UpdateInterestMeter, ...)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (INTTarget, ~INTTarget)
    u32 m_field_00C;  // 0x00C [R/W] (INTTarget, ~INTTarget)
    u32 m_field_010;  // 0x010 [R/W] (INTTarget, ~INTTarget)
    u32 m_field_014;  // 0x014 [R/W] (INTTarget, ~INTTarget)
    u32 m_field_018;  // 0x018 [R/W] (INTTarget, ~INTTarget)
    u32 m_field_01C;  // 0x01C [R/W] (INTTarget, ~INTTarget)
    u32 m_field_020;  // 0x020 [R/W] (INTTarget, ~INTTarget)
    u32 m_field_024;  // 0x024 [R/W] (INTTarget, ~INTTarget)
    u32 m_field_028;  // 0x028 [W] (INTTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (INTTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (INTTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (INTTarget, ~INTTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (INTTarget, ~INTTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (INTTarget)
    u32 m_field_07C;  // 0x07C [R/W] (INTTarget, ~INTTarget)
    u32 m_field_080;  // 0x080 [W] (INTTarget, ~INTTarget)
    u32 m_variable_084;  // 0x084 [R/W] (GetVariable, INTTarget, Update)
    u32 m_variable_088;  // 0x088 [R/W] (INTTarget, MirrorUpArrow, SetVariable, ...)
    u32 m_variable_08C;  // 0x08C [R/W] (INTTarget, SetVariable, Update, ...)
    u32 m_interactionDisplayValues;  // 0x090 [R/W] (INTTarget, SetInteractionDisplayValues, SetVariable, ...)
    u32 m_field_094;  // 0x094 [R/W] (INTTarget, Update)
    u32 m_interactionDisplayValues_098;  // 0x098 [R/W] (INTTarget, MirrorUpArrow, SetInteractionDisplayValues, ...)
    u32 m_interactionDisplayValues_09C;  // 0x09C [R/W] (INTTarget, SetInteractionDisplayValues, Update)
    u32 m_interactionDisplayValues_0A0;  // 0x0A0 [W] (INTTarget, SetInteractionDisplayValues, TriggerInteractionAnimation)
    u32 m_field_0A4;  // 0x0A4 [W] (INTTarget, TriggerInteractionAnimation)
    u32 m_variable_0A8;  // 0x0A8 [W] (INTTarget, SetInteractionDisplayValues, SetVariable)
    u32 m_field_0AC;  // 0x0AC [W] (INTTarget, TriggerInteractionAnimation)
    u32 m_variable_0B0;  // 0x0B0 [R/W] (INTTarget, SetVariable, TriggerInteractionAnimation)
    u8 _pad_0B4[0x28];  // 0x0B4
    u32 m_field_0DC;  // 0x0DC [R/W] (INTTarget, MirrorUpArrow, Update)
};

#endif // INTTARGET_H
