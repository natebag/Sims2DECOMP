#ifndef CASSELECTIONTARGET_H
#define CASSELECTIONTARGET_H

#include "types.h"

// CASSelectionTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x5DB (1499 bytes)
// 48 known fields (10 named), 50 methods

class CASSelectionTarget {
public:
    // Constructors / Destructors
    CASSelectionTarget(void)  // 0x804D06C4
    ~CASSelectionTarget(void);  // 0x804D0CB8

    // Methods
    void InitScreen(void);  // 0x804D1EE8 (584B)
    void CreateSelectionShaders(void);  // 0x804D2130 (952B)
    void ClearTextures(void);  // 0x804D28AC (64B)
    void SetVariable(char *, char *);  // 0x804D0E04 (920B)
    void ConvertGridStringToOptionArrayIdx(char *);  // 0x804D119C (200B)
    void ClearRecentlyUnlockedBitFlag(int);  // 0x804D1524 (680B)
    void ConvertCurUIFocusToChangeEvent(int &);  // 0x804D2E24 (524B)
    void ScrollPageLeft(void);  // 0x804D1A70 (196B)
    void ScrollPageRight(void);  // 0x804D1B34 (204B)
    void UpdateSelectionArrowState(void);  // 0x804D2ACC (276B)
    void ConvertColRowToOptionIdx(char, int);  // 0x804D1E68 (128B)
    /* ? */ GetVariable(char *);  // 0x804D1264 (324B)
    /* ? */ GetLockStateString(char *);  // 0x804D13A8 (380B)
    void ConvertGridIdxToOptionIdx(unsigned int);  // 0x804D1E20 (72B)
    void ConvertUiFocusToBodyTextureType(unsigned int, eTattooTextureTypeS2C *);  // 0x804D2D88 (156B)
    void ConvertUiFocusToBodyPart(unsigned int, eBodyPartS2C *);  // 0x804D2BE0 (424B)
    /* ? */ GetLocalizable(char *);  // 0x804D17CC (676B)
    void ClearTextures(unsigned int, unsigned int);  // 0x804D28EC (480B)
    void ShiftShaderTexturesRight(void);  // 0x804D1D10 (272B)
    void LoadGridTextures(unsigned int, unsigned int);  // 0x804D24E8 (836B)
    void ShiftShaderTexturesLeft(void);  // 0x804D1C00 (272B)
    void SetTitleShaderAccordingToCurUIFocus(unsigned int);  // 0x804D3030 (992B)
    void SetupInitialSelectionPage(void);  // 0x804D282C (128B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_variable;  // 0x000 [R/W] (CASSelectionTarget, ClearRecentlyUnlockedBitFlag, GetVariable, ...)
    u8 _pad_001[1];  // 0x001
    u8 m_variable_002;  // 0x002 [W] (GetVariable)
    u8 _pad_003[1];  // 0x003
    u32 m_field_004;  // 0x004 [R/W] (CASSelectionTarget, LoadGridTextures, ~CASSelectionTarget)
    u8 m_localizable;  // 0x007 [W] (GetLocalizable)
    u32 m_field_008;  // 0x008 [R/W] (CASSelectionTarget, ~CASSelectionTarget)
    u32 m_field_00C;  // 0x00C [R/W] (CASSelectionTarget, ~CASSelectionTarget)
    u32 m_field_010;  // 0x010 [R/W] (CASSelectionTarget, ~CASSelectionTarget)
    u32 m_field_014;  // 0x014 [R/W] (CASSelectionTarget, ~CASSelectionTarget)
    u32 m_field_018;  // 0x018 [R/W] (CASSelectionTarget, ~CASSelectionTarget)
    u32 m_titleShaderAccordingToCurUIFocus;  // 0x01C [R/W] (CASSelectionTarget, InitScreen, SetTitleShaderAccordingToCurUIFocus, ...)
    u32 m_field_020;  // 0x020 [R/W] (CASSelectionTarget, ~CASSelectionTarget)
    u32 m_field_024;  // 0x024 [R/W] (CASSelectionTarget, ~CASSelectionTarget)
    u32 m_field_028;  // 0x028 [W] (CASSelectionTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (CASSelectionTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (CASSelectionTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (CASSelectionTarget, ~CASSelectionTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (CASSelectionTarget, ~CASSelectionTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (CASSelectionTarget)
    u32 m_titleShaderAccordingToCurUIFocus_07C;  // 0x07C [R/W] (CASSelectionTarget, SetTitleShaderAccordingToCurUIFocus, ~CASSelectionTarget)
    u32 m_field_080;  // 0x080 [W] (CASSelectionTarget, ~CASSelectionTarget)
    u32 m_variable_084;  // 0x084 [R/W] (CASSelectionTarget, ClearRecentlyUnlockedBitFlag, InitScreen, ...)
    u32 m_field_088;  // 0x088 [W] (CASSelectionTarget, ~CASSelectionTarget)
    u32 m_lockStateString;  // 0x08C [R/W] (CASSelectionTarget, ClearRecentlyUnlockedBitFlag, GetLocalizable, ...)
    u32 m_localizable_090;  // 0x090 [R/W] (CASSelectionTarget, GetLocalizable, SetVariable)
    u8 _pad_094[0x5C];  // 0x094
    u32 m_field_0F0;  // 0x0F0 [R] (ClearTextures, LoadGridTextures, ShiftShaderTexturesLeft, ...)
    u8 _pad_0F4[0x450];  // 0x0F4
    u32 m_field_544;  // 0x544 [R/W] (CASSelectionTarget, InitScreen, ScrollPageRight, ...)
    u32 m_upInitialSelectionPage;  // 0x548 [R/W] (CASSelectionTarget, InitScreen, ScrollPageLeft, ...)
    u32 m_field_54C;  // 0x54C [R/W] (CASSelectionTarget, ClearRecentlyUnlockedBitFlag, ConvertCurUIFocusToChangeEvent, ...)
    u32 m_field_550;  // 0x550 [W] (CASSelectionTarget, InitScreen)
    u8 _pad_554[0x40];  // 0x554
    u32 m_field_594;  // 0x594 [W] (CreateSelectionShaders)
    u32 m_field_598;  // 0x598 [W] (CreateSelectionShaders)
    u32 m_field_59C;  // 0x59C [W] (CreateSelectionShaders)
    u32 m_field_5A0;  // 0x5A0 [W] (CreateSelectionShaders)
    u32 m_field_5A4;  // 0x5A4 [W] (CreateSelectionShaders)
    u32 m_field_5A8;  // 0x5A8 [W] (CreateSelectionShaders)
    u32 m_field_5AC;  // 0x5AC [W] (CreateSelectionShaders)
    u32 m_field_5B0;  // 0x5B0 [W] (CreateSelectionShaders)
    u32 m_field_5B4;  // 0x5B4 [W] (CreateSelectionShaders)
    u32 m_field_5B8;  // 0x5B8 [W] (CreateSelectionShaders)
    u32 m_field_5BC;  // 0x5BC [W] (CreateSelectionShaders)
    u32 m_field_5C0;  // 0x5C0 [W] (CreateSelectionShaders)
    u32 m_field_5C4;  // 0x5C4 [W] (CreateSelectionShaders)
    u32 m_field_5C8;  // 0x5C8 [W] (CreateSelectionShaders)
    u32 m_field_5CC;  // 0x5CC [W] (CreateSelectionShaders)
    u32 m_field_5D0;  // 0x5D0 [W] (CreateSelectionShaders)
    u32 m_field_5D4;  // 0x5D4 [R/W] (CASSelectionTarget, ClearTextures, CreateSelectionShaders, ...)
    u16 m_field_5D8;  // 0x5D8 [W] (InitScreen)
    u8 m_variable_5DA;  // 0x5DA [W] (InitScreen, SetVariable)
};

#endif // CASSELECTIONTARGET_H
