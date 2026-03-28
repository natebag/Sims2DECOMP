#ifndef GAMESOUND_H
#define GAMESOUND_H

#include "types.h"

// Forward declarations
class ERSoundEvent;
class cBoxX;
class cSoundModeManager;

// Sound mode enum from map symbols
namespace snd {
    enum eMode {
        eMode_Normal = 0,
        eMode_1 = 1,
        eMode_2 = 2,
        eMode_3 = 3,
        eMode_4 = 4,
        eMode_DiscError = 5,
    };
}

// SoundEventInfo - linked list node for sound events
// 20 bytes (0x14) per entry
struct SoundEventInfo {
    SoundEventInfo* m_prev;  // +0x00
    SoundEventInfo* m_next;  // +0x04
    int m_sourceId;          // +0x08
    float m_field_0C;        // +0x0C
    int m_field_10;          // +0x10
};

// OptionsRecon - forward declared, used by Get*Volume functions
// Layout (partial, from Get*Volume offsets):
//   +0x0C: int m_freeplayUnlocked
//   +0x1C: s8 m_sfxVolume
//   +0x1D: s8 m_musicVolume
//   +0x28: s8 m_voxVolume
//   +0x29: s8 m_ambientVolume
class OptionsRecon;

// cSoundPlayer class
// Object file: gamesound.obj
//
// Memory layout (from constructor/disassembly):
//   +0x00: int m_initialized       (0 = not initialized)
//   +0x04: void* m_soundSystem     (cBoxX/sound engine ptr)
//   +0x08: int m_soundEnabled
//   +0x0C: int m_isPaused
//   +0x10: int m_field_10          (saved volume or mode)
//   +0x14: int m_field_14
//   +0x18: list<SoundEventInfo> m_eventList  (8 bytes: sentinel node ptr + ?)
//       +0x18: int m_listField_00
//       +0x1C: SoundEventInfo* m_listSentinel
//   +0x20-0x2F: additional list/allocator fields
//   +0x30: snd::eMode m_gameMode
//
// Total size: ~52 bytes
class cSoundPlayer {
public:
    int m_initialized;       // +0x00
    void* m_soundSystem;     // +0x04 (cBoxX*)
    int m_soundEnabled;      // +0x08
    int m_isPaused;          // +0x0C
    int m_savedVolume;       // +0x10
    int m_field_14;          // +0x14
    // list at +0x18
    int m_listField_00;      // +0x18
    void* m_listSentinel;    // +0x1C
    int m_field_20;          // +0x20
    int m_field_24;          // +0x24
    int m_field_28;          // +0x28
    int m_field_2C;          // +0x2C
    snd::eMode m_gameMode;   // +0x30

    cSoundPlayer();
    ~cSoundPlayer();

    void Initialize();
    void Shutdown();
    void KillSourceEvent(int sourceId);
    void KillAllEvent();
    void Update();

    snd::eMode GetGameMode();
    void SetGameMode(snd::eMode mode);
    void EnableSound(bool enable);
    void QuietAll();

    void PlayBySource(unsigned int soundId, short sourceId);
    void PlayBySource(char* name, short sourceId);
    void PlayBySource(ERSoundEvent* event, short sourceId);
    void QuietBySourceID(int sourceId);

    void PauseSFX();
    void ResumeSFX();
    void PauseMusic();
    void ResumeMusic();
    void PauseSounds();
    void ResumeSounds();

    void NotifyViewChange();
    void NotifyHourChange();

    s8 GetSFXVolume();
    s8 GetMusicVolume();
    s8 GetVOXVolume();
    s8 GetAmbientVolume();

    void SetOldFXVolume(int volume);
    void SetMusicVolume(int volume);
    void SetSFXVolume(int volume);
    void SetVOXVolume(int volume);
    void SetAmbientVolume(int volume);
};

// Global callback
void DiscErrorCallback(bool isError);

#endif // GAMESOUND_H
