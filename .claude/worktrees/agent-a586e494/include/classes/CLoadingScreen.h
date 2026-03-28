#ifndef CLOADINGSCREEN_H
#define CLOADINGSCREEN_H

#include "types.h"

// CLoadingScreen - struct layout extracted from assembly analysis
// Estimated minimum size: 0x5580 (21888 bytes)
// 27 known fields (18 named), 12 methods

class CLoadingScreen {
public:
    // Constructors / Destructors
    CLoadingScreen(CLoadingScreen::eLoadingScreenMode)  // 0x80107550
    ~CLoadingScreen(void);  // 0x80107800

    // Methods
    void InitAsync(void);  // 0x8010796C (212B)
    void Update(float);  // 0x80107A40 (356B)
    void DrawTopmost(ERC *, float);  // 0x80107BA4 (3368B)
    /* ? */ GetMode(void);  // 0x8010BC50 (44B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[4];  // 0x000
    f32 m_topmost;  // 0x004 [W] (DrawTopmost)
    u8 _pad_008[4];  // 0x008
    u32 m_field_00C;  // 0x00C [R] (~CLoadingScreen)
    u8 _pad_010[0x48];  // 0x010
    f32 m_topmost_058;  // 0x058 [W] (DrawTopmost)
    u8 _pad_05C[0x40];  // 0x05C
    u32 m_topmost_09C;  // 0x09C [R] (DrawTopmost)
    u8 _pad_0A0[0x50];  // 0x0A0
    u32 m_topmost_0F0;  // 0x0F0 [R] (DrawTopmost)
    u8 _pad_0F4[0x4C];  // 0x0F4
    s16 m_topmost_140;  // 0x140 [R] (DrawTopmost)
    u8 _pad_142[2];  // 0x142
    u32 m_topmost_144;  // 0x144 [R] (DrawTopmost)
    u8 _pad_148[0x40];  // 0x148
    s16 m_topmost_188;  // 0x188 [R] (DrawTopmost)
    u8 _pad_18A[2];  // 0x18A
    u32 m_topmost_18C;  // 0x18C [R] (DrawTopmost)
    u8 _pad_190[0x40];  // 0x190
    s16 m_topmost_1D0;  // 0x1D0 [R] (DrawTopmost)
    u8 _pad_1D2[2];  // 0x1D2
    u32 m_topmost_1D4;  // 0x1D4 [R] (DrawTopmost)
    u8 _pad_1D8[0x40];  // 0x1D8
    s16 m_topmost_218;  // 0x218 [R] (DrawTopmost)
    u8 _pad_21A[2];  // 0x21A
    u32 m_topmost_21C;  // 0x21C [R] (DrawTopmost)
    u8 _pad_220[0x130];  // 0x220
    u32 m_field_350;  // 0x350 [R/W] (CLoadingScreen, DrawTopmost, InitAsync)
    u32 m_field_354;  // 0x354 [R/W] (CLoadingScreen)
    u32 m_field_358;  // 0x358 [R/W] (CLoadingScreen, DrawTopmost, Update, ...)
    u32 m_field_35C;  // 0x35C [R/W] (CLoadingScreen, Update, ~CLoadingScreen)
    u32 m_field_360;  // 0x360 [R/W] (CLoadingScreen, DrawTopmost, Update, ...)
    u32 m_field_364;  // 0x364 [R/W] (CLoadingScreen, DrawTopmost, ~CLoadingScreen)
    u8 _pad_368[0x20];  // 0x368
    u32 m_topmost_388;  // 0x388 [R/W] (CLoadingScreen, DrawTopmost)
    u32 m_field_38C;  // 0x38C [R/W] (CLoadingScreen, Update)
    u32 m_field_390;  // 0x390 [W] (CLoadingScreen, ~CLoadingScreen)
    u8 _pad_394[0x357C];  // 0x394
    f32 m_topmost_3910;  // 0x3910 [R] (DrawTopmost)
    u8 _pad_3914[4];  // 0x3914
    f64 m_topmost_3918;  // 0x3918 [R] (DrawTopmost)
    u8 _pad_3920[4];  // 0x3920
    f32 m_topmost_3924;  // 0x3924 [R] (DrawTopmost)
    f32 m_topmost_3928;  // 0x3928 [R] (DrawTopmost)
    u8 _pad_392C[0x1C50];  // 0x392C
    u32 m_topmost_557C;  // 0x557C [R] (DrawTopmost)
};

#endif // CLOADINGSCREEN_H
