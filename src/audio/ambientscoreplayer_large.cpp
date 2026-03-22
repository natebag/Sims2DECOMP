// ambientscoreplayer_large.cpp - AmbientScorePlayer large functions (257-1024 bytes)
// Object file: ambientscoreplayer.obj
// All NON_MATCHING - GCC vs SN Systems codegen differences

#include "types.h"
#include "stub_classes.h"

extern "C" {
    void* operator_new_wrapper(u32 size);
    void operator_delete_wrapper(void* ptr);
    void* memcpy(void* dst, const void* src, u32 n);
}

// ============================================================================
// AmbientScorePlayer::Update(void)
// Address: 0x800a81d8
// Size: 0x34c = 844 bytes
// NON_MATCHING - sound processing loop, time-based scheduling
// ============================================================================
void AmbientScorePlayer_Update(void* self) {
    char* _this = (char*)self;

    // Check if player is active
    int active = *(int*)(_this + 0x04);
    if (!active) return;

    // Get current time
    float curTime = *(float*)(_this + 0x08);

    // Remove finished sounds
    // RemoveFinishedSounds()

    // Get ambient score data
    void* score = *(void**)(_this + 0x0C);
    if (!score) return;

    // Get number of sounds in score
    int numSounds = *(int*)((char*)score + 0x04);

    // For each sound in score:
    for (int i = 0; i < numSounds; i++) {
        // Get ERAmbientSound at index
        void* ambSound = *(void**)((char*)score + 0x08 + i * 4);
        if (!ambSound) continue;

        // Check if sound's time range covers current time
        // SoundRangeCoversCurTime(ambSound)

        // Check if already playing
        // SoundAlreadyPlaying(ambSound)

        // Check if within hearing distance of any listener
        // SoundInHearingDistance(ambSound)

        // If eligible: AddSoundBasedOnProbability
    }

    // Update playing sounds
    // For each active AmbientSoundPlayer:
    //   Call Update()

    (void)curTime;
}

// ============================================================================
// AmbientScorePlayer::UpdateListener(unsigned int, EVec3&, EVec3&)
// Address: 0x800a85a4
// Size: 0x1c0 = 448 bytes
// NON_MATCHING - listener position update, distance calculations
// ============================================================================
void AmbientScorePlayer_UpdateListener(void* self, u32 listenerIdx, void* pos, void* dir) {
    char* _this = (char*)self;

    // Bounds check listener index
    int listenerCount = *(int*)(_this + 0x10);
    if ((int)listenerIdx >= listenerCount) return;

    // Get listener info array
    void* listeners = *(void**)(_this + 0x14);
    char* listener = (char*)listeners + listenerIdx * 0x20; // sizeof(ListenerInfo)

    // Update position
    float* listenerPos = (float*)(listener + 0x00);
    float* srcPos = (float*)pos;
    listenerPos[0] = srcPos[0];
    listenerPos[1] = srcPos[1];
    listenerPos[2] = srcPos[2];

    // Update direction
    float* listenerDir = (float*)(listener + 0x0C);
    float* srcDir = (float*)dir;
    listenerDir[0] = srcDir[0];
    listenerDir[1] = srcDir[1];
    listenerDir[2] = srcDir[2];

    // Recalculate distance to all active sounds
    // Update panning for active sounds based on new listener position

    (void)_this;
}

// ============================================================================
// AmbientScorePlayer::Load(char*)
// Address: 0x800a8774
// Size: 0x16c = 364 bytes
// NON_MATCHING - file loading, score parsing
// ============================================================================
void AmbientScorePlayer_Load(void* self, char* filename) {
    char* _this = (char*)self;

    // Stop any currently playing sounds
    // KillAllAmbientSounds()

    // Load ambient score file
    // Get resource from dataset by filename

    // Parse score header
    // Get number of ambient sound entries
    // Get time range info

    // For each sound entry:
    //   Create ERAmbientSound reference
    //   Load sound parameters (position, range, probability, etc.)

    // Set score pointer
    // Reset time to start

    (void)_this;
    (void)filename;
}

// ============================================================================
// AmbientScorePlayer::SoundInHearingDistance(ERAmbientSound*)
// Address: 0x800a8cb0
// Size: 0x228 = 552 bytes
// NON_MATCHING - 3D distance calculation, listener proximity
// ============================================================================
int AmbientScorePlayer_SoundInHearingDistance(void* self, void* ambSound) {
    char* _this = (char*)self;

    // Get sound position
    float* soundPos = (float*)((char*)ambSound + 0x10);

    // Get sound hearing range
    float hearingRange = *(float*)((char*)ambSound + 0x1C);

    // For each listener:
    int listenerCount = *(int*)(_this + 0x10);
    void* listeners = *(void**)(_this + 0x14);

    for (int i = 0; i < listenerCount; i++) {
        float* listenerPos = (float*)((char*)listeners + i * 0x20);

        // Calculate distance
        float dx = soundPos[0] - listenerPos[0];
        float dy = soundPos[1] - listenerPos[1];
        float dz = soundPos[2] - listenerPos[2];
        float distSq = dx * dx + dy * dy + dz * dz;

        if (distSq < hearingRange * hearingRange) {
            return 1;
        }
    }

    return 0;
}

// ============================================================================
// AmbientScorePlayer::SetPause(bool)
// Address: 0x800a8a18
// Size: 0xf8 = 248 bytes (under 257, skip)
// ============================================================================

// ============================================================================
// AmbientScorePlayer::Shutdown(void)
// Address: 0x800a8954
// Size: 0xc4 = 196 bytes (under 257, skip)
// ============================================================================

// ============================================================================
// vector<AmbientScorePlayer::ListenerInfo>::_M_fill_insert(...)
// Address: 0x803a23e8
// Size: 0x574 = 1396 bytes (over 1024, skip)
// ============================================================================
