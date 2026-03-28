#ifndef CASTATTOOTARGET_H
#define CASTATTOOTARGET_H

#include "types.h"

// CASTattooTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x120 (288 bytes)
// 38 known fields (1 named), 12 methods

class CASTattooTarget {
public:
    // Constructors / Destructors
    CASTattooTarget(void)  // 0x804D87BC
    ~CASTattooTarget(void);  // 0x804D8A08

    // Methods
    /* ? */ GetLocalizableSubnav(int, unsigned wchar_t *);  // 0x804D8B68 (400B)
    void RemoveClothesForTattoo(void);  // 0x804D8CF8 (496B)
    void RestoreClothesForTattoo(void);  // 0x804D8EE8 (352B)
    void SetVariable(char *, char *);  // 0x804D8A88 (224B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (CASTattooTarget, ~CASTattooTarget)
    u32 m_field_004;  // 0x004 [R/W] (CASTattooTarget, ~CASTattooTarget)
    u32 m_field_008;  // 0x008 [R/W] (CASTattooTarget, ~CASTattooTarget)
    u32 m_field_00C;  // 0x00C [R/W] (CASTattooTarget, ~CASTattooTarget)
    u32 m_field_010;  // 0x010 [R/W] (CASTattooTarget, RestoreClothesForTattoo, ~CASTattooTarget)
    u32 m_field_014;  // 0x014 [R/W] (CASTattooTarget, ~CASTattooTarget)
    u32 m_field_018;  // 0x018 [R/W] (CASTattooTarget, ~CASTattooTarget)
    u32 m_field_01C;  // 0x01C [R/W] (CASTattooTarget, ~CASTattooTarget)
    u32 m_field_020;  // 0x020 [R/W] (CASTattooTarget, ~CASTattooTarget)
    u32 m_field_024;  // 0x024 [R/W] (CASTattooTarget, ~CASTattooTarget)
    u32 m_field_028;  // 0x028 [W] (CASTattooTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (CASTattooTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (CASTattooTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (CASTattooTarget, ~CASTattooTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (CASTattooTarget, ~CASTattooTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (CASTattooTarget)
    u32 m_field_07C;  // 0x07C [R/W] (CASTattooTarget, ~CASTattooTarget)
    u32 m_field_080;  // 0x080 [W] (CASTattooTarget, ~CASTattooTarget)
    u32 m_field_084;  // 0x084 [R/W] (CASTattooTarget, RemoveClothesForTattoo, RestoreClothesForTattoo)
    u32 m_field_088;  // 0x088 [W] (CASTattooTarget, ~CASTattooTarget)
    u8 _pad_08C[1];  // 0x08C
    u8 m_field_08D;  // 0x08D [W] (RemoveClothesForTattoo)
    u8 m_field_08E;  // 0x08E [W] (RemoveClothesForTattoo)
    u8 _pad_08F[1];  // 0x08F
    u32 m_field_090;  // 0x090 [W] (RemoveClothesForTattoo)
    u8 _pad_094[4];  // 0x094
    u8 m_field_098;  // 0x098 [W] (RemoveClothesForTattoo)
    u8 m_field_099;  // 0x099 [W] (RemoveClothesForTattoo)
    u8 _pad_09A[2];  // 0x09A
    u32 m_field_09C;  // 0x09C [W] (RemoveClothesForTattoo)
    u32 m_field_0A0;  // 0x0A0 [W] (RemoveClothesForTattoo)
    u8 _pad_0A4[0x20];  // 0x0A4
    u8 m_field_0C4;  // 0x0C4 [W] (RemoveClothesForTattoo)
    u8 m_field_0C5;  // 0x0C5 [W] (RemoveClothesForTattoo)
    u8 _pad_0C6[2];  // 0x0C6
    u32 m_field_0C8;  // 0x0C8 [W] (RemoveClothesForTattoo)
    u8 m_field_0CC;  // 0x0CC [W] (RemoveClothesForTattoo)
    u8 m_field_0CD;  // 0x0CD [W] (RemoveClothesForTattoo)
    u8 _pad_0CE[2];  // 0x0CE
    u32 m_field_0D0;  // 0x0D0 [W] (RemoveClothesForTattoo)
    u8 _pad_0D4[0x1E];  // 0x0D4
    u16 m_field_0F2;  // 0x0F2 [R] (RestoreClothesForTattoo)
    u8 m_field_0F4;  // 0x0F4 [R] (RestoreClothesForTattoo)
    u8 _pad_0F5[0x24];  // 0x0F5
    u8 m_field_119;  // 0x119 [R] (RemoveClothesForTattoo)
    u8 m_field_11A;  // 0x11A [R] (RemoveClothesForTattoo)
    u8 _pad_11B[1];  // 0x11B
    u32 m_field_11C;  // 0x11C [R] (RemoveClothesForTattoo)
};

#endif // CASTATTOOTARGET_H
