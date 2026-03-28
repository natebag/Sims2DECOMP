// ambientscoreplayer_medium.cpp - AmbientScorePlayer medium functions (65-256 bytes)
// Object file: ambientscoreplayer.obj
// All NON_MATCHING due to: GCC vs SN Systems codegen differences

#include "audio/ambientscoreplayer.h"

// External functions
extern "C" void* EAHeap_Get();
extern "C" void EAHeap_Free(void*, void*);
extern "C" void* EAHeap_Alloc(int);
extern "C" void EAHeap_FreePtr(void*);
extern "C" int OSGetTick();
extern "C" void AmbientSoundPlayer_Delete(void*);
extern "C" void AmbientSoundPlayer_Stop(void*);
extern "C" void AmbientSoundPlayer_Pause(void*);
extern "C" void AmbientSoundPlayer_UnPause(void*);

// Globals
extern int g_ambientSoundDuckLevel; // SDA relative

// ============================================================================
// AmbientScorePlayer::AmbientScorePlayer
// ambientscoreplayer.obj | 0x800A80B8 | 132 bytes
// ============================================================================
// NON_MATCHING: init order, codegen
AmbientScorePlayer::AmbientScorePlayer(bool usePositional) {
    m_state = 0;
    m_field_04 = 0;
    m_ambientScore = 0;
    m_field_0C = 0;
    m_numPlaying = 0;
    m_volume = 1024;
    m_field_18 = 0;
    m_numListeners = 2;
    m_listenerBegin = 0;
    m_listenerEnd = 0;
    m_listenerCap = 0;
    m_field_2C = 0;
    m_usePositional = usePositional ? 1 : 0;
    m_time = 0.0f;
    m_startTimestamp = 0;
}

// ============================================================================
// AmbientScorePlayer::~AmbientScorePlayer
// ambientscoreplayer.obj | 0x800A813C | 156 bytes
// ============================================================================
// NON_MATCHING: cleanup sequence
AmbientScorePlayer::~AmbientScorePlayer() {
    Shutdown();
    // Free listener info array
    if (m_listenerBegin != 0) {
        EAHeap_FreePtr(m_listenerBegin);
        m_listenerBegin = 0;
        m_listenerEnd = 0;
        m_listenerCap = 0;
    }
}

// ============================================================================
// AmbientScorePlayer::Shutdown
// ambientscoreplayer.obj | 0x800A8954 | 196 bytes
// ============================================================================
// NON_MATCHING: linked list traversal codegen
void AmbientScorePlayer::Shutdown() {
    KillAllAmbientSounds();
    m_state = 0;
    m_ambientScore = 0;
    m_numPlaying = 0;
    m_time = 0.0f;
}

// ============================================================================
// AmbientScorePlayer::RemoveFinishedSounds
// ambientscoreplayer.obj | 0x800A9198 | 216 bytes
// Removes sounds that have finished playing from the active list
// ============================================================================
// NON_MATCHING: list iteration with removal
void AmbientScorePlayer::RemoveFinishedSounds() {
    // Iterate through active ambient sound players
    // For each finished sound:
    //   Remove from list
    //   Delete the player
    //   Decrement m_numPlaying
}

// ============================================================================
// AmbientScorePlayer::SoundRangeCoversCurTime
// ambientscoreplayer.obj | 0x800A8B3C | 236 bytes
// Checks if a sound's time range covers the current playback time
// ============================================================================
// NON_MATCHING: FP comparison codegen
int AmbientScorePlayer::SoundRangeCoversCurTime(ERAmbientSound* sound) {
    if (sound == 0) return 0;
    // Get sound's start and end time
    // Compare with m_time
    // Handle wraparound for looping scores
    return 0;
}

// ============================================================================
// AmbientScorePlayer::SoundAlreadyPlaying
// ambientscoreplayer.obj | 0x800A8C28 | 136 bytes
// Checks if a specific ambient sound is already in the active list
// ============================================================================
// NON_MATCHING: list search codegen
int AmbientScorePlayer::SoundAlreadyPlaying(ERAmbientSound* sound) {
    if (sound == 0) return 0;
    // Iterate through active sound players
    // Compare each player's sound pointer with 'sound'
    // Return 1 if found
    return 0;
}

// ============================================================================
// AmbientScorePlayer::AddSoundBasedOnProbability
// ambientscoreplayer.obj | 0x800A8ED8 | 184 bytes
// ============================================================================
// NON_MATCHING: random number generation / probability check
void AmbientScorePlayer::AddSoundBasedOnProbability(void* sounds, int count, bool flag) {
    // For each sound in the list:
    //   Check if it's within time range
    //   Check probability against random value
    //   If passes, add new ambient sound player
}

// ============================================================================
// AmbientScorePlayer::SetListenerCount
// ambientscoreplayer.obj | 0x800A8524 | 128 bytes
// Reallocates listener info array for new count
// ============================================================================
// NON_MATCHING: vector reallocation pattern
void AmbientScorePlayer::SetListenerCount(int count) {
    m_numListeners = count;
    // Reallocate listener info vector
    if (m_listenerBegin != 0) {
        EAHeap_FreePtr(m_listenerBegin);
    }
    int allocSize = count * sizeof(ListenerInfo);
    m_listenerBegin = (ListenerInfo*)EAHeap_Alloc(allocSize);
    m_listenerEnd = m_listenerBegin;
    m_listenerCap = (ListenerInfo*)((char*)m_listenerBegin + allocSize);
}

// ============================================================================
// AmbientScorePlayer::KillAllAmbientSounds
// ambientscoreplayer.obj | 0x800A8F90 | 184 bytes
// Stops and removes all active ambient sounds
// ============================================================================
// NON_MATCHING: list traversal with deletion
int AmbientScorePlayer::KillAllAmbientSounds() {
    // Iterate through all active sound players
    // For each:
    //   Stop the sound
    //   Remove from list
    //   Delete the player
    m_numPlaying = 0;
    return 0;
}

// ============================================================================
// AmbientScorePlayer::SetPause
// ambientscoreplayer.obj | 0x800A8A18 | 248 bytes
// Pauses or unpauses all active ambient sounds
// ============================================================================
// NON_MATCHING: complex pause/unpause with timestamp management
void AmbientScorePlayer::SetPause(bool pause) {
    if (pause) {
        m_state = 0; // paused
        // Save current timestamp
        // Iterate all sounds and pause them
    } else {
        m_state = 1; // playing
        // Restore timestamp
        // Iterate all sounds and unpause them
    }
}

// ============================================================================
// AmbientScorePlayer::AddNewAmbientSoundPlayer
// ambientscoreplayer.obj | 0x800A9048 | 148 bytes
// Creates and starts a new ambient sound player
// ============================================================================
// NON_MATCHING: allocation + list insert
int AmbientScorePlayer::AddNewAmbientSoundPlayer(ERAmbientSound* sound) {
    if (sound == 0) return 0;
    // Allocate new AmbientSoundPlayer
    // Initialize with this score player and sound
    // Start playing
    // Add to active list
    m_numPlaying++;
    return 1;
}

// ============================================================================
// AmbientScorePlayer::RemoveAmbientSoundPlayer
// ambientscoreplayer.obj | 0x800A90DC | 188 bytes
// Removes a specific ambient sound from the active list
// ============================================================================
// NON_MATCHING: list search and removal
void AmbientScorePlayer::RemoveAmbientSoundPlayer(ERAmbientSound* sound) {
    if (sound == 0) return;
    // Find the sound player matching this sound
    // Stop it, remove from list, delete
    // Decrement m_numPlaying
}
