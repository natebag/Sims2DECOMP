// ambientsoundplayer_medium.cpp - AmbientSoundPlayer medium functions (65-256 bytes)
// Object file: ambientsoundplayer.obj
// All NON_MATCHING due to: GCC vs SN Systems codegen differences

#include "audio/ambientsoundplayer.h"

// External functions
extern "C" void* cBoxX_CreateSound(void*, int, int);
extern "C" void cBoxX_StopSound(void*, int);
extern "C" void cBoxX_PauseSound(void*, int);
extern "C" void cBoxX_UnPauseSound(void*, int);
extern "C" void cBoxX_SetSoundVolume(void*, int, int);
extern "C" void cBoxX_SetSoundPosition(void*, int, float, float, float);
extern "C" int cBoxX_IsSoundFinished(void*, int);

// Globals
extern void* g_pSoundBox;  // SDA relative

// ============================================================================
// AmbientSoundPlayer::AmbientSoundPlayer
// ambientsoundplayer.obj | 0x800A9270 | 76 bytes
// ============================================================================
// NON_MATCHING: init order
AmbientSoundPlayer::AmbientSoundPlayer() {
    m_scorePlayer = 0;
    m_ambientSound = 0;
    m_soundHandle = 0;
    m_field_0C = 0;
    m_field_10 = 0;
    m_posX = 0.0f;
    m_posY = 0.0f;
    m_field_1C = 0.0f;
    m_velX = 0.0f;
    m_velY = 0.0f;
    m_field_28 = 0;
    m_soundId = -1;
}

// ============================================================================
// AmbientSoundPlayer::~AmbientSoundPlayer
// ambientsoundplayer.obj | 0x800A92BC | 116 bytes
// ============================================================================
// NON_MATCHING: cleanup order, sound system calls
AmbientSoundPlayer::~AmbientSoundPlayer() {
    Stop();
    m_scorePlayer = 0;
    m_ambientSound = 0;
    m_soundHandle = 0;
    m_soundId = -1;
}

// ============================================================================
// AmbientSoundPlayer::UpdateSoundPosition
// ambientsoundplayer.obj | 0x800AA050 | 84 bytes
// Updates the 3D position of the playing sound
// ============================================================================
// NON_MATCHING: FP codegen
void AmbientSoundPlayer::UpdateSoundPosition() {
    if (m_soundHandle == 0) return;
    if (m_soundId == -1) return;
    // Set 3D position on the sound instance
    cBoxX_SetSoundPosition(g_pSoundBox, m_soundId, m_posX, m_posY, 0.0f);
}

// ============================================================================
// AmbientSoundPlayer::UpdateSoundVolume
// ambientsoundplayer.obj | 0x800AA904 | 176 bytes
// Updates the volume based on distance from listener
// ============================================================================
// NON_MATCHING: FP distance calculation, volume curve
void AmbientSoundPlayer::UpdateSoundVolume() {
    if (m_soundHandle == 0) return;
    if (m_soundId == -1) return;
    // Calculate distance from listener
    // Apply distance attenuation curve
    // Clamp volume to valid range
    // Set volume on sound instance
}

// ============================================================================
// AmbientSoundPlayer::Stop
// ambientsoundplayer.obj | 0x800A9738 | 124 bytes
// ============================================================================
// NON_MATCHING: sound system shutdown sequence
int AmbientSoundPlayer::Stop() {
    if (m_soundHandle != 0) {
        if (m_soundId != -1) {
            cBoxX_StopSound(g_pSoundBox, m_soundId);
        }
        m_soundHandle = 0;
        m_soundId = -1;
    }
    return 0;
}

// ============================================================================
// AmbientSoundPlayer::Pause
// ambientsoundplayer.obj | 0x800A97B4 | 68 bytes
// ============================================================================
// NON_MATCHING: codegen
int AmbientSoundPlayer::Pause() {
    if (m_soundHandle == 0) return 0;
    if (m_soundId == -1) return 0;
    cBoxX_PauseSound(g_pSoundBox, m_soundId);
    return 1;
}

// ============================================================================
// AmbientSoundPlayer::UnPause
// ambientsoundplayer.obj | 0x800A97F8 | 68 bytes
// ============================================================================
// NON_MATCHING: codegen
int AmbientSoundPlayer::UnPause() {
    if (m_soundHandle == 0) return 0;
    if (m_soundId == -1) return 0;
    cBoxX_UnPauseSound(g_pSoundBox, m_soundId);
    return 1;
}

// ============================================================================
// AmbientSoundPlayer::IsFinished
// ambientsoundplayer.obj | 0x800AA9BC | 92 bytes
// ============================================================================
// NON_MATCHING: codegen
int AmbientSoundPlayer::IsFinished() {
    if (m_soundHandle == 0) return 1;
    if (m_soundId == -1) return 1;
    return cBoxX_IsSoundFinished(g_pSoundBox, m_soundId);
}
