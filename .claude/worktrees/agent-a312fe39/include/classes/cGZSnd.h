#ifndef CGZSND_H
#define CGZSND_H

#include "types.h"

// cGZSnd - struct layout extracted from assembly analysis
// Estimated minimum size: 0x3C (60 bytes)
// 16 known fields (7 named), 46 methods

class cGZSnd {
public:
    // Constructors / Destructors
    cGZSnd(void)  // 0x80240B24
    ~cGZSnd(void);  // 0x80240BC4

    // Methods
    void setVolume(int);  // 0x80241580 (308B)
    void getLRVolume(int, float &, float &);  // 0x80241A6C (908B)
    void reset(void);  // 0x802419CC (160B)
    void Init(void);  // 0x80240C98 (40B)
    void Release(void);  // 0x80240CC0 (292B)
    void AddRef(void);  // 0x80240DE4 (56B)
    void Play(void);  // 0x80240E1C (792B)
    bool IsPlaying(void);  // 0x80241134 (228B)
    void Stop(void);  // 0x80241218 (300B)
    void Pause(void);  // 0x80241344 (168B)
    void Unpause(void);  // 0x802413EC (168B)
    void Load(void);  // 0x80241494 (40B)
    void Unload(void);  // 0x802414BC (40B)
    /* ? */ GetVolume(void);  // 0x802414E4 (44B)
    void SetVolume(int);  // 0x80241510 (112B)
    void FadeVolume(int, int, unsigned int);  // 0x802416B4 (168B)
    /* ? */ GetPan(void);  // 0x8024175C (44B)
    void SetPan(int);  // 0x80241788 (452B)
    /* ? */ GetFrequency(void);  // 0x8024194C (40B)
    void SetFrequency(int);  // 0x80241974 (44B)
    void SetPosition(unsigned int);  // 0x802419A0 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Play, Release, cGZSnd, ...)
    f32 m_field_004;  // 0x004 [R/W] (Play, Release, cGZSnd)
    f32 m_field_008;  // 0x008 [W] (Play)
    f32 m_bIsPlaying;  // 0x00C [R/W] (IsPlaying, Play, Stop)
    u32 m_field_010;  // 0x010 [R/W] (Pause, Play, Unpause)
    u32 m_field_014;  // 0x014 [R] (Play)
    u8 m_field_017;  // 0x017 [R] (Play)
    u32 m_bIsPlaying_018;  // 0x018 [R/W] (IsPlaying, Play, reset)
    u32 m_pan;  // 0x01C [R/W] (IsPlaying, Pause, Play, ...)
    u32 m_pan_020;  // 0x020 [R/W] (Release, SetPan, cGZSnd, ...)
    u32 m_pan_024;  // 0x024 [R/W] (SetPan, cGZSnd, getLRVolume)
    f32 m_field_028;  // 0x028 [R/W] (cGZSnd, getLRVolume)
    f32 m_field_02C;  // 0x02C [R/W] (cGZSnd, getLRVolume)
    f32 m_field_030;  // 0x030 [R/W] (Play, cGZSnd)
    u32 m_pan_034;  // 0x034 [R/W] (FadeVolume, Release, SetPan, ...)
    u32 m_field_038;  // 0x038 [R/W] (Play, cGZSnd, setVolume)
};

#endif // CGZSND_H
