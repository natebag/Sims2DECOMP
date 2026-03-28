#ifndef EAPP_H
#define EAPP_H

#include "types.h"

// EApp - struct layout extracted from assembly analysis
// Estimated minimum size: 0x474 (1140 bytes)
// 14 known fields (4 named), 66 methods

class EApp {
public:
    // Constructors / Destructors
    EApp(void)  // 0x8079A008
    ~EApp(void);  // 0x8079A10C

    // Methods
    void SetGameState(OVERALL_GAME_STATE);  // 0x8079B48C (40B)
    void Main(void);  // 0x8079A2BC (932B)
    void SetupPaths(void);  // 0x8079A1D8 (228B)
    /* ? */ GetRootDirectory(void);  // 0x8079B320 (68B)
    /* ? */ GetPrefetchBlockSize(void);  // 0x8079B3BC (40B)
    /* ? */ GetScratchBuffSize(void);  // 0x8079B3E4 (40B)
    void PlayMovie(unsigned int, int, int);  // 0x8079AE24 (100B)
    void StopMovie(void);  // 0x8079AE88 (48B)
    bool IsMovieStarting(void);  // 0x8079AEB8 (84B)
    bool IsMoviePlaying(void);  // 0x8079AF0C (84B)
    void SetMenuOwner(OVERALL_GAME_STATE);  // 0x8079B4E0 (40B)
    void SystemInit(void);  // 0x8079A6EC (92B)
    void SystemUpdate(void);  // 0x8079A788 (1692B)
    /* ? */ GetAppStackSize(void);  // 0x8079B588 (44B)
    /* ? */ GetArg(char *);  // 0x8079B0BC (292B)
    /* ? */ GetGameState(void);  // 0x8079B460 (44B)
    void CreateAndStartAppThread(void);  // 0x8079A660 (140B)
    void SetupForMovie(void);  // 0x8079A748 (32B)
    void CleanupAfterMovie(void);  // 0x8079A768 (32B)
    void SetArgs(int, char **);  // 0x8079AF60 (348B)
    /* ? */ GetMovieHeap(void);  // 0x8079B1E0 (64B)
    /* ? */ GetBuildVersion(void);  // 0x8079B364 (44B)
    /* ? */ GetAppName(void);  // 0x8079B390 (44B)
    /* ? */ GetEventTableSize(void);  // 0x8079B40C (40B)
    void ShowInitialDisplay(void);  // 0x8079B508 (32B)
    void Init(void);  // 0x8079B528 (32B)
    void Update(void);  // 0x8079B548 (32B)
    void UpdateAfterHotSync(void);  // 0x8079B568 (32B)
    void Shutdown(void);  // 0x8079B5B4 (32B)
    /* ? */ GetFullArgString(void);  // 0x8079B434 (44B)
    /* ? */ GetMenuOwner(void);  // 0x8079B4B4 (44B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0x32C];  // 0x000
    u32 m_field_32C;  // 0x32C [W] (CreateAndStartAppThread)
    u8 _pad_330[8];  // 0x330
    u32 m_field_338;  // 0x338 [R/W] (CreateAndStartAppThread, EApp, Main, ...)
    u8 _pad_33C[4];  // 0x33C
    u32 m_field_340;  // 0x340 [R/W] (EApp, Main)
    u8 _pad_344[4];  // 0x344
    u32 m_arg;  // 0x348 [R/W] (GetArg, SetArgs)
    u32 m_arg_34C;  // 0x34C [R/W] (GetArg, SetArgs)
    u8 m_args;  // 0x350 [W] (SetArgs)
    u8 _pad_351[0xFF];  // 0x351
    u32 m_field_450;  // 0x450 [R/W] (EApp, SystemUpdate)
    u32 m_field_454;  // 0x454 [R/W] (EApp, SystemUpdate)
    u32 m_field_458;  // 0x458 [R/W] (EApp, SystemUpdate)
    u32 m_field_45C;  // 0x45C [R/W] (EApp, SystemUpdate)
    u32 m_field_460;  // 0x460 [R] (SystemUpdate)
    u32 m_field_464;  // 0x464 [R] (SystemUpdate)
    u32 m_field_468;  // 0x468 [W] (EApp)
    u8 _pad_46C[4];  // 0x46C
    u32 m_upPaths;  // 0x470 [R/W] (EApp, SetupPaths)
};

#endif // EAPP_H
