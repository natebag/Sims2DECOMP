#ifndef CRDTARGET_H
#define CRDTARGET_H

#include "types.h"

// CRDTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0xF8 (248 bytes)
// 50 known fields (20 named), 34 methods

class CRDTarget {
public:
    // Constructors / Destructors
    CRDTarget(void)  // 0x804EB524
    ~CRDTarget(void);  // 0x804EBA5C

    // Methods
    void ScrollingCallback(ERC *, structDrawCBparams *);  // 0x804ECE80 (3384B)
    void HidePhoto(void);  // 0x804EDC40 (92B)
    void EndCredits(void);  // 0x804EC5F0 (360B)
    void SetVariable(char *, char *);  // 0x804EBB64 (464B)
    void StartCredits(void);  // 0x804EC564 (140B)
    void HideCredits(void);  // 0x804EC490 (156B)
    /* ? */ GetVariable(char *);  // 0x804EBD34 (452B)
    /* ? */ GetLocalizable(char *);  // 0x804EBEF8 (600B)
    void Draw(ERC *);  // 0x804EC150 (36B)
    void Update(void);  // 0x804EC174 (412B)
    void ShowPhoto(void);  // 0x804EDBB8 (136B)
    void ShowCredits(void);  // 0x804EC310 (384B)
    void UpdateCredits(void);  // 0x804EC52C (56B)
    void SetupForCreditsRender(int);  // 0x804EC758 (1684B)
    void InitCreditsTextFetch(void);  // 0x804ECDEC (148B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_localizable;  // 0x000 [R/W] (CRDTarget, EndCredits, GetLocalizable, ...)
    u8 m_upForCreditsRender;  // 0x001 [W] (SetupForCreditsRender)
    u16 m_upForCreditsRender_002;  // 0x002 [R/W] (ScrollingCallback, SetupForCreditsRender)
    f32 m_variable;  // 0x004 [R/W] (CRDTarget, GetVariable, ScrollingCallback, ...)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    f32 m_upForCreditsRender_008;  // 0x008 [R/W] (CRDTarget, ScrollingCallback, SetupForCreditsRender, ...)
    f32 m_field_00C;  // 0x00C [R/W] (CRDTarget, ScrollingCallback, ~CRDTarget)
    u32 m_field_010;  // 0x010 [R/W] (CRDTarget, ~CRDTarget)
    u32 m_field_014;  // 0x014 [R/W] (CRDTarget, ~CRDTarget)
    u32 m_upForCreditsRender_018;  // 0x018 [R/W] (CRDTarget, SetupForCreditsRender, ~CRDTarget)
    u32 m_upForCreditsRender_01C;  // 0x01C [R/W] (CRDTarget, SetupForCreditsRender, ~CRDTarget)
    u32 m_field_020;  // 0x020 [R/W] (CRDTarget, ~CRDTarget)
    f32 m_upForCreditsRender_024;  // 0x024 [R/W] (CRDTarget, ScrollingCallback, SetupForCreditsRender, ...)
    u32 m_field_028;  // 0x028 [W] (CRDTarget)
    u32 m_field_02C;  // 0x02C [W] (ScrollingCallback)
    u32 m_field_030;  // 0x030 [W] (ScrollingCallback)
    u32 m_field_034;  // 0x034 [W] (ScrollingCallback)
    u32 m_field_038;  // 0x038 [W] (CRDTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (CRDTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (CRDTarget, ~CRDTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (CRDTarget, ~CRDTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [R/W] (CRDTarget)
    u32 m_field_07C;  // 0x07C [R/W] (CRDTarget, ~CRDTarget)
    u32 m_field_080;  // 0x080 [W] (CRDTarget, ~CRDTarget)
    u32 m_variable_084;  // 0x084 [R/W] (CRDTarget, GetVariable, Update)
    u32 m_field_088;  // 0x088 [R/W] (CRDTarget, HideCredits, ShowCredits, ...)
    u32 m_variable_08C;  // 0x08C [R/W] (CRDTarget, HideCredits, SetVariable, ...)
    u32 m_field_090;  // 0x090 [R/W] (CRDTarget, ShowCredits, Update)
    u32 m_field_094;  // 0x094 [R/W] (ShowPhoto, Update)
    u32 m_field_098;  // 0x098 [R/W] (ShowCredits, Update, ~CRDTarget)
    u32 m_variable_09C;  // 0x09C [R/W] (CRDTarget, EndCredits, GetVariable, ...)
    u32 m_field_0A0;  // 0x0A0 [R/W] (CRDTarget, EndCredits, ScrollingCallback, ...)
    f32 m_field_0A4;  // 0x0A4 [W] (CRDTarget, StartCredits)
    f32 m_upForCreditsRender_0A8;  // 0x0A8 [R/W] (CRDTarget, ScrollingCallback, SetupForCreditsRender)
    f32 m_field_0AC;  // 0x0AC [R/W] (CRDTarget, ScrollingCallback)
    u32 m_field_0B0;  // 0x0B0 [R/W] (CRDTarget, InitCreditsTextFetch, ScrollingCallback)
    u8 m_field_0B3;  // 0x0B3 [R] (ScrollingCallback)
    f32 m_field_0B4;  // 0x0B4 [R/W] (CRDTarget, ScrollingCallback)
    u32 m_field_0B8;  // 0x0B8 [R/W] (CRDTarget, EndCredits, InitCreditsTextFetch, ...)
    u32 m_field_0BC;  // 0x0BC [R/W] (InitCreditsTextFetch, ScrollingCallback)
    u32 m_field_0C0;  // 0x0C0 [R/W] (CRDTarget, ShowCredits, Update)
    u32 m_upForCreditsRender_0C4;  // 0x0C4 [R/W] (CRDTarget, EndCredits, SetupForCreditsRender)
    u32 m_upForCreditsRender_0C8;  // 0x0C8 [R/W] (CRDTarget, SetupForCreditsRender, ~CRDTarget)
    u32 m_field_0CC;  // 0x0CC [W] (CRDTarget)
    u32 m_field_0D0;  // 0x0D0 [W] (CRDTarget)
    u8 _pad_0D4[0xC];  // 0x0D4
    u16 m_upForCreditsRender_0E0;  // 0x0E0 [W] (SetupForCreditsRender)
    u16 m_upForCreditsRender_0E2;  // 0x0E2 [W] (SetupForCreditsRender)
    u8 _pad_0E4[6];  // 0x0E4
    u8 m_upForCreditsRender_0EA;  // 0x0EA [W] (SetupForCreditsRender)
    u8 _pad_0EB[5];  // 0x0EB
    u32 m_upForCreditsRender_0F0;  // 0x0F0 [R/W] (CRDTarget, EndCredits, SetupForCreditsRender)
    u32 m_upForCreditsRender_0F4;  // 0x0F4 [R/W] (CRDTarget, EndCredits, SetupForCreditsRender)
};

#endif // CRDTARGET_H
