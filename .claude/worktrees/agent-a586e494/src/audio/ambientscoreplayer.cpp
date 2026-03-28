// ambientscoreplayer.cpp - Ambient score/music player
// Object file: ambientscoreplayer.obj
// 9 small functions (<=64 bytes) decompiled from Sims 2 GC
// 7 MATCHING, 2 NON_MATCHING
//
// AmbientScorePlayer layout (60 bytes, 0x3C):
//   +0x00: int m_state             (0 = stopped, 1 = playing)
//   +0x04: int m_field_04
//   +0x08: ERAmbientScore* m_ambientScore
//   +0x0C: int m_field_0C
//   +0x10: int m_numPlaying
//   +0x14: int m_volume            (default 1024)
//   +0x18: int m_field_18
//   +0x1C: int m_numListeners      (default 2)
//   +0x20: vector<ListenerInfo> m_listenerInfos
//   +0x30: int m_usePositional
//   +0x34: float m_time
//   +0x38: u32 m_startTimestamp

#include "audio/ambientscoreplayer.h"

// External functions
extern "C" u32 timeGetTime();

// MATCHING
// AmbientScorePlayer::SetTime(float) @ 0x800a8764, 8 bytes
void AmbientScorePlayer::SetTime(float time) {
    m_time = time;
}

// MATCHING
// AmbientScorePlayer::GetTime(void) @ 0x800a876c, 8 bytes
float AmbientScorePlayer::GetTime() {
    return m_time;
}

// NON_MATCHING: GCC uses stw r31 instead of stmw r30; different register (r31 vs r30);
// GCC interleaves li r9,1/stw differently from original's li r0,1/stw
// AmbientScorePlayer::Start(void) @ 0x800a88e0, 60 bytes
int AmbientScorePlayer::Start() {
    m_startTimestamp = timeGetTime();
    m_state = 1;
    return 1;
}

// NON_MATCHING: GCC uses addic/subfe for bool conversion;
// original uses cmpwi/beq/li pattern
// AmbientScorePlayer::Stop(void) @ 0x800a891c, 56 bytes
int AmbientScorePlayer::Stop() {
    m_state = 0;
    int result = KillAllAmbientSounds();
    if (result != 0) {
        return 1;
    }
    return 0;
}

// MATCHING
// AmbientScorePlayer::SetVolume(int) @ 0x800a8b10, 12 bytes
int AmbientScorePlayer::SetVolume(int volume) {
    m_volume = volume;
    return 1;
}

// MATCHING
// AmbientScorePlayer::GetVolume(void) @ 0x800a8b1c, 8 bytes
int AmbientScorePlayer::GetVolume() {
    return m_volume;
}

// MATCHING
// AmbientScorePlayer::GetAmbientScore(void) @ 0x800a8b24, 8 bytes
ERAmbientScore* AmbientScorePlayer::GetAmbientScore() {
    return m_ambientScore;
}

// MATCHING
// AmbientScorePlayer::GetNumPlaying(void) @ 0x800a8b2c, 8 bytes
int AmbientScorePlayer::GetNumPlaying() {
    return m_numPlaying;
}

// MATCHING
// AmbientScorePlayer::GetListenerInfos(void) @ 0x800a8b34, 8 bytes
// Returns pointer to the vector struct itself (this + 0x20)
void* AmbientScorePlayer::GetListenerInfos() {
    return &m_listenerBegin;
}
