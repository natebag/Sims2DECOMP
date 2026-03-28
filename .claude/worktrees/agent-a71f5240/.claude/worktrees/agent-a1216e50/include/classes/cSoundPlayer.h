#ifndef CSOUNDPLAYER_H
#define CSOUNDPLAYER_H

#include "types.h"

// cSoundPlayer - struct layout extracted from assembly analysis
// Estimated minimum size: 0x20 (32 bytes)
// 7 known fields (2 named), 65 methods

class cSoundPlayer {
public:
    // Constructors / Destructors
    cSoundPlayer(void)  // 0x80237C2C
    ~cSoundPlayer(void);  // 0x80237CD4

    // Methods
    bool IsPaused(void);  // 0x80224E14 (44B)
    void Update(void);  // 0x802382B0 (596B)
    void SetGameMode(snd::eMode);  // 0x80238504 (196B)
    void ResumeSounds(void);  // 0x80238CA8 (176B)
    void PlayBySource(char *, short);  // 0x8023880C (168B)
    void PauseSounds(void);  // 0x80238BF0 (184B)
    void QuietBySourceID(int);  // 0x80238958 (120B)
    void QuietAll(void);  // 0x802386A8 (140B)
    void EnableSound(bool);  // 0x80238630 (120B)
    void NotifyViewChange(void);  // 0x80238D58 (116B)
    void SetOldFXVolume(int);  // 0x80238F30 (176B)
    /* ? */ GetGameMode(void);  // 0x802385C8 (104B)
    void KillAllEvent(void);  // 0x80238180 (304B)
    void KillSourceEvent(int);  // 0x80238020 (352B)
    void Initialize(void);  // 0x80237DA0 (328B)
    void Shutdown(void);  // 0x80237EE8 (312B)
    void PlayBySource(unsigned int, short);  // 0x80238734 (216B)
    void PlayBySource(ERSoundEvent *, short);  // 0x802388B4 (164B)
    void PauseSFX(void);  // 0x802389D0 (140B)
    void ResumeSFX(void);  // 0x80238A5C (132B)
    void PauseMusic(void);  // 0x80238AE0 (140B)
    void ResumeMusic(void);  // 0x80238B6C (132B)
    void NotifyHourChange(void);  // 0x80238DCC (116B)
    /* ? */ GetSFXVolume(void);  // 0x80238E40 (60B)
    /* ? */ GetMusicVolume(void);  // 0x80238E7C (60B)
    /* ? */ GetVOXVolume(void);  // 0x80238EB8 (60B)
    /* ? */ GetAmbientVolume(void);  // 0x80238EF4 (60B)
    void SetMusicVolume(int);  // 0x80238FE0 (140B)
    void SetSFXVolume(int);  // 0x8023906C (140B)
    void SetVOXVolume(int);  // 0x802390F8 (140B)
    void SetAmbientVolume(int);  // 0x80239184 (140B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (EnableSound, Initialize, KillAllEvent, ...)
    u32 m_field_004;  // 0x004 [R/W] (Initialize, KillAllEvent, KillSourceEvent, ...)
    u32 m_musicVolume_008;  // 0x008 [R/W] (EnableSound, Initialize, NotifyHourChange, ...)
    u32 m_field_00C;  // 0x00C [R/W] (PauseSounds, ResumeSounds, Update, ...)
    f32 m_field_010;  // 0x010 [R/W] (KillAllEvent, KillSourceEvent, QuietAll, ...)
    u32 m_field_014;  // 0x014 [W] (KillAllEvent)
    u8 _pad_018[4];  // 0x018
    u32 m_field_01C;  // 0x01C [R] (PlayBySource, QuietAll)
};

#endif // CSOUNDPLAYER_H
