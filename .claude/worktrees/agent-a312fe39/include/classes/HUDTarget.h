#ifndef HUDTARGET_H
#define HUDTARGET_H

#include "types.h"

// HUDTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8B8 (2232 bytes)
// 48 known fields (23 named), 134 methods

class HUDTarget {
public:
    // Constructors / Destructors
    HUDTarget(void)  // 0x804A6DB0
    ~HUDTarget(void);  // 0x804A7868

    // Methods
    void ShowMenu(int);  // 0x804AB2FC (224B)
    void AddMenu(int, cXObject *, BString2 &, unsigned int, ERShader *);  // 0x804AAF8C (244B)
    void CompleteMenu(int);  // 0x804AB228 (212B)
    void AddMenuItem(int, cXObject *, Interaction *, BString2 &, unsigned int, ERShader *, int, bool);  // 0x804AB080 (260B)
    /* ? */ GetHUDMode(void);  // 0x804B0824 (64B)
    void ReleasePause(bool);  // 0x804A7D00 (72B)
    void IncPause(bool);  // 0x804A7CB8 (72B)
    void NotifyMenuRemoveObj(cXObject *);  // 0x804AB184 (164B)
    void CloseMenu(int);  // 0x804AB490 (84B)
    /* ? */ GetHudTransitionTarget(void);  // 0x804B095C (48B)
    void GotoMainMenu(void);  // 0x804ACB54 (176B)
    void RequestHUD(short, short, short);  // 0x804AB8F0 (372B)
    void AddHUDControl(short, short, short &);  // 0x804ABA64 (152B)
    void RemoveHUDControl(short, short);  // 0x804ABAFC (176B)
    void SetJobBarInputRange(int, int, int);  // 0x804ABED4 (288B)
    void ApplyMotiveCurveArray(unsigned int, short);  // 0x804ABFF4 (568B)
    void AnimateHUDControl(short, HUDTarget::EControlAnimType);  // 0x804AC884 (188B)
    void ManageHUD(short, short, short);  // 0x804ABBAC (312B)
    void SetHUDData(short, short);  // 0x804ABCE4 (496B)
    /* ? */ GetHUDData(short, short &);  // 0x804AC7B0 (212B)
    /* ? */ GetActionQueueHUD(int);  // 0x804ACD14 (196B)
    void ResetJobHudProperties(void);  // 0x804AB7D0 (288B)
    void InstallHUDIcons(int);  // 0x804A9D04 (1416B)
    void AttachControllers(void);  // 0x804A7A04 (468B)
    void InitRepValues(void);  // 0x804A9224 (420B)
    void UpdateClock(void);  // 0x804AA624 (432B)
    void ReleaseControllers(void);  // 0x804A7BD8 (224B)
    void SetVariable(char *, char *);  // 0x804A7D48 (148B)
    void SetPlayerVariable(int, char *, char *);  // 0x804A7DDC (1420B)
    void OnHUDHide(void);  // 0x804A9CBC (72B)
    void OnHUDHideStart(void);  // 0x804A9C94 (40B)
    void OnHUDShow(void);  // 0x804A9C4C (72B)
    void OnPlayerHUDHide(int);  // 0x804A9B50 (88B)
    void OnPlayerHUDHideStart(int);  // 0x804A9BA8 (164B)
    void OnPlayerHUDShow(int);  // 0x804A9AF4 (92B)
    void UpdateActivePlayer(int, bool);  // 0x804AA7D4 (148B)
    /* ? */ GetVariable(char *);  // 0x804A8368 (160B)
    /* ? */ GetPlayerVariable(int, char *);  // 0x804A8408 (1824B)
    void OnReadBar(int, unsigned int);  // 0x804A965C (264B)
    /* ? */ GetReputationValue(int);  // 0x804A93C8 (400B)
    /* ? */ GetNextRepUnlockValue(int);  // 0x804A9558 (260B)
    void ShouldHUDBeVisible(int);  // 0x804AA28C (420B)
    /* ? */ GetLocalizable(char *);  // 0x804A8B28 (152B)
    /* ? */ GetPlayerLocalizable(int, char *);  // 0x804A8BC0 (1636B)
    void CalculateJobScore(void);  // 0x804AC22C (1412B)
    void ReadMoodBar(int, unsigned int);  // 0x804A9764 (488B)
    void ShowHUD(void);  // 0x804A994C (268B)
    void HideHUD(void);  // 0x804A9A58 (156B)
    void UpdateTutorialLocks(void);  // 0x804AA430 (156B)
    void Update(void);  // 0x804AA4CC (344B)
    bool IsHUDVisible(void);  // 0x804B08DC (60B)
    void UpdateSpeedControls(void);  // 0x804AA91C (1648B)
    bool IsActionQueueAvailable(int);  // 0x804AA868 (180B)
    bool IsMenuAvailable(int);  // 0x804AB3DC (180B)
    void AddAction(int, Interaction *, BString2 &, unsigned int, ERShader *, unsigned int);  // 0x804AB4E4 (228B)
    void RemoveAction(int, Interaction *);  // 0x804AB5C8 (132B)
    void RemoveAllActions(int);  // 0x804AB64C (124B)
    void Draw(ERC *);  // 0x804AB6C8 (216B)
    void DrawMotiveValues(ERC *, int);  // 0x804AB7A0 (48B)
    void GotoCAS(unsigned short, unsigned short, int, int);  // 0x804AC940 (532B)
    void RequestQuitGame(bool);  // 0x804ACC04 (188B)
    /* ? */ GetJobBarCount(void);  // 0x804ACCC0 (84B)
    void HUDHideComplete(void);  // 0x804B0864 (60B)
    void HideInProgress(void);  // 0x804B08A0 (60B)
    bool IsPlayerHUDVisible(int);  // 0x804B0918 (68B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_playerLocalizable;  // 0x000 [R/W] (ApplyMotiveCurveArray, GetNextRepUnlockValue, GetPlayerLocalizable, ...)
    u8 _pad_002[2];  // 0x002
    u16 m_playerVariable;  // 0x004 [R/W] (ApplyMotiveCurveArray, GetPlayerVariable, HUDTarget, ...)
    u8 m_playerVariable_006;  // 0x006 [W] (GetPlayerVariable)
    u8 _pad_007[1];  // 0x007
    u16 m_playerVariable_008;  // 0x008 [R/W] (GetPlayerVariable, HUDTarget, ~HUDTarget)
    u8 _pad_00A[2];  // 0x00A
    u32 m_field_00C;  // 0x00C [R/W] (HUDTarget, ~HUDTarget)
    u32 m_field_010;  // 0x010 [R/W] (HUDTarget, ~HUDTarget)
    u32 m_field_014;  // 0x014 [R/W] (HUDTarget, ~HUDTarget)
    u32 m_field_018;  // 0x018 [R/W] (HUDTarget, ~HUDTarget)
    u32 m_field_01C;  // 0x01C [R/W] (HUDTarget, InstallHUDIcons, ~HUDTarget)
    u32 m_field_020;  // 0x020 [R/W] (HUDTarget, ~HUDTarget)
    u32 m_field_024;  // 0x024 [R/W] (HUDTarget, ~HUDTarget)
    u32 m_field_028;  // 0x028 [W] (HUDTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (HUDTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (HUDTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (HUDTarget, ~HUDTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (HUDTarget, ~HUDTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (HUDTarget)
    u32 m_field_07C;  // 0x07C [R/W] (HUDTarget, InstallHUDIcons, ~HUDTarget)
    u32 m_field_080;  // 0x080 [W] (HUDTarget, ~HUDTarget)
    u8 m_field_084;  // 0x084 [R/W] (HUDTarget, Update)
    u8 _pad_085[0x15];  // 0x085
    u16 m_field_09A;  // 0x09A [R/W] (CalculateJobScore, ResetJobHudProperties)
    u16 m_field_09C;  // 0x09C [R/W] (CalculateJobScore, ResetJobHudProperties)
    u8 _pad_09E[2];  // 0x09E
    u32 m_hUDData;  // 0x0A0 [R/W] (ApplyMotiveCurveArray, CalculateJobScore, GetHUDData, ...)
    u8 _pad_0A4[0x24];  // 0x0A4
    u16 m_playerLocalizable_0C8;  // 0x0C8 [R/W] (GetPlayerLocalizable, GetPlayerVariable, HUDTarget, ...)
    u16 m_playerVariable_0CA;  // 0x0CA [R/W] (ApplyMotiveCurveArray, GetPlayerVariable, HUDTarget, ...)
    f32 m_playerVariable_0CC;  // 0x0CC [W] (HUDTarget, SetPlayerVariable)
    u32 m_playerVariable_0D0;  // 0x0D0 [R/W] (GetPlayerLocalizable, GetPlayerVariable, HUDTarget)
    u32 m_field_0D4;  // 0x0D4 [W] (HUDTarget)
    u8 m_field_0D8;  // 0x0D8 [W] (HUDTarget)
    u8 _pad_0D9[3];  // 0x0D9
    u32 m_playerVariable_0DC;  // 0x0DC [W] (HUDTarget, SetPlayerVariable)
    u32 m_field_0E0;  // 0x0E0 [W] (HUDTarget)
    u32 m_playerVariable_0E4;  // 0x0E4 [R/W] (HUDTarget, HideHUD, SetPlayerVariable, ...)
    u8 m_playerVariable_0E8;  // 0x0E8 [R/W] (GotoCAS, HUDTarget, HideHUD, ...)
    u8 m_playerVariable_0E9;  // 0x0E9 [W] (HUDTarget, SetPlayerVariable)
    u8 m_playerVariable_0EA;  // 0x0EA [W] (HUDTarget, SetPlayerVariable)
    u8 _pad_0EB[1];  // 0x0EB
    u32 m_field_0EC;  // 0x0EC [R/W] (HUDTarget, HideHUD, ShowHUD, ...)
    u32 m_tutorialLocks;  // 0x0F0 [W] (HUDTarget, UpdateTutorialLocks)
    u8 m_speedControls;  // 0x0F4 [R/W] (HUDTarget, Update, UpdateSpeedControls)
    u8 m_speedControls_0F5;  // 0x0F5 [R/W] (HUDTarget, Update, UpdateSpeedControls)
    u8 m_speedControls_0F6;  // 0x0F6 [R/W] (HUDTarget, Update, UpdateSpeedControls)
    u8 m_speedControls_0F7;  // 0x0F7 [R/W] (HUDTarget, Update, UpdateSpeedControls)
    u32 m_field_0F8;  // 0x0F8 [R/W] (AttachControllers, HUDTarget, ReleaseControllers, ...)
    u32 m_field_0FC;  // 0x0FC [R/W] (AttachControllers, HUDTarget, ReleaseControllers, ...)
    u8 m_playerVariable_100;  // 0x100 [R/W] (GetPlayerVariable, GotoCAS, HUDTarget, ...)
    u8 _pad_101[3];  // 0x101
    u32 m_hUDData_104;  // 0x104 [R/W] (CalculateJobScore, GetHUDData, GetPlayerVariable, ...)
    u8 _pad_108[0x50];  // 0x108
    u32 m_playerLocalizable_158;  // 0x158 [R] (GetPlayerLocalizable)
    u8 _pad_15C[0x308];  // 0x15C
    u32 m_playerLocalizable_464;  // 0x464 [R] (GetPlayerLocalizable)
    u8 _pad_468[0x44C];  // 0x468
    u32 m_field_8B4;  // 0x8B4 [R/W] (HUDTarget, ~HUDTarget)
};

#endif // HUDTARGET_H
