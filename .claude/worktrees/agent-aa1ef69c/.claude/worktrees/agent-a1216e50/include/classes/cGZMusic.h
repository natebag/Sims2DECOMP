#ifndef CGZMUSIC_H
#define CGZMUSIC_H

#include "types.h"

// cGZMusic - struct layout extracted from assembly analysis
// Estimated minimum size: 0x24 (36 bytes)
// 9 known fields (2 named), 48 methods

class cGZMusic {
public:
    // Constructors / Destructors
    cGZMusic(void)  // 0x80241DF8
    ~cGZMusic(void);  // 0x80241E88

    // Methods
    void setVolume(int);  // 0x80242610 (440B)
    void reset(void);  // 0x80242A70 (168B)
    void Init(void);  // 0x80241F5C (40B)
    void AddRef(void);  // 0x80241F84 (56B)
    void Release(void);  // 0x80241FBC (196B)
    void Play(void);  // 0x80242080 (708B)
    bool IsPlaying(void);  // 0x80242344 (44B)
    void Stop(void);  // 0x80242370 (144B)
    void Pause(void);  // 0x80242400 (152B)
    void Unpause(void);  // 0x80242498 (152B)
    void Load(void);  // 0x80242530 (40B)
    void Unload(void);  // 0x80242558 (40B)
    /* ? */ GetVolume(void);  // 0x80242580 (44B)
    void SetVolume(int);  // 0x802425AC (100B)
    void getLRVolume(void);  // 0x80242B18 (92B)
    void getPanSetting(void);  // 0x80242B74 (96B)
    void FadeVolume(int, int, unsigned int);  // 0x802427C8 (240B)
    /* ? */ GetPan(void);  // 0x802428B8 (40B)
    void SetPan(int);  // 0x802428E0 (272B)
    /* ? */ GetFrequency(void);  // 0x802429F0 (40B)
    void SetFrequency(int);  // 0x80242A18 (44B)
    void SetPosition(unsigned int);  // 0x80242A44 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Play, Release, cGZMusic, ...)
    u32 m_field_004;  // 0x004 [R/W] (Release, cGZMusic)
    u32 m_field_008;  // 0x008 [R/W] (Play, Stop, cGZMusic)
    u32 m_field_00C;  // 0x00C [R] (Play)
    u32 m_field_010;  // 0x010 [R] (Play)
    u32 m_field_014;  // 0x014 [W] (FadeVolume, cGZMusic, setVolume)
    u32 m_pan;  // 0x018 [R/W] (SetPan, cGZMusic, getPanSetting)
    f32 m_field_01C;  // 0x01C [W] (cGZMusic)
    u32 m_field_020;  // 0x020 [R/W] (FadeVolume, Play, cGZMusic, ...)
};

#endif // CGZMUSIC_H
