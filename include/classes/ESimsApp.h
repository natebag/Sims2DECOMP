#ifndef ESIMSAPP_H
#define ESIMSAPP_H

#include "types.h"

// ESimsApp - struct layout extracted from assembly analysis
// Estimated minimum size: 0xD24 (3364 bytes)
// 38 known fields (6 named), 62 methods

class ESimsApp {
public:
    // Constructors / Destructors
    ESimsApp(void)  // 0x800060C4
    ~ESimsApp(void);  // 0x8000614C

    // Methods
    /* ? */ GetStartLot(void);  // 0x80005718 (48B)
    void SetStartLot(int);  // 0x80005748 (216B)
    void SetNghName(char *);  // 0x80005820 (316B)
    void parseCommandLine(void);  // 0x8000595C (1896B)
    void Shutdown(void);  // 0x800061A8 (356B)
    /* ? */ GetBuildVersion(void);  // 0x8000630C (44B)
    /* ? */ GetDefaultLanguage(void);  // 0x80006338 (52B)
    void Init(void);  // 0x8000636C (4372B)
    void initContinue(void);  // 0x800076DC (920B)
    void ClearRecentlyBuiltFilesList(void);  // 0x8000A534 (128B)
    void ShowInitialDisplay(void);  // 0x80007480 (604B)
    void LoadSimulatorGlobs(void);  // 0x80007AB4 (52B)
    void SetGameState(OVERALL_GAME_STATE);  // 0x80007A74 (64B)
    void UpdateCheats(void);  // 0x80007B1C (2132B)
    void UpdateApt(void);  // 0x80008370 (168B)
    void UpdateGame(void);  // 0x80008418 (144B)
    void UpdateShaders(float);  // 0x800084A8 (824B)
    void UpdateAudio(void);  // 0x800087E0 (156B)
    void UpdateDraw(void);  // 0x80008A14 (3404B)
    void UpdateReset(void);  // 0x80009760 (308B)
    void Update(void);  // 0x80009894 (484B)
    void SetupForMovie(void);  // 0x80009A78 (68B)
    void CleanupAfterMovie(void);  // 0x80009ABC (68B)
    /* ? */ GetMovieHeap(void);  // 0x80009B00 (112B)
    void TakeBigScreenshot(int, int);  // 0x80009B70 (72B)
    void UpdateAfterHotSync(void);  // 0x8000A15C (984B)
    /* ? */ GetAppName(void);  // 0x8000DB5C (44B)
    /* ? */ GetEventTableSize(void);  // 0x8000DB88 (40B)
    /* ? */ GetNghName(void);  // 0x8000DBB0 (160B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (UpdateDraw, initContinue)
    u32 m_field_004;  // 0x004 [R/W] (initContinue)
    u32 m_field_008;  // 0x008 [W] (initContinue)
    u32 m_field_00C;  // 0x00C [R/W] (initContinue)
    u32 m_field_010;  // 0x010 [W] (initContinue)
    u32 m_field_014;  // 0x014 [W] (initContinue)
    u32 m_field_018;  // 0x018 [W] (initContinue)
    u32 m_field_01C;  // 0x01C [W] (initContinue)
    u32 m_field_020;  // 0x020 [W] (initContinue)
    u32 m_field_024;  // 0x024 [W] (initContinue)
    f32 m_field_028;  // 0x028 [W] (initContinue)
    u32 m_field_02C;  // 0x02C [W] (initContinue)
    u8 _pad_030[0xC];  // 0x030
    u32 m_field_03C;  // 0x03C [W] (initContinue)
    u8 _pad_040[0x14];  // 0x040
    u32 m_field_054;  // 0x054 [W] (initContinue)
    u8 _pad_058[0xC];  // 0x058
    u32 m_field_064;  // 0x064 [W] (initContinue)
    u8 _pad_068[0x1C];  // 0x068
    u32 m_field_084;  // 0x084 [W] (initContinue)
    u32 m_field_088;  // 0x088 [W] (initContinue)
    u32 m_field_08C;  // 0x08C [W] (initContinue)
    u32 m_field_090;  // 0x090 [W] (initContinue)
    u32 m_field_094;  // 0x094 [W] (initContinue)
    u32 m_field_098;  // 0x098 [W] (initContinue)
    u8 _pad_09C[0x60];  // 0x09C
    u32 m_field_0FC;  // 0x0FC [R/W] (Init)
    u8 _pad_100[0x238];  // 0x100
    u32 m_field_338;  // 0x338 [R/W] (ESimsApp, Init)
    u8 _pad_33C[0xC];  // 0x33C
    u32 m_field_348;  // 0x348 [R] (parseCommandLine)
    u32 m_field_34C;  // 0x34C [R] (parseCommandLine)
    u8 _pad_350[0x100];  // 0x350
    u32 m_audio;  // 0x450 [R] (UpdateAudio)
    u8 _pad_454[0x24];  // 0x454
    u32 m_field_478;  // 0x478 [R/W] (ESimsApp, Init, Shutdown)
    u32 m_draw_47C;  // 0x47C [W] (UpdateDraw)
    u32 m_field_480;  // 0x480 [R/W] (ESimsApp, Init, Shutdown)
    u8 m_field_484;  // 0x484 [W] (ESimsApp, Shutdown)
    u8 _pad_485[3];  // 0x485
    u32 m_field_488;  // 0x488 [W] (ESimsApp, Shutdown)
    u32 m_field_48C;  // 0x48C [R/W] (ESimsApp, Update)
    u32 m_field_490;  // 0x490 [R/W] (ESimsApp, Update)
    u8 _pad_494[4];  // 0x494
    u32 m_field_498;  // 0x498 [W] (Init)
    u32 m_draw_49C;  // 0x49C [R/W] (UpdateDraw)
    u32 m_draw_4A0;  // 0x4A0 [R] (UpdateDraw)
    u32 m_draw_4A4;  // 0x4A4 [R] (UpdateDraw)
    u8 _pad_4A8[0x878];  // 0x4A8
    u32 m_field_D20;  // 0xD20 [W] (Init)
};

#endif // ESIMSAPP_H
