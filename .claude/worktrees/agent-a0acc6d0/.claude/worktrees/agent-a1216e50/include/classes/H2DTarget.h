#ifndef H2DTARGET_H
#define H2DTARGET_H

#include "types.h"

// H2DTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x5C74 (23668 bytes)
// 41 known fields (9 named), 76 methods

class H2DTarget {
public:
    // Constructors / Destructors
    H2DTarget(void)  // 0x80504140
    ~H2DTarget(void);  // 0x80504DCC

    // Methods
    bool IsDialogActive(void);  // 0x80507E54 (168B)
    void SelectedPersonChanged(int, cXPerson *);  // 0x80506F30 (248B)
    /* ? */ GetPausePlayer(void);  // 0x80506C78 (52B)
    void SpawnModelessDialog(UIDialog *);  // 0x805072E4 (96B)
    void SpawnIntroThoughtBalloon(UIDialog *);  // 0x8050719C (212B)
    void SpawnRewardMomentDialog(int, int);  // 0x80507028 (140B)
    void NewWantFearIcon(int, int, unsigned int, unsigned int, WAFTarget::eWAFIconAnim, Neighbor *);  // 0x80507408 (164B)
    void CountModelessDialogs(void);  // 0x8050739C (108B)
    void CleanupModelessDialogs(void);  // 0x80507344 (88B)
    void TriggerInteractionAnimation(int, unsigned int, unsigned int, unsigned int);  // 0x80507C68 (148B)
    void SetInteractionDisplayValues(int, unsigned int, unsigned int);  // 0x80507BD8 (144B)
    void AddAction(int, Interaction *, BString2 &, unsigned int, ERShader *, unsigned int);  // 0x805074AC (180B)
    void RemoveAction(int, Interaction *);  // 0x80507560 (148B)
    void RemoveAllActions(int);  // 0x805075F4 (140B)
    bool IsActionQueueAvailable(int);  // 0x80507680 (164B)
    void IncPause(bool);  // 0x80506CAC (232B)
    void ReleasePause(bool);  // 0x80506D94 (280B)
    void DisplayPaused(void);  // 0x80507CFC (88B)
    void DisplayFastForward(void);  // 0x80507D54 (88B)
    void ShouldH2DBeVisible(int);  // 0x80507A20 (440B)
    void ACTCancelModeExited(int);  // 0x805070B4 (232B)
    void CSIMActive(int, bool);  // 0x80507724 (160B)
    void INTMirrorUpArrow(int, bool);  // 0x80507E00 (84B)
    void SetVariable(char *, char *);  // 0x80505414 (2500B)
    void CloseSidePanels(int);  // 0x80506EAC (132B)
    /* ? */ GetVariable(char *);  // 0x80505DD8 (332B)
    /* ? */ GetLocalizable(char *);  // 0x80505F24 (600B)
    void Draw(ERC *);  // 0x8050617C (36B)
    void Update(void);  // 0x805061A0 (2776B)
    bool IsUserReadingIntroThoughtBalloon(void);  // 0x80507270 (116B)
    void SKLInWarning(int, bool);  // 0x805077C4 (140B)
    void MOTInWarning(int, bool);  // 0x80507850 (140B)
    void WAFInWarning(int, bool, bool);  // 0x805078DC (144B)
    void SetMoodMeterValue(int, float, bool);  // 0x8050796C (140B)
    void RewardMomentDialogClosed(void);  // 0x805079F8 (40B)
    void CSIMSetIconDisable(int, bool);  // 0x80507DAC (84B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_localizable;  // 0x000 [R/W] (GetLocalizable, GetVariable, H2DTarget, ...)
    u8 _pad_002[2];  // 0x002
    u16 m_variable;  // 0x004 [R/W] (GetVariable, H2DTarget, SetVariable, ...)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (H2DTarget, ~H2DTarget)
    u32 m_field_00C;  // 0x00C [R/W] (H2DTarget, ~H2DTarget)
    u32 m_field_010;  // 0x010 [R/W] (H2DTarget, ~H2DTarget)
    u32 m_field_014;  // 0x014 [R/W] (H2DTarget, ~H2DTarget)
    u32 m_field_018;  // 0x018 [R/W] (H2DTarget, ~H2DTarget)
    u32 m_variable_01C;  // 0x01C [R/W] (H2DTarget, SetVariable, ~H2DTarget)
    u32 m_field_020;  // 0x020 [R/W] (H2DTarget, ~H2DTarget)
    u32 m_field_024;  // 0x024 [R/W] (H2DTarget, ~H2DTarget)
    u32 m_field_028;  // 0x028 [W] (H2DTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (H2DTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (H2DTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (H2DTarget, ~H2DTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (H2DTarget, ~H2DTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (H2DTarget)
    u32 m_field_07C;  // 0x07C [R/W] (H2DTarget, ~H2DTarget)
    u32 m_field_080;  // 0x080 [W] (H2DTarget, ~H2DTarget)
    u32 m_field_084;  // 0x084 [W] (H2DTarget)
    u8 _pad_088[0x10];  // 0x088
    u32 m_field_098;  // 0x098 [W] (H2DTarget)
    u8 _pad_09C[0x28];  // 0x09C
    u32 m_bIsUserReadingIntroThoughtBalloon;  // 0x0C4 [R/W] (H2DTarget, IsUserReadingIntroThoughtBalloon, SpawnIntroThoughtBalloon, ...)
    u32 m_bIsDialogActive;  // 0x0C8 [R/W] (H2DTarget, IsDialogActive, ~H2DTarget)
    u32 m_bIsDialogActive_0CC;  // 0x0CC [R/W] (H2DTarget, IsDialogActive, SpawnRewardMomentDialog, ...)
    u32 m_variable_0D0;  // 0x0D0 [W] (H2DTarget, SetVariable)
    u32 m_field_0D4;  // 0x0D4 [R/W] (SpawnRewardMomentDialog, Update)
    u32 m_field_0D8;  // 0x0D8 [R/W] (SpawnRewardMomentDialog, Update)
    u32 m_field_0DC;  // 0x0DC [R/W] (H2DTarget, SpawnRewardMomentDialog, Update)
    u32 m_field_0E0;  // 0x0E0 [R/W] (H2DTarget, Update)
    u32 m_field_0E4;  // 0x0E4 [W] (H2DTarget)
    u32 m_field_0E8;  // 0x0E8 [W] (H2DTarget)
    u8 _pad_0EC[8];  // 0x0EC
    u32 m_field_0F4;  // 0x0F4 [W] (H2DTarget)
    u32 m_field_0F8;  // 0x0F8 [W] (H2DTarget)
    u8 _pad_0FC[8];  // 0x0FC
    u32 m_field_104;  // 0x104 [W] (H2DTarget)
    u32 m_field_108;  // 0x108 [W] (H2DTarget)
    u32 m_field_10C;  // 0x10C [W] (H2DTarget)
    u32 m_field_110;  // 0x110 [W] (H2DTarget)
    u32 m_field_114;  // 0x114 [W] (H2DTarget)
    u32 m_field_118;  // 0x118 [W] (H2DTarget)
    u8 _pad_11C[0x118];  // 0x11C
    u32 m_variable_234;  // 0x234 [R] (SetVariable)
    u8 _pad_238[0x5A38];  // 0x238
    u32 m_field_5C70;  // 0x5C70 [R] (H2DTarget)
};

#endif // H2DTARGET_H
