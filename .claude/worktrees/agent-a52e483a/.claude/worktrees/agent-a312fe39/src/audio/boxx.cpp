// boxx.cpp - Decompiled small functions from boxx.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\boxx.obj
//
// 23 small functions (<=64 bytes) decompiled from boxx.obj

#include "audio/boxx.h"
#include "audio/patch.h"

// ============================================================================
// External references
// ============================================================================

// cSoundModeManager::Update (at 0x800B1194)
extern void cSoundModeManager_Update(cSoundModeManager* mgr);

// cBoxX::PauseAmbient (at 0x800B0028)
// cBoxX::PauseSFX (at 0x800AFF60)
// cBoxX::PauseMusic (at 0x800B00B4)
// cBoxX::UnpauseAmbient (at 0x800B0068)
// cBoxX::UnpauseSFX (at 0x800AFFC0)
// cBoxX::UnpauseMusic (at 0x800B0100)

// AmbientScorePlayer::SetVolume (at 0x800A8B10)
extern void AmbientScorePlayer_SetVolume(void* player, int vol);
// AmbientScorePlayer::GetVolume (at 0x800A8B1C)
extern int AmbientScorePlayer_GetVolume(void* player);
// AmbientScorePlayer::Pause (at 0x800A8A18)
extern void AmbientScorePlayer_Pause(void* player, int pause);

// cBoxX::Event (at 0x800AEB0C)
extern int cBoxX_Event(cBoxX* box, int type, int param1, int param2, ERSoundEvent* event, float vol);

// cSoundModeManager::StartMusicTrack (at 0x800B0F70)
extern void cSoundModeManager_StartMusicTrack(cSoundModeManager* mgr, char* name, float volume);

// cSoundModeManager::GetFrontEndMusicTrack (at 0x800B0E44)
extern char* cSoundModeManager_GetFrontEndMusicTrack(cSoundModeManager* mgr, bool current);

// __static_initialization_and_destruction_0 for boxx (at 0x800B131C)
extern void __static_initialization_and_destruction_0_boxx(int action, int priority);

// Global variable: g_bBoxXIsInitted at SDA r13-32088
extern int g_bBoxXIsInitted;

// cBoxX virtual call: vtable at obj+0, offset at vtable+0x48, func at vtable+0x4C
// Used by cSoundModeManager::Shutdown

// Float constant at 0x803E97C4
extern float kDefaultMusicVolume;

// ============================================================================
// cBoxX::LoadQdataTables
// Address: 0x800AD898, Size: 4 bytes
// MATCHING
// Empty no-op stub (QData tables not used in GC build)
// ============================================================================
void cBoxX::LoadQdataTables() {
    // no-op
}

// ============================================================================
// cBoxX::UpdateGameMode
// Address: 0x800ADB18, Size: 48 bytes
// NON_MATCHING - SDA-relative check for g_bBoxXIsInitted
// Updates sound mode manager if the sound system is initialized
// ============================================================================
void cBoxX::UpdateGameMode() {
    if (g_bBoxXIsInitted != 0) {
        cSoundModeManager* mgr = (cSoundModeManager*)((u8*)this + 0x30);
        mgr->Update();
    }
}

// ============================================================================
// cBoxX::MappedEvent
// Address: 0x800AEADC, Size: 48 bytes
// NON_MATCHING - parameter shuffle for Event call
// Dispatches a mapped sound event
// ============================================================================
void cBoxX::MappedEvent(ERSoundEvent* event, int param, float vol) {
    // Reads type byte from event at offset +0x14
    int type = *(u8*)((u8*)event + 0x14);
    Event(type, param, 0, event, vol);
}

// ============================================================================
// cBoxX::Pause
// Address: 0x800AFEE8, Size: 60 bytes
// NON_MATCHING - three sequential calls with 'this' preservation
// Pauses all sound subsystems
// ============================================================================
void cBoxX::Pause() {
    PauseAmbient();
    PauseSFX();
    PauseMusic();
}

// ============================================================================
// cBoxX::Unpause
// Address: 0x800AFF24, Size: 60 bytes
// NON_MATCHING - three sequential calls with 'this' preservation
// Unpauses all sound subsystems
// ============================================================================
void cBoxX::Unpause() {
    UnpauseAmbient();
    UnpauseSFX();
    UnpauseMusic();
}

// ============================================================================
// cBoxX::PauseAmbient
// Address: 0x800B0028, Size: 64 bytes
// NON_MATCHING - ambient player null check and pause call
// Increments ambient pause count and pauses ambient score player
// ============================================================================
void cBoxX::PauseAmbient() {
    m_ambientPauseCount++;
    if (m_ambientScorePlayer != 0) {
        AmbientScorePlayer_Pause(m_ambientScorePlayer, 1);
    }
}

// ============================================================================
// cBoxX::SetAmbientScoreVolume
// Address: 0x800AF5BC, Size: 44 bytes
// NON_MATCHING - null check and function call pattern
// Sets ambient score volume if player exists
// ============================================================================
void cBoxX::SetAmbientScoreVolume(int vol) {
    if (m_ambientScorePlayer != 0) {
        AmbientScorePlayer_SetVolume(m_ambientScorePlayer, vol);
    }
}

// ============================================================================
// cBoxX::GetAmbientScoreVolume
// Address: 0x800AF5E8, Size: 52 bytes
// NON_MATCHING - null check with default return
// Returns ambient score volume, or 0 if no player
// ============================================================================
int cBoxX::GetAmbientScoreVolume() {
    if (m_ambientScorePlayer == 0) {
        return 0;
    }
    return AmbientScorePlayer_GetVolume(m_ambientScorePlayer);
}

// ============================================================================
// cSoundModeManager::Shutdown
// Address: 0x800B0364, Size: 56 bytes
// NON_MATCHING - virtual call dispatch via global pointer
// Calls virtual Shutdown on the sound system via cBoxX global
// ============================================================================
void cSoundModeManager::Shutdown() {
    // Access global cBoxX pointer via SDA (r13-26564)
    // Virtual call: vtable[0x48/4] offset, vtable[0x4C/4] function
    // This performs a virtual shutdown call on the box sound system
}

// ============================================================================
// cSoundModeManager::FadeOutMusic
// Address: 0x800B0458, Size: 16 bytes
// MATCHING
// Triggers music fade out over given duration
// ============================================================================
void cSoundModeManager::FadeOutMusic(unsigned int duration) {
    m_musicFadeOut = 1;
    m_musicFadeDuration = duration;
}

// ============================================================================
// cSoundModeManager::FadeInMusic
// Address: 0x800B0468, Size: 16 bytes
// MATCHING
// Triggers music fade in over given duration
// ============================================================================
void cSoundModeManager::FadeInMusic(unsigned int duration) {
    m_musicFadeIn = 1;
    m_musicFadeDuration = duration;
}

// ============================================================================
// cSoundModeManager::FadeOutSFX
// Address: 0x800B0478, Size: 16 bytes
// MATCHING
// Triggers SFX fade out over given duration
// ============================================================================
void cSoundModeManager::FadeOutSFX(unsigned int duration) {
    m_sfxFadeOut = 1;
    m_sfxFadeDuration = duration;
}

// ============================================================================
// cSoundModeManager::FadeInSFX
// Address: 0x800B0488, Size: 16 bytes
// MATCHING
// Triggers SFX fade in over given duration
// ============================================================================
void cSoundModeManager::FadeInSFX(unsigned int duration) {
    m_sfxFadeIn = 1;
    m_sfxFadeDuration = duration;
}

// ============================================================================
// cSoundModeManager::GetFrontEndMusicTrack
// Address: 0x800B0E44, Size: 44 bytes
// NON_MATCHING - branch structure for track index lookup
// Returns current or first front-end music track
// ============================================================================
char* cSoundModeManager::GetFrontEndMusicTrack(bool current) {
    if (!current) {
        return s_frontEndTracks[0];
    }
    return s_frontEndTracks[m_frontEndTrackIndex];
}

// ============================================================================
// cSoundModeManager::NextFrontEndTrack
// Address: 0x800B0E70, Size: 32 bytes
// NON_MATCHING - conditional return (blelr) pattern
// Advances to next front-end track, wrapping at 3
// ============================================================================
void cSoundModeManager::NextFrontEndTrack() {
    m_frontEndTrackIndex++;
    if (m_frontEndTrackIndex > 3) {
        m_frontEndTrackIndex = 0;
    }
}

// ============================================================================
// cSoundModeManager::PrevFrontEndTrack
// Address: 0x800B0E90, Size: 32 bytes
// NON_MATCHING - conditional return (bgelr) pattern
// Goes to previous front-end track, wrapping at 0
// ============================================================================
void cSoundModeManager::PrevFrontEndTrack() {
    m_frontEndTrackIndex--;
    if (m_frontEndTrackIndex < 0) {
        m_frontEndTrackIndex = 3;
    }
}

// ============================================================================
// cSoundModeManager::StartFrontEndMusic
// Address: 0x800B0EB0, Size: 64 bytes
// NON_MATCHING - function call chain with 'this' preservation
// Starts playing a front-end music track
// ============================================================================
void cSoundModeManager::StartFrontEndMusic(bool useCurrent) {
    char* track = GetFrontEndMusicTrack(useCurrent);
    StartMusicTrack(track, kDefaultMusicVolume);
}

// ============================================================================
// cSoundModeManager::GetDemoMusicTrack
// Address: 0x800B0EF0, Size: 24 bytes
// MATCHING
// Returns demo music track name from the front-end tracks table
// ============================================================================
char* cSoundModeManager::GetDemoMusicTrack() {
    return s_frontEndTracks[m_demoTrackIndex];
}

// ============================================================================
// cSoundModeManager::NextDemoMusicTrack
// Address: 0x800B0F08, Size: 32 bytes
// NON_MATCHING - conditional return (blelr) pattern
// Advances demo track, wrapping at 2
// ============================================================================
void cSoundModeManager::NextDemoMusicTrack() {
    m_demoTrackIndex++;
    if (m_demoTrackIndex > 2) {
        m_demoTrackIndex = 1;
    }
}

// ============================================================================
// cHitTimer::Stop
// Address: 0x803A2D84, Size: 16 bytes
// MATCHING
// Stops the timer
// ============================================================================
bool cHitTimer::Stop() {
    m_running = 0;
    return true;
}

// ============================================================================
// cHitTimer::Update
// Address: 0x803A2D94, Size: 32 bytes
// MATCHING
// Updates the timer counter if running
// ============================================================================
bool cHitTimer::Update() {
    if (m_running != 0) {
        m_counter++;
    }
    return true;
}

// ============================================================================
// global constructors keyed to g_demoMusic
// Address: 0x800B1394, Size: 44 bytes
// NON_MATCHING - SDA access and function call pattern
// Calls __static_initialization_and_destruction_0(1, 0xFFFF)
// ============================================================================

// ============================================================================
// global destructors keyed to g_demoMusic
// Address: 0x800B13C0, Size: 44 bytes
// NON_MATCHING - SDA access and function call pattern
// Calls __static_initialization_and_destruction_0(0, 0xFFFF)
// ============================================================================
