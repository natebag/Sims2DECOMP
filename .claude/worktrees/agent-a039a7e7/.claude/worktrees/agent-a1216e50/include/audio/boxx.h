#ifndef BOXX_H
#define BOXX_H

#include "types.h"

// Forward declarations
class ERSoundEvent;
class ESimsCam;
class AmbientScorePlayer;
class cSoundModeManager;
class cTrack;
struct EVec3;

// ============================================================================
// cBoxX - Main sound engine
// Object file: boxx.obj
//
// Layout (from disassembly):
//   +0x30: cSoundModeManager m_soundModeManager (embedded)
//   +0x64: AmbientScorePlayer* m_ambientScorePlayer
//   +0x74: int m_ambientPauseCount
// ============================================================================
class cBoxX {
public:
    u8  m_pad00[0x30];
    u8  m_soundModeManager[0x34];      // +0x30 - embedded cSoundModeManager
    AmbientScorePlayer* m_ambientScorePlayer; // +0x64
    u8  m_pad68[0x0C];
    int m_ambientPauseCount;           // +0x74

    cBoxX();
    ~cBoxX();
    void Init();
    void LoadQdataTables();
    void Shutdown();
    void Update(unsigned int dt);
    void UpdateGameMode();
    void Event(int type, int param1, int param2, ERSoundEvent* event, float vol);
    void MappedEvent(ERSoundEvent* event, int param, float vol);
    void GetListenerPosAndDir(ESimsCam* cam, EVec3& pos, EVec3& dir);
    void GetSurroundVol(AmbientScorePlayer* player, EVec3& pos, float range, float vol, int& fl, int& fr, int& rl, int& rr);
    void GetSurroundVol(EVec3& pos, float range, float vol, int& fl, int& fr, int& rl, int& rr, int mode);
    void CalculateSurroundVol(EVec3& listenerPos, EVec3& listenerDir, EVec3& sourcePos, float range, float vol, int& fl, int& fr, int& rl, int& rr);
    void GetInstanceSurroundVol(int instance, cTrack* track, int& fl, int& fr, int& rl, int& rr);
    void GetInstanceVolNoPan(int instance, cTrack* track, int& vol);
    void ConvertSurroundToVolPan(int fl, int fr, int rl, int rr, int& vol, int& pan);
    void Pause();
    void Unpause();
    void PauseAmbient();
    void UnpauseAmbient();
    void PauseSFX();
    void UnpauseSFX();
    void PauseMusic();
    void UnpauseMusic();
    void SetAmbientScore(int score);
    void SetAmbientScoreVolume(int vol);
    int GetAmbientScoreVolume();
    void FindSndobInstancePair(ERSoundEvent* event, int instance);
    void UpdateSndobVolPan(ERSoundEvent* event);
    void UpdateAllSndobVolPan();
    void GetSndobSurroundVols(ERSoundEvent* event, int& fl, int& fr, int& rl, int& rr);
    void AddToInstanceMap(ERSoundEvent* event, int instance);
    void CheckForTooManySounds();
    void KillSource(int source);
};

// ============================================================================
// cSoundModeManager - Manages sound mode transitions
// Object file: boxx.obj
//
// Layout (from disassembly):
//   +0x04: int m_musicFadeOut
//   +0x08: int m_musicFadeIn
//   +0x0C: unsigned int m_musicFadeDuration
//   +0x10: int m_sfxFadeOut
//   +0x14: int m_sfxFadeIn
//   +0x18: unsigned int m_sfxFadeDuration
//   +0x28: int m_frontEndTrackIndex
//   +0x2C: int m_demoTrackIndex
// Size: >= 0x30
// ============================================================================
class cSoundModeManager {
public:
    u8  m_pad00[0x04];
    int m_musicFadeOut;             // +0x04
    int m_musicFadeIn;              // +0x08
    unsigned int m_musicFadeDuration; // +0x0C
    int m_sfxFadeOut;               // +0x10
    int m_sfxFadeIn;                // +0x14
    unsigned int m_sfxFadeDuration; // +0x18
    u8  m_pad1C[0x0C];
    int m_frontEndTrackIndex;       // +0x28
    int m_demoTrackIndex;           // +0x2C

    cSoundModeManager();
    void SetMode(int mode);
    void Update();
    void Pause();
    void Unpause();
    void Shutdown();
    void FadeOutMusic(unsigned int duration);
    void FadeInMusic(unsigned int duration);
    void FadeOutSFX(unsigned int duration);
    void FadeInSFX(unsigned int duration);
    char* GetFrontEndMusicTrack(bool current);
    void NextFrontEndTrack();
    void PrevFrontEndTrack();
    void StartFrontEndMusic(bool useCurrent);
    char* GetDemoMusicTrack();
    void NextDemoMusicTrack();
    void StartDemoMusic();
    void StartMusicTrack(char* name, float volume);
    void StartBuildBuyMusic();
    void StartCASMusic();
    void UpdateMusicVolume();
    void UpdateSFXVolume();
    void UpdateLoadMusic();
};

// Front end music tracks table (at 0x8042401C)
extern char* s_frontEndTracks[];

// Globals
extern int g_demoMusic;            // 0x804FDBB0
extern int g_social_duck;          // 0x804FDBB4
extern int g_cam_height;           // 0x804FDBB8
extern int g_cam_dist;             // 0x804FDBBC
extern int g_footstepAll;          // 0x804FDBC0
extern int g_displayFootstepDebug; // 0x804FDBC4
extern int g_bBoxXIsInitted;       // 0x804FDBC8
extern cBoxX* g_pBoxX;            // 0x804FF964

#endif // BOXX_H
