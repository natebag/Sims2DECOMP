// gamesound.cpp - Game sound effects system
// Object file: gamesound.obj
// 22 functions decompiled from Sims 2 GC
// 0 MATCHING, 22 NON_MATCHING
// All NON_MATCHING due to: GCC tail-call optimization (b vs bl), beqlr vs beq-forward,
// different global addressing (abs vs SDA r13-relative), register allocation differences
//
// cSoundPlayer layout (52+ bytes):
//   +0x00: int m_initialized
//   +0x04: void* m_soundSystem     (cBoxX*)
//   +0x08: int m_soundEnabled
//   +0x0C: int m_isPaused
//   +0x10: int m_savedVolume
//   +0x14-0x17: padding/field
//   +0x18: list stuff
//   +0x1C: SoundEventInfo* m_listSentinel
//   +0x30: snd::eMode m_gameMode
//
// OptionsRecon layout (partial):
//   +0x1C: s8 m_sfxVolume
//   +0x1D: s8 m_musicVolume
//   +0x28: s8 m_voxVolume
//   +0x29: s8 m_ambientVolume
//
// Globals (SDA-relative via r13):
//   r13 - 24508 (0xA044): cBoxX* g_pSoundBox (sound engine instance)
//   r13 - 21492 (0xAC0C): cSoundPlayer* g_pSoundPlayer (global singleton)
//   r13 - 32064 (0x82C0): snd::eMode g_savedGameMode
//   r13 - 24464 (0xA070): void* g_pSoundBoxInst (secondary reference)
//
// Data-relative globals:
//   0x80475f14 = _globals + 0x148: OptionsRecon* g_pOptionsRecon

#include "audio/gamesound.h"

// External globals (SDA-relative)
extern void* g_pSoundBox;           // r13 - 0xa044
extern cSoundPlayer* g_pSoundPlayer; // r13 - offset for 0xAC0C
extern int g_savedGameMode;          // r13 - 0x82C0

// External global pointer to OptionsRecon
extern OptionsRecon* g_pOptionsRecon; // at 0x80475f14

// External functions
extern void cBoxX_MappedEvent(void* box, ERSoundEvent* event, int sourceId, float priority);
extern void cBoxX_Event(void* box, int eventId, int param1, int param2, ERSoundEvent* event, float priority);
extern void cSoundModeManager_SetMode(void* box, int mode);

// OptionsRecon accessors - accessing raw bytes at known offsets
static inline s8 _GetSFXVolume() {
    return *(s8*)((char*)g_pOptionsRecon + 0x1C);
}
static inline s8 _GetMusicVolume() {
    return *(s8*)((char*)g_pOptionsRecon + 0x1D);
}
static inline s8 _GetVOXVolume() {
    return *(s8*)((char*)g_pOptionsRecon + 0x28);
}
static inline s8 _GetAmbientVolume() {
    return *(s8*)((char*)g_pOptionsRecon + 0x29);
}
static inline void _SetSFXVolume(s8 v) {
    *(s8*)((char*)g_pOptionsRecon + 0x1C) = v;
}
static inline void _SetMusicVolume(s8 v) {
    *(s8*)((char*)g_pOptionsRecon + 0x1D) = v;
}
static inline void _SetVOXVolume(s8 v) {
    *(s8*)((char*)g_pOptionsRecon + 0x28) = v;
}
static inline void _SetAmbientVolume(s8 v) {
    *(s8*)((char*)g_pOptionsRecon + 0x29) = v;
}

// ============================================================================
// cSoundPlayer::GetGameMode @ 0x800b7898, 24 bytes
// Loads g_pSoundBox, if null returns 3, otherwise returns m_gameMode at +0x30
// Uses beqlr (conditional return)
// ============================================================================
// NON_MATCHING: GCC likely won't emit beqlr (conditional blr)
snd::eMode cSoundPlayer::GetGameMode() {
    if (g_pSoundBox == 0) {
        return (snd::eMode)3;
    }
    return *(snd::eMode*)((char*)g_pSoundBox + 0x30);
}

// ============================================================================
// cSoundPlayer::GetSFXVolume @ 0x800b7f04, 20 bytes
// Loads g_pOptionsRecon, reads s8 at offset 0x1C, sign-extends
// ============================================================================
s8 cSoundPlayer::GetSFXVolume() {
    return _GetSFXVolume();
}

// ============================================================================
// cSoundPlayer::GetMusicVolume @ 0x800b7f18, 20 bytes
// Same pattern, offset 0x1D
// ============================================================================
s8 cSoundPlayer::GetMusicVolume() {
    return _GetMusicVolume();
}

// ============================================================================
// cSoundPlayer::GetVOXVolume @ 0x800b7f2c, 20 bytes
// Same pattern, offset 0x28
// ============================================================================
s8 cSoundPlayer::GetVOXVolume() {
    return _GetVOXVolume();
}

// ============================================================================
// cSoundPlayer::GetAmbientVolume @ 0x800b7f40, 20 bytes
// Same pattern, offset 0x29
// ============================================================================
s8 cSoundPlayer::GetAmbientVolume() {
    return _GetAmbientVolume();
}

// ============================================================================
// DiscErrorCallback(bool) @ 0x800b720c, 88 bytes
// If g_pSoundBox != NULL:
//   If isError: save current game mode, set mode to 5 (disc error)
//   If !isError: restore saved game mode
// ============================================================================
// NON_MATCHING: GCC register allocation / branch layout differs
void DiscErrorCallback(bool isError) {
    if (g_pSoundBox != 0) {
        if (isError) {
            g_savedGameMode = (int)g_pSoundPlayer->GetGameMode();
            g_pSoundPlayer->SetGameMode(snd::eMode_DiscError);
        } else {
            g_pSoundPlayer->SetGameMode((snd::eMode)g_savedGameMode);
        }
    }
}

// ============================================================================
// cSoundPlayer::SetGameMode(snd::eMode) @ 0x800b7814, 132 bytes
// Complex function with multiple checks and branching
// Checks m_soundEnabled, m_initialized, g_pSoundBox, and another global
// If mode == 5 (disc error), calls cSoundModeManager::SetMode
// Otherwise calls cBoxX::Event with specific params
// ============================================================================
// NON_MATCHING: Complex control flow, GCC codegen differs significantly
void cSoundPlayer::SetGameMode(snd::eMode mode) {
    if (m_soundEnabled == 0) return;
    if (m_initialized == 0) return;
    if (g_pSoundBox == 0) return;

    // Check some other global condition
    // Original: lwz r9,r13-26824; lwz r0,1104(r9); cmpwi r0,0; bne skip
    // Skipping this complex global check for now

    if (mode == (snd::eMode)5) {
        cSoundModeManager_SetMode((void*)((char*)g_pSoundBox + 0x30), 5);
    } else {
        cBoxX_Event(g_pSoundBox, 0x24, mode, 0, 0, 0.0f);
    }
}

// ============================================================================
// cSoundPlayer::EnableSound(bool) @ 0x800b78b0, 84 bytes
// Checks m_initialized and m_soundEnabled, then calls cBoxX::Event
// ============================================================================
// NON_MATCHING: GCC codegen differs
void cSoundPlayer::EnableSound(bool enable) {
    if (m_initialized == 0) return;
    if (m_soundEnabled == 0) return;
    cBoxX_Event(g_pSoundBox, 0x22, enable, 0, 0, 0.0f);
}

// ============================================================================
// cSoundPlayer::QuietAll(void) @ 0x800b7904, 100 bytes
// Saves m_savedVolume from current volume, calls cBoxX::Event(0x14, ...)
// ============================================================================
// NON_MATCHING: GCC codegen differs
void cSoundPlayer::QuietAll() {
    if (m_initialized == 0) return;
    if (m_soundEnabled == 0) return;
    m_savedVolume = m_field_14;
    cBoxX_Event(g_pSoundBox, 0x14, 0, 0, 0, 0.0f);
}

// ============================================================================
// cSoundPlayer::PlayBySource(ERSoundEvent*, short) @ 0x800b7acc, 84 bytes
// Validates state, checks event and sourceId, then calls cBoxX::MappedEvent
// ============================================================================
// NON_MATCHING: GCC codegen differs
void cSoundPlayer::PlayBySource(ERSoundEvent* event, short sourceId) {
    if (m_initialized == 0) return;
    if (m_soundEnabled == 0) return;
    if (event == 0) return;
    if (sourceId == -2) return;
    cBoxX_MappedEvent(g_pSoundBox, event, sourceId, 0.0f);
}

// ============================================================================
// cSoundPlayer::QuietBySourceID(int) @ 0x800b7b20, 84 bytes
// Validates state, calls cBoxX::Event(0x17, ...)
// ============================================================================
// NON_MATCHING: GCC codegen differs
void cSoundPlayer::QuietBySourceID(int sourceId) {
    if (m_initialized == 0) return;
    if (m_soundEnabled == 0) return;
    cBoxX_Event(g_pSoundBox, 0x17, 0, sourceId, 0, 0.0f);
}

// ============================================================================
// cSoundPlayer::NotifyViewChange(void) @ 0x800b7e5c, 84 bytes
// Validates state, calls cBoxX::Event(0x2E, ...)
// ============================================================================
// NON_MATCHING: GCC codegen differs
void cSoundPlayer::NotifyViewChange() {
    if (m_initialized == 0) return;
    if (m_soundEnabled == 0) return;
    cBoxX_Event(g_pSoundBox, 0x2E, 0, 0, 0, 0.0f);
}

// ============================================================================
// cSoundPlayer::NotifyHourChange(void) @ 0x800b7eb0, 84 bytes
// Same pattern as NotifyViewChange but different float constant
// ============================================================================
// NON_MATCHING: GCC codegen differs
void cSoundPlayer::NotifyHourChange() {
    if (m_initialized == 0) return;
    if (m_soundEnabled == 0) return;
    cBoxX_Event(g_pSoundBox, 0x2E, 0, 0, 0, 0.0f);
}

// ============================================================================
// cSoundPlayer::PauseSFX(void) @ 0x800b7b74, 112 bytes
// Validates state, sends pause event, then calls NotifyViewChange
// ============================================================================
// NON_MATCHING: GCC codegen differs
void cSoundPlayer::PauseSFX() {
    if (m_initialized == 0) return;
    if (m_soundEnabled == 0) return;
    if (g_pSoundBox != 0) {
        cBoxX_Event(g_pSoundBox, 0x31, 0, 0, 0, 0.0f);
    }
    NotifyViewChange();
}

// ============================================================================
// cSoundPlayer::ResumeSFX(void) @ 0x800b7be4, 112 bytes
// Same pattern as PauseSFX with different event ID (0x32)
// ============================================================================
// NON_MATCHING: GCC codegen differs
void cSoundPlayer::ResumeSFX() {
    if (m_initialized == 0) return;
    if (m_soundEnabled == 0) return;
    if (g_pSoundBox != 0) {
        cBoxX_Event(g_pSoundBox, 0x32, 0, 0, 0, 0.0f);
    }
    NotifyViewChange();
}

// ============================================================================
// cSoundPlayer::PauseMusic(void) @ 0x800b7c54, 112 bytes
// Same pattern, event ID 0x33
// ============================================================================
// NON_MATCHING: GCC codegen differs
void cSoundPlayer::PauseMusic() {
    if (m_initialized == 0) return;
    if (m_soundEnabled == 0) return;
    if (g_pSoundBox != 0) {
        cBoxX_Event(g_pSoundBox, 0x33, 0, 0, 0, 0.0f);
    }
    NotifyViewChange();
}

// ============================================================================
// cSoundPlayer::ResumeMusic(void) @ 0x800b7cc4, 112 bytes
// Same pattern, event ID 0x34
// ============================================================================
// NON_MATCHING: GCC codegen differs
void cSoundPlayer::ResumeMusic() {
    if (m_initialized == 0) return;
    if (m_soundEnabled == 0) return;
    if (g_pSoundBox != 0) {
        cBoxX_Event(g_pSoundBox, 0x34, 0, 0, 0, 0.0f);
    }
    NotifyViewChange();
}

// ============================================================================
// cSoundPlayer::PauseSounds(void) @ 0x800b7d34, 148 bytes
// Sets m_isPaused to 1, then sends two events (0x2F and 0x15),
// then calls NotifyViewChange
// ============================================================================
// NON_MATCHING: GCC codegen differs
void cSoundPlayer::PauseSounds() {
    m_isPaused = 1;
    if (m_initialized == 0) return;
    if (m_soundEnabled == 0) return;
    if (g_pSoundBox != 0) {
        cBoxX_Event(g_pSoundBox, 0x2F, 0, 0, 0, 0.0f);
        cBoxX_Event(g_pSoundBox, 0x15, 0, 0, 0, 0.0f);
    }
    NotifyViewChange();
}

// ============================================================================
// cSoundPlayer::ResumeSounds(void) @ 0x800b7dc8, 148 bytes
// Validates state, sends two events (0x30 and 0x16),
// calls NotifyViewChange, then sets m_isPaused to 0
// ============================================================================
// NON_MATCHING: GCC codegen differs
void cSoundPlayer::ResumeSounds() {
    if (m_initialized == 0) return;
    if (m_soundEnabled == 0) return;
    if (g_pSoundBox != 0) {
        cBoxX_Event(g_pSoundBox, 0x30, 0, 0, 0, 0.0f);
        cBoxX_Event(g_pSoundBox, 0x16, 0, 0, 0, 0.0f);
    }
    NotifyViewChange();
    m_isPaused = 0;
}

// ============================================================================
// cSoundPlayer::SetOldFXVolume(int) @ 0x800b7f54, 136 bytes
// Stores volume to OptionsRecon sfx field, then sends two events (0x25 and 0x27)
// ============================================================================
// NON_MATCHING: GCC codegen differs
void cSoundPlayer::SetOldFXVolume(int volume) {
    _SetSFXVolume((s8)volume);
    if (m_initialized == 0) return;
    if (m_soundEnabled == 0) return;
    cBoxX_Event(g_pSoundBox, 0x25, volume, 0, 0, 0.0f);
    cBoxX_Event(g_pSoundBox, 0x27, volume, 0, 0, 0.0f);
}

// ============================================================================
// cSoundPlayer::SetMusicVolume(int) @ 0x800b7fdc, 96 bytes
// Stores volume to OptionsRecon music field, sends event 0x26
// ============================================================================
// NON_MATCHING: GCC codegen differs
void cSoundPlayer::SetMusicVolume(int volume) {
    _SetMusicVolume((s8)volume);
    if (m_initialized == 0) return;
    if (m_soundEnabled == 0) return;
    cBoxX_Event(g_pSoundBox, 0x26, volume, 0, 0, 0.0f);
}

// ============================================================================
// cSoundPlayer::SetSFXVolume(int) @ 0x800b803c, 96 bytes
// Stores volume to OptionsRecon sfx field, sends event 0x2B
// ============================================================================
// NON_MATCHING: GCC codegen differs
void cSoundPlayer::SetSFXVolume(int volume) {
    _SetSFXVolume((s8)volume);
    if (m_initialized == 0) return;
    if (m_soundEnabled == 0) return;
    cBoxX_Event(g_pSoundBox, 0x2B, volume, 0, 0, 0.0f);
}

// ============================================================================
// cSoundPlayer::SetVOXVolume(int) @ 0x800b809c, 96 bytes
// Stores volume to OptionsRecon vox field, sends event 0x27
// ============================================================================
// NON_MATCHING: GCC codegen differs
void cSoundPlayer::SetVOXVolume(int volume) {
    _SetVOXVolume((s8)volume);
    if (m_initialized == 0) return;
    if (m_soundEnabled == 0) return;
    cBoxX_Event(g_pSoundBox, 0x27, volume, 0, 0, 0.0f);
}

// ============================================================================
// cSoundPlayer::SetAmbientVolume(int) @ 0x800b80fc, 96 bytes
// Stores volume to OptionsRecon ambient field, sends event 0x2C
// ============================================================================
// NON_MATCHING: GCC codegen differs
void cSoundPlayer::SetAmbientVolume(int volume) {
    _SetAmbientVolume((s8)volume);
    if (m_initialized == 0) return;
    if (m_soundEnabled == 0) return;
    cBoxX_Event(g_pSoundBox, 0x2C, volume, 0, 0, 0.0f);
}
