#ifndef AMBIENTSOUNDPLAYER_H
#define AMBIENTSOUNDPLAYER_H

#include "types.h"

// AmbientSoundPlayer - struct layout extracted from assembly analysis
// Estimated minimum size: 0x30 (48 bytes)
// 13 known fields (12 named), 35 methods

class AmbientSoundPlayer {
public:
    // Constructors / Destructors
    AmbientSoundPlayer(void)  // 0x8020AF14
    ~AmbientSoundPlayer(void);  // 0x8020AFBC

    // Methods
    bool IsValid(void);  // 0x8020D7A4 (80B)
    void Update(void);  // 0x8020B0BC (260B)
    void Start(void);  // 0x8020B1C0 (1756B)
    void SetScorePlayer(AmbientScorePlayer *);  // 0x8020B064 (44B)
    void Pause(void);  // 0x8020BA1C (120B)
    void UnPause(void);  // 0x8020BA94 (120B)
    /* ? */ GetAmbientSound(void);  // 0x8020D6D8 (52B)
    void Stop(void);  // 0x8020B89C (384B)
    void SetAmbientSound(ERAmbientSound *);  // 0x8020B090 (44B)
    bool IsFinished(void);  // 0x8020D70C (152B)
    void UpdateSoundPosition(void);  // 0x8020C738 (144B)
    void UpdatePanAndVolume(void);  // 0x8020D0D0 (1268B)
    void SetInitialSoundPosition(void);  // 0x8020BB0C (3116B)
    void UpdateSoundVolume(void);  // 0x8020D5C4 (276B)
    void UpdateLoopingSoundPosition(void);  // 0x8020C7C8 (2312B)
    /* ? */ GetCurrentPosition(void);  // 0x8040A6EC (80B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (SetInitialSoundPosition, Start, UpdateLoopingSoundPosition, ...)
    u32 m_initialSoundPosition_004;  // 0x004 [R/W] (SetInitialSoundPosition, Start, UpdateLoopingSoundPosition, ...)
    u32 m_bIsFinished;  // 0x008 [R/W] (IsFinished, Pause, Start, ...)
    u32 m_panAndVolume;  // 0x00C [R/W] (UpdatePanAndVolume, UpdateSoundVolume)
    u32 m_panAndVolume_010;  // 0x010 [R/W] (Start, UpdatePanAndVolume)
    f32 m_initialSoundPosition_014;  // 0x014 [R/W] (SetInitialSoundPosition, Start, UpdateLoopingSoundPosition, ...)
    f32 m_initialSoundPosition_018;  // 0x018 [R/W] (SetInitialSoundPosition, Start, UpdateLoopingSoundPosition, ...)
    f32 m_initialSoundPosition_01C;  // 0x01C [W] (SetInitialSoundPosition, UpdateLoopingSoundPosition)
    f32 m_soundPosition;  // 0x020 [R/W] (Start, UpdateSoundPosition)
    f32 m_soundPosition_024;  // 0x024 [R/W] (Start, UpdateSoundPosition)
    u32 m_field_028;  // 0x028 [W] (Start)
    u8 m_soundVolume;  // 0x02A [R] (UpdateSoundVolume)
    u8 _pad_02B[1];  // 0x02B
    u32 m_panAndVolume_02C;  // 0x02C [R/W] (Start, Stop, UpdatePanAndVolume)
};

#endif // AMBIENTSOUNDPLAYER_H
