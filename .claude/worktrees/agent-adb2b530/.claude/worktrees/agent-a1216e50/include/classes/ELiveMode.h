#ifndef ELIVEMODE_H
#define ELIVEMODE_H

#include "types.h"

// ELiveMode - struct layout extracted from assembly analysis
// Estimated minimum size: 0x7E8C (32396 bytes)
// 41 known fields (20 named), 60 methods

class ELiveMode {
public:
    // Constructors / Destructors
    ELiveMode(void)  // 0x801B2B38
    ~ELiveMode(void);  // 0x801B2BE8

    // Methods
    bool IsRunningIntroCamera(void);  // 0x801BFF3C (60B)
    void Init(int);  // 0x801B2C5C (508B)
    void SetDontDraw(bool);  // 0x801BFFF4 (40B)
    /* ? */ GetIntroCameraState(void);  // 0x801BFF10 (44B)
    void TriggerIntroCamera(CameraDirector *);  // 0x801BA9CC (112B)
    void SetInitialized(bool);  // 0x801BFFA0 (40B)
    void Reset(int);  // 0x801B4F18 (1188B)
    void SetGoingToNeighborhoodMode(bool);  // 0x801BFF78 (40B)
    void ChangeHouse(void);  // 0x801B7148 (96B)
    void GotoStartMode(void);  // 0x801B71A8 (120B)
    void QuitToMainMenu(void);  // 0x801B7220 (500B)
    bool IsReadyForUpdate(void);  // 0x801B7414 (728B)
    bool IsInitialized(void);  // 0x801BFFC8 (44B)
    void UpdateIntroCamera(void);  // 0x801B76EC (2496B)
    void StartIntroCamera(CameraDirector *, ESimsCam *);  // 0x801BAA3C (1088B)
    void EndIntroCamera(CameraDirector *, ESimsCam *);  // 0x801BAE7C (392B)
    void Update(void);  // 0x801B80AC (2848B)
    void Draw(ERC *);  // 0x801B8BCC (1852B)
    void DrawMain(ERC *);  // 0x801BA21C (1968B)
    void PauseAllSounds(void);  // 0x801B9308 (40B)
    void ResumeAllSounds(void);  // 0x801B9330 (40B)
    void DrawSplitScreenMask(ERC *, E3DWindow &, int);  // 0x801B9358 (1456B)
    void InitPlayerXWindow(ERC *, E3DWindow &, int);  // 0x801B9908 (964B)
    void DrawSplitScreenDivider(ERC *);  // 0x801B9CCC (1360B)
    void InTransportMode(void);  // 0x801BFE5C (44B)
    bool IsIntroCameraTriggered(void);  // 0x801BFE88 (56B)
    void ResetIntroCamera(void);  // 0x801BFEC0 (40B)
    void SetIntroCameraState(IntroCameraStartState);  // 0x801BFEE8 (40B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (Draw, EndIntroCamera, InitPlayerXWindow, ...)
    f32 m_field_004;  // 0x004 [R/W] (Draw, DrawSplitScreenDivider, InitPlayerXWindow)
    f32 m_field_008;  // 0x008 [R/W] (Draw, DrawSplitScreenDivider, InitPlayerXWindow, ...)
    f32 m_field_00C;  // 0x00C [R/W] (Draw, InitPlayerXWindow, Update, ...)
    f32 m_introCamera;  // 0x010 [R/W] (UpdateIntroCamera)
    f32 m_bIsReadyForUpdate;  // 0x014 [W] (IsReadyForUpdate)
    u32 m_bIsReadyForUpdate_018;  // 0x018 [W] (IsReadyForUpdate)
    u32 m_bIsReadyForUpdate_01C;  // 0x01C [R/W] (Draw, Init, IsReadyForUpdate)
    u32 m_field_020;  // 0x020 [R/W] (Draw, Init)
    u32 m_bIsReadyForUpdate_024;  // 0x024 [R/W] (Draw, GotoStartMode, IsReadyForUpdate, ...)
    u32 m_bIsReadyForUpdate_028;  // 0x028 [R/W] (IsReadyForUpdate, Update)
    u32 m_main;  // 0x02C [R] (DrawMain, Update)
    u32 m_bIsReadyForUpdate_030;  // 0x030 [R/W] (Draw, IsReadyForUpdate, Reset)
    u32 m_introCamera_034;  // 0x034 [R/W] (Draw, Reset, UpdateIntroCamera)
    u32 m_field_038;  // 0x038 [W] (Init)
    u32 m_field_03C;  // 0x03C [W] (Draw, Init)
    u8 _pad_040[4];  // 0x040
    u32 m_field_044;  // 0x044 [R/W] (DrawSplitScreenDivider, Init, Reset)
    u8 _pad_048[8];  // 0x048
    u32 m_field_050;  // 0x050 [W] (Init)
    u32 m_field_054;  // 0x054 [W] (StartIntroCamera)
    f32 m_field_058;  // 0x058 [W] (Draw)
    u8 _pad_05C[0x40];  // 0x05C
    u32 m_main_09C;  // 0x09C [R] (DrawMain)
    u8 _pad_0A0[0x28];  // 0x0A0
    u32 m_main_0C8;  // 0x0C8 [R] (DrawMain, Update)
    u32 m_main_0CC;  // 0x0CC [W] (DrawMain)
    u32 m_main_0D0;  // 0x0D0 [R] (DrawMain)
    u8 _pad_0D4[0xC];  // 0x0D4
    u32 m_main_0E0;  // 0x0E0 [R] (DrawMain)
    u8 _pad_0E4[0xC];  // 0x0E4
    u32 m_field_0F0;  // 0x0F0 [R] (Draw, DrawSplitScreenDivider, DrawSplitScreenMask, ...)
    u8 _pad_0F4[8];  // 0x0F4
    u32 m_field_0FC;  // 0x0FC [R] (Draw)
    u32 m_field_100;  // 0x100 [R] (DrawMain, DrawSplitScreenMask, InitPlayerXWindow)
    u32 m_field_104;  // 0x104 [R] (Draw)
    u8 _pad_108[4];  // 0x108
    u32 m_main_10C;  // 0x10C [R] (DrawMain)
    u32 m_main_110;  // 0x110 [R] (DrawMain)
    u8 _pad_114[0xBC];  // 0x114
    s16 m_splitScreenMask;  // 0x1D0 [R] (DrawSplitScreenMask)
    u8 _pad_1D2[2];  // 0x1D2
    u32 m_splitScreenMask_1D4;  // 0x1D4 [R] (DrawSplitScreenMask)
    u8 _pad_1D8[0x29C];  // 0x1D8
    u32 m_field_474;  // 0x474 [R] (Draw)
    u8 _pad_478[0x5E18];  // 0x478
    f32 m_field_6290;  // 0x6290 [R] (Draw)
    u8 _pad_6294[0x1B88];  // 0x6294
    f32 m_field_7E1C;  // 0x7E1C [R] (Draw)
    u8 _pad_7E20[8];  // 0x7E20
    f32 m_field_7E28;  // 0x7E28 [R] (Draw)
    u8 _pad_7E2C[0x38];  // 0x7E2C
    f32 m_field_7E64;  // 0x7E64 [R] (InitPlayerXWindow)
    f32 m_field_7E68;  // 0x7E68 [R] (InitPlayerXWindow)
    u8 _pad_7E6C[8];  // 0x7E6C
    f32 m_splitScreenDivider;  // 0x7E74 [R] (DrawSplitScreenDivider)
    u8 _pad_7E78[0x10];  // 0x7E78
    f32 m_splitScreenDivider_7E88;  // 0x7E88 [R] (DrawSplitScreenDivider)
};

#endif // ELIVEMODE_H
