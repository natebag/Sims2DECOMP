#ifndef ENGCAUDIO_H
#define ENGCAUDIO_H

#include "types.h"

// ENgcAudio - struct layout extracted from assembly analysis
// Estimated minimum size: 0x60 (96 bytes)
// 11 known fields (4 named), 58 methods

class ENgcAudio {
public:
    // Constructors / Destructors
    ENgcAudio(void)  // 0x808A2088
    ~ENgcAudio(void);  // 0x808A211C

    // Methods
    void SetDiscErrorCallback(void (*);  // 0x808A422C (44B)
    void InitAudio(void);  // 0x808A2250 (428B)
    void AudioAlarmHandler(OSAlarm *, OSContext *);  // 0x808A23FC (36B)
    void Shutdown(void);  // 0x808A2420 (180B)
    void PlayMusic(EPMDesc &);  // 0x808A24D4 (1932B)
    /* ? */ GetIndexFromVoice(EVoice *);  // 0x808A2C60 (44B)
    /* ? */ GetVoiceFromIndex(unsigned char);  // 0x808A2C8C (52B)
    void Update(void);  // 0x808A2CC0 (1284B)
    void StopMusic(void);  // 0x808A31C4 (320B)
    void PauseMusic(void);  // 0x808A3304 (228B)
    void ResumeMusic(void);  // 0x808A33E8 (228B)
    void SetMusicVolume(float);  // 0x808A34CC (340B)
    /* ? */ GetMusicVolume(void);  // 0x808A3620 (52B)
    void SetMusicPan(float);  // 0x808A3654 (524B)
    /* ? */ GetMusicPan(void);  // 0x808A3860 (52B)
    bool IsPlayingMusic(void);  // 0x808A3894 (132B)
    void AudioAllocVoice(char *, int);  // 0x808A397C (96B)
    void FreeVoice(EVoice *);  // 0x808A39DC (108B)
    void AudioBindVoice(EVoice *, unsigned int, char *, int);  // 0x808A3A48 (656B)
    void UnbindVoice(EVoice *);  // 0x808A3CD8 (276B)
    /* ? */ GetVoiceState(EVoice *, EVoiceDesc &);  // 0x808A3DEC (248B)
    void SetVoiceState(EVoice *, EVoiceDesc &);  // 0x808A3EE4 (632B)
    void SetSpeakerVolumes(EVoice *, int *, unsigned int);  // 0x808A415C (164B)
    bool IsPausedDueToDiscError(void);  // 0x808A4200 (44B)
    void Flush(bool);  // 0x808A445C (36B)
    void AddEvent(EA_EVENT, EMsgQueue &, unsigned int);  // 0x808A4480 (44B)
    void RemoveEvent(EA_EVENT, EMsgQueue &, unsigned int);  // 0x808A44AC (44B)
    void AudioAllocVoice(void);  // 0x80504FF8 (64B)
    void AudioBindVoice(EVoice *, unsigned int);  // 0x80505080 (412B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AudioBindVoice, ENgcAudio, FreeVoice, ...)
    f32 m_musicVolume;  // 0x004 [R/W] (ENgcAudio, PlayMusic, SetMusicVolume)
    f32 m_musicPan;  // 0x008 [W] (ENgcAudio, SetMusicPan)
    u32 m_bIsPlayingMusic;  // 0x00C [R/W] (InitAudio, IsPlayingMusic, PauseMusic, ...)
    u8 _pad_010[4];  // 0x010
    u32 m_field_014;  // 0x014 [R] (PlayMusic)
    u32 m_field_018;  // 0x018 [R] (PlayMusic)
    u32 m_field_01C;  // 0x01C [R] (AudioBindVoice, PlayMusic)
    u8 _pad_020[0x18];  // 0x020
    u32 m_field_038;  // 0x038 [R/W] (ENgcAudio, Update)
    u32 m_field_03C;  // 0x03C [R/W] (ENgcAudio, Update)
    u32 m_field_040;  // 0x040 [R] (PlayMusic, StopMusic, Update)
    u8 _pad_044[0x18];  // 0x044
    u32 m_field_05C;  // 0x05C [R] (AudioBindVoice, UnbindVoice)
};

#endif // ENGCAUDIO_H
