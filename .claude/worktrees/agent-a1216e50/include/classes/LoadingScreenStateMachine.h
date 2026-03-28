#ifndef LOADINGSCREENSTATEMACHINE_H
#define LOADINGSCREENSTATEMACHINE_H

#include "types.h"

// LoadingScreenStateMachine - struct layout extracted from assembly analysis
// Estimated minimum size: 0xAC (172 bytes)
// 25 known fields (2 named), 54 methods

class LoadingScreenStateMachine {
public:
    // Constructors / Destructors
    LoadingScreenStateMachine(int, int)  // 0x801C152C
    ~LoadingScreenStateMachine(void);  // 0x801C1600

    // Methods
    void LoadInProgress(void);  // 0x801C1C24 (92B)
    void StartingLoad(CLoadingScreen::eLoadingScreenMode);  // 0x801C1B44 (80B)
    void LoadFinishing(void);  // 0x801C1B94 (72B)
    bool IsFadedIn(void);  // 0x801C5180 (76B)
    /* ? */ GetSingleton(void);  // 0x801C50E0 (44B)
    /* ? */ GetLoadingScreen(void);  // 0x801C4F14 (44B)
    void LoadStarted(void);  // 0x801C4F40 (40B)
    bool IsFadedOut(void);  // 0x801C5218 (76B)
    void DeleteLoadingScreen(void);  // 0x801C17FC (256B)
    void FaderStop(void);  // 0x801C500C (60B)
    void Startup(void);  // 0x801C1668 (252B)
    void Update(float);  // 0x801C1764 (64B)
    void CreateLoadingScreen(void);  // 0x801C17A4 (88B)
    bool IsReadyToLoad(void);  // 0x801C18FC (60B)
    bool IsLoading(void);  // 0x801C1938 (100B)
    void StartLoad(CLoadingScreen::eLoadingScreenMode);  // 0x801C199C (348B)
    bool IsFadingOut(void);  // 0x801C51CC (76B)
    void FaderStart(float, bool);  // 0x801C4F94 (120B)
    void LoadFinishedNow(void);  // 0x801C1AF8 (76B)
    void LoadFinished(void);  // 0x801C5264 (40B)
    void LoadFinishNow(void);  // 0x801C1BDC (72B)
    bool IsLoadComplete(void);  // 0x801C4F68 (44B)
    void FaderUpdate(float);  // 0x801C5048 (80B)
    void FaderGetFadeOpacity(void);  // 0x801C5098 (72B)
    bool IsFadingIn(void);  // 0x801C510C (116B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (LoadingScreenStateMachine, Startup)
    u32 m_field_004;  // 0x004 [W] (LoadingScreenStateMachine, Startup)
    f32 m_field_008;  // 0x008 [R/W] (FaderUpdate, LoadingScreenStateMachine, Startup)
    u32 m_field_00C;  // 0x00C [R/W] (FaderUpdate, LoadingScreenStateMachine, Startup)
    u32 m_field_010;  // 0x010 [W] (LoadingScreenStateMachine, Startup)
    u32 m_field_014;  // 0x014 [W] (LoadingScreenStateMachine, Startup)
    u32 m_field_018;  // 0x018 [W] (LoadingScreenStateMachine, Startup, ~LoadingScreenStateMachine)
    u32 m_field_01C;  // 0x01C [W] (LoadingScreenStateMachine)
    u32 m_field_020;  // 0x020 [W] (LoadingScreenStateMachine)
    u32 m_field_024;  // 0x024 [W] (LoadingScreenStateMachine)
    f32 m_field_028;  // 0x028 [W] (LoadingScreenStateMachine)
    u32 m_field_02C;  // 0x02C [R/W] (LoadingScreenStateMachine, ~LoadingScreenStateMachine)
    u8 _pad_030[0xC];  // 0x030
    u32 m_field_03C;  // 0x03C [W] (LoadingScreenStateMachine)
    u8 _pad_040[0x14];  // 0x040
    u32 m_field_054;  // 0x054 [W] (LoadingScreenStateMachine)
    u8 _pad_058[0xC];  // 0x058
    u32 m_field_064;  // 0x064 [W] (LoadingScreenStateMachine)
    u8 _pad_068[0x1C];  // 0x068
    u32 m_field_084;  // 0x084 [W] (LoadingScreenStateMachine)
    u32 m_field_088;  // 0x088 [W] (LoadingScreenStateMachine)
    u32 m_field_08C;  // 0x08C [W] (LoadingScreenStateMachine)
    u32 m_field_090;  // 0x090 [W] (LoadingScreenStateMachine)
    u32 m_field_094;  // 0x094 [W] (LoadingScreenStateMachine)
    u32 m_field_098;  // 0x098 [R/W] (CreateLoadingScreen, DeleteLoadingScreen, LoadingScreenStateMachine)
    u32 m_field_09C;  // 0x09C [R/W] (CreateLoadingScreen, StartLoad)
    u32 m_bIsLoading;  // 0x0A0 [R/W] (DeleteLoadingScreen, IsLoading, LoadingScreenStateMachine, ...)
    u32 m_field_0A4;  // 0x0A4 [W] (LoadingScreenStateMachine, StartLoad)
    f32 m_field_0A8;  // 0x0A8 [R/W] (FaderGetFadeOpacity, FaderStart, LoadingScreenStateMachine, ...)
};

#endif // LOADINGSCREENSTATEMACHINE_H
