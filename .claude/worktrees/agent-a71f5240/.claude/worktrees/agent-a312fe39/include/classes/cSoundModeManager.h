#ifndef CSOUNDMODEMANAGER_H
#define CSOUNDMODEMANAGER_H

#include "types.h"

// cSoundModeManager - struct layout extracted from assembly analysis
// Estimated minimum size: 0x34 (52 bytes)
// 11 known fields (10 named), 48 methods

class cSoundModeManager {
public:
    // Constructors / Destructors
    cSoundModeManager(void)  // 0x8021E4F8

    // Methods
    void FadeOutMusic(unsigned int);  // 0x8021E758 (164B)
    void FadeOutSFX(unsigned int);  // 0x8021E8A0 (164B)
    void Update(void);  // 0x80220138 (740B)
    void Mode(void);  // 0x80224AA8 (44B)
    void SetMode(int);  // 0x8021E9E8 (312B)
    bool IsFadingMusic(void);  // 0x80224AD4 (76B)
    void Pause(void);  // 0x8021E5F4 (184B)
    void Unpause(void);  // 0x8021E6AC (172B)
    void Shutdown(void);  // 0x8021E588 (108B)
    void FadeInMusic(unsigned int);  // 0x8021E7FC (164B)
    void FadeInSFX(unsigned int);  // 0x8021E944 (164B)
    void UpdateMusicVolume(void);  // 0x8021EB20 (1408B)
    void UpdateSFXVolume(void);  // 0x8021F0A0 (1332B)
    void UpdateLoadMusic(void);  // 0x8021F5D4 (1600B)
    /* ? */ GetFrontEndMusicTrack(bool);  // 0x8021FC14 (108B)
    void NextFrontEndTrack(void);  // 0x8021FC80 (72B)
    void PrevFrontEndTrack(void);  // 0x8021FCC8 (72B)
    void StartFrontEndMusic(bool);  // 0x8021FD10 (96B)
    void StartMusicTrack(char *, float);  // 0x8021FE60 (336B)
    /* ? */ GetDemoMusicTrack(void);  // 0x8021FD70 (72B)
    void NextDemoMusicTrack(void);  // 0x8021FDB8 (72B)
    void StartDemoMusic(void);  // 0x8021FE00 (96B)
    void StartBuildBuyMusic(void);  // 0x8021FFB0 (196B)
    void StartCASMusic(void);  // 0x80220074 (196B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Pause, SetMode, Update, ...)
    u32 m_mode_004;  // 0x004 [R/W] (SetMode, StartMusicTrack, UpdateLoadMusic, ...)
    u32 m_musicVolume;  // 0x008 [R/W] (StartMusicTrack, UpdateMusicVolume)
    u32 m_musicVolume_00C;  // 0x00C [R] (UpdateMusicVolume)
    u32 m_sFXVolume;  // 0x010 [R/W] (UpdateSFXVolume)
    u32 m_sFXVolume_014;  // 0x014 [R/W] (UpdateSFXVolume)
    u32 m_sFXVolume_018;  // 0x018 [R] (UpdateSFXVolume)
    u32 m_loadMusic;  // 0x01C [R/W] (UpdateLoadMusic)
    u32 m_loadMusic_020;  // 0x020 [R/W] (UpdateLoadMusic)
    u32 m_loadMusic_024;  // 0x024 [R/W] (UpdateLoadMusic)
    u8 _pad_028[8];  // 0x028
    u32 m_field_030;  // 0x030 [R/W] (StartBuildBuyMusic, StartCASMusic)
};

#endif // CSOUNDMODEMANAGER_H
