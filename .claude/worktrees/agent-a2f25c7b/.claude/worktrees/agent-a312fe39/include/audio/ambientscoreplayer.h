#ifndef AMBIENTSCOREPLAYER_H
#define AMBIENTSCOREPLAYER_H

#include "types.h"

// Forward declarations
class ERAmbientSound;
class ERAmbientScore;
struct EVec3;

template <class T, class Alloc> class vector;
template <class T> class allocator;

// AmbientScorePlayer class
// Object file: ambientscoreplayer.obj
//
// Memory layout (from disassembly):
//   +0x00: int m_state             (0 = stopped, 1 = playing)
//   +0x04: int m_field_04          (unknown)
//   +0x08: ERAmbientScore* m_ambientScore
//   +0x0C: int m_field_0C
//   +0x10: int m_numPlaying
//   +0x14: int m_volume            (default 1024)
//   +0x18: int m_field_18
//   +0x1C: int m_numListeners      (default 2)
//   +0x20: vector<ListenerInfo> m_listenerInfos  (12 bytes: begin, end, capacity)
//   +0x2C: int m_field_2C
//   +0x30: int m_usePositional     (from constructor arg)
//   +0x34: float m_time
//   +0x38: u32 m_startTimestamp
class AmbientScorePlayer {
public:
    struct ListenerInfo {
        // 28 bytes (0x1C) per entry - inferred from vector operations
        char data[28];
    };

    int m_state;              // +0x00
    int m_field_04;           // +0x04
    ERAmbientScore* m_ambientScore; // +0x08
    int m_field_0C;           // +0x0C
    int m_numPlaying;         // +0x10
    int m_volume;             // +0x14
    int m_field_18;           // +0x18
    int m_numListeners;       // +0x1C
    // vector<ListenerInfo> at +0x20 (3 pointers: begin, end, end_of_storage)
    ListenerInfo* m_listenerBegin;  // +0x20
    ListenerInfo* m_listenerEnd;    // +0x24
    ListenerInfo* m_listenerCap;    // +0x28
    int m_field_2C;           // +0x2C
    int m_usePositional;      // +0x30
    float m_time;             // +0x34
    u32 m_startTimestamp;     // +0x38

    static int s_duckAmbient; // @ sdata

    AmbientScorePlayer(bool usePositional);
    ~AmbientScorePlayer();

    void SetTime(float time);
    float GetTime();
    int Start();
    int Stop();
    int SetVolume(int volume);
    int GetVolume();
    ERAmbientScore* GetAmbientScore();
    int GetNumPlaying();
    void* GetListenerInfos();

    void Shutdown();
    void Update();
    void RemoveFinishedSounds();
    int SoundRangeCoversCurTime(ERAmbientSound* sound);
    int SoundAlreadyPlaying(ERAmbientSound* sound);
    int SoundInHearingDistance(ERAmbientSound* sound);
    void AddSoundBasedOnProbability(void* sounds, int count, bool flag);
    void SetListenerCount(int count);
    void UpdateListener(unsigned int index, EVec3& pos, EVec3& dir);
    void Load(char* filename);
    int KillAllAmbientSounds();
    void SetPause(bool pause);
    int AddNewAmbientSoundPlayer(ERAmbientSound* sound);
    void RemoveAmbientSoundPlayer(ERAmbientSound* sound);
};

#endif // AMBIENTSCOREPLAYER_H
