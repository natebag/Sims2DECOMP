#ifndef AMBIENTSCOREPLAYER_H
#define AMBIENTSCOREPLAYER_H

#include "types.h"

// AmbientScorePlayer - struct layout extracted from assembly analysis
// Estimated minimum size: 0x3C (60 bytes)
// 14 known fields (6 named), 52 methods

class AmbientScorePlayer {
public:
    // Static members (from map file)
    // static ??? s_ambientDatabase;

    // Constructors / Destructors
    AmbientScorePlayer(bool)  // 0x80206D74
    ~AmbientScorePlayer(void);  // 0x80206E44

    // Methods
    void Shutdown(void);  // 0x802077F8 (264B)
    void Update(void);  // 0x80206EAC (784B)
    void RemoveFinishedSounds(void);  // 0x80208A28 (528B)
    void SoundRangeCoversCurTime(ERAmbientSound *);  // 0x80207BD8 (380B)
    void SoundAlreadyPlaying(ERAmbientSound *);  // 0x80207D54 (188B)
    void SoundInHearingDistance(ERAmbientSound *);  // 0x80207E10 (1364B)
    void AddSoundBasedOnProbability(vector<ERAmbientSound *, allocator<ERAmbientSound *> > &, int, bool);  // 0x80208364 (308B)
    void SetListenerCount(int);  // 0x802071BC (68B)
    void UpdateListener(unsigned int, EVec3 &, EVec3 &);  // 0x80207200 (668B)
    void SetTime(float);  // 0x8020749C (44B)
    /* ? */ GetTime(void);  // 0x802074C8 (44B)
    void Load(char *);  // 0x802074F4 (604B)
    void KillAllAmbientSounds(void);  // 0x80208498 (356B)
    void Start(void);  // 0x80207750 (76B)
    void Stop(void);  // 0x8020779C (92B)
    void SetPause(bool);  // 0x80207900 (372B)
    void SetVolume(int);  // 0x80207A74 (180B)
    /* ? */ GetVolume(void);  // 0x80207B28 (44B)
    /* ? */ GetAmbientScore(void);  // 0x80207B54 (44B)
    /* ? */ GetNumPlaying(void);  // 0x80207B80 (44B)
    /* ? */ GetListenerInfos(void);  // 0x80207BAC (44B)
    void AddNewAmbientSoundPlayer(ERAmbientSound *);  // 0x802085FC (500B)
    void RemoveAmbientSoundPlayer(ERAmbientSound *);  // 0x802087F0 (568B)
    void ResetLastUpdateTime(void);  // 0x8040A768 (64B)
    /* ? */ GetAmbientSoundPlayers(void);  // 0x8040A73C (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AmbientScorePlayer, SetPause, Update, ...)
    u32 m_listenerCount;  // 0x004 [R/W] (AmbientScorePlayer, SetListenerCount)
    u32 m_field_008;  // 0x008 [R/W] (AmbientScorePlayer, Load, Shutdown, ...)
    u32 m_pause_00C;  // 0x00C [R/W] (AddNewAmbientSoundPlayer, AmbientScorePlayer, KillAllAmbientSounds, ...)
    u32 m_field_010;  // 0x010 [R/W] (AddNewAmbientSoundPlayer, AmbientScorePlayer, KillAllAmbientSounds, ...)
    u32 m_field_014;  // 0x014 [W] (AmbientScorePlayer)
    u32 m_field_018;  // 0x018 [R/W] (AmbientScorePlayer, Load, Update)
    u8 m_field_019;  // 0x019 [R] (RemoveFinishedSounds)
    u8 _pad_01A[2];  // 0x01A
    u32 m_pause_01C;  // 0x01C [R/W] (AddNewAmbientSoundPlayer, AmbientScorePlayer, KillAllAmbientSounds, ...)
    u32 m_listenerCount_020;  // 0x020 [R/W] (AmbientScorePlayer, SetListenerCount, SoundInHearingDistance, ...)
    u32 m_listener;  // 0x024 [R] (SoundInHearingDistance, UpdateListener)
    u8 _pad_028[8];  // 0x028
    u32 m_field_030;  // 0x030 [W] (AmbientScorePlayer)
    f32 m_field_034;  // 0x034 [R/W] (AmbientScorePlayer, SoundRangeCoversCurTime)
    u32 m_field_038;  // 0x038 [R/W] (AmbientScorePlayer, Update)
};

#endif // AMBIENTSCOREPLAYER_H
