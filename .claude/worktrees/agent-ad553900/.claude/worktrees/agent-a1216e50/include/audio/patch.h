#ifndef PATCH_H
#define PATCH_H

#include "types.h"

// Forward declarations
class ERSoundEvent;
struct ERSoundTrackData;
struct SndEvtHitPatch;

// ============================================================================
// TrackDataReader - Reader for sound track data commands
// Object file: patch.obj
//
// Layout:
//   +0x00: ERSoundTrackData* m_data
//   +0x04: int m_pos (current position index)
// Size: 8 bytes
// ============================================================================
class TrackDataReader {
public:
    ERSoundTrackData* m_data;   // +0x00
    int m_pos;                  // +0x04

    TrackDataReader();
    ~TrackDataReader();
    TrackDataReader& operator=(TrackDataReader& other);
    TrackDataReader& operator=(ERSoundTrackData* data);
    TrackDataReader& operator--();
    TrackDataReader& operator+=(int offset);
    void ReadCommand();
    void Trace() const;
    bool IsValid() const;
    void JumpToEnd();
};

// ============================================================================
// ERSoundTrackData - Sound track data container
// Layout (partial, from TrackDataReader::JumpToEnd):
//   +0x14: void* m_commands (start of command array)
//   +0x18: void* m_commandsEnd (end of command array)
//   +0x24: void* m_vHitList
//   +0x28: int   m_numVHitLists
//   +0x30: int   m_startPos
// ============================================================================
struct ERSoundTrackData {
    u8   m_pad00[0x14];
    void* m_commands;      // +0x14 (int* array)
    void* m_commandsEnd;   // +0x18 (int* end)
    u8   m_pad1C[0x04];
    int  m_minRange;       // +0x1F (byte at +0x1F)
    int  m_maxRange;       // +0x20 (byte at +0x20)
    u8   m_pad21[0x03];
    void* m_vHitList;      // +0x24
    int   m_numVHitLists;  // +0x28
    u8   m_pad2C[0x04];
    int   m_startPos;      // +0x30
};

// ============================================================================
// cHitControlGroup - Sound control group
// Object file: patch.obj
//
// Layout:
//   +0x00: int m_id
//   +0x04: int m_volume (default 1024)
// ============================================================================
class cHitControlGroup {
public:
    int m_id;       // +0x00
    int m_volume;   // +0x04

    cHitControlGroup(int id);
    void SetVolume(int volume);
};

// ============================================================================
// cSamplePatch - Sample-based sound patch
// Object file: patch.obj
//
// Layout:
//   +0x00: (base)
//   +0x04: void* m_channel
//   +0x08: int   m_sndId
//   +0x0C: int   m_sndBank
//   +0x10: int   m_looped
//   +0x14: float m_volume
//   +0x18: void* m_snd
// Size: 0x1C
// ============================================================================
class cSamplePatch {
public:
    u8    m_pad00[0x04];    // +0x00
    void* m_channel;        // +0x04
    int   m_sndId;          // +0x08
    int   m_sndBank;        // +0x0C
    int   m_looped;         // +0x10
    float m_volumeScale;    // +0x14
    void* m_snd;            // +0x18

    cSamplePatch(SndEvtHitPatch* patch, float volume);
    ~cSamplePatch();
    void SetLooped(int looped);
    bool IsPlaying();
    void CreateSnd();
    void FreeSnd();
    void SetVolume(int volume);
    void SetPan(int pan);
    void* CreateChannel();
};

// ============================================================================
// cSampleChannel - Audio channel for sample playback
// Object file: patch.obj
//
// Layout:
//   +0x00: cSamplePatch* m_patch
//   +0x04: int m_state  (0 = inactive)
// Size: 8 bytes
// ============================================================================
class cSampleChannel {
public:
    cSamplePatch* m_patch;   // +0x00
    int m_state;             // +0x04

    cSampleChannel(cSamplePatch* patch);
    ~cSampleChannel();
    void Shutdown();
    void NoteOn();
    void NoteOff();
    bool IsPlaying();
    void Pause();
    void Unpause();
    void SetVolume(int volume);
    void SetPan(int pan);
    void SetPatch(cSamplePatch* patch);
    void* Snd(int index);
};

// ============================================================================
// cTrack - Sound track object
// Object file: patch.obj
//
// Layout (from disassembly):
//   +0x00: ERSoundEvent* m_event
//   +0x04: int m_instanceId
//   +0x34: int m_isPlaying
//   +0x38: int m_pauseCount
//   +0x3C: int m_isEqual
//   +0x40: int m_isGreater
//   +0x44: int m_isLess
//   +0x50: cSampleChannel* m_channel
// ============================================================================
class cTrack {
public:
    ERSoundEvent* m_event;          // +0x00
    int m_instanceId;               // +0x04
    u8  m_pad08[0x2C];              // +0x08
    int m_isPlaying;                // +0x34
    int m_pauseCount;               // +0x38
    int m_isEqual;                  // +0x3C
    int m_isGreater;                // +0x40
    int m_isLess;                   // +0x44
    u8  m_pad48[0x08];              // +0x48
    cSampleChannel* m_channel;      // +0x50

    static int s_superDuckEnabled;     // 0x804FDD04
    static u8  s_maxSfxDuckPri;        // 0x804FDD08
    static u8  s_maxVoxDuckPri;        // 0x804FDD09
    static u8  s_maxMusicDuckPri;      // 0x804FDD0A

    cTrack(ERSoundEvent* event);
    ~cTrack();
    void Kill();
    void OnStartPlaying();
    void OnEndPlaying();
    void HandleTimerCallback();
    void PlayPause(int volume, int pan, int type, float speed);
    void Pause();
    void Unpause();
    void Stop();
    void DoCommand();
    void SetRegister(int reg, int value);
    int RegisterVal(int reg);
    int StartPos();
    void UpdateVolPan();
    void NoteOn();
    void NoteOff();
    void SetPatch(SndEvtHitPatch* patch, float speed);
    void SetCompareFlags(int a, int b);
    void* GetVHitList(int index);
    void SetVolume(int volume);
    void SetPan(int pan);
    void CalculateCurrentVolume();
    int GetControlGroup();
    int GetMinRange();
    int GetMaxRange();
    int GetArgsType();
    void SetInstanceId(int id);
    int InstanceId();
    bool IsPlaying();
    bool IsPaused();
    int CheckedRegId(int id);

    void HandleTrackFlowError(char* msg);
};

// ============================================================================
// cTrackCacheHandle - Handle for cached track lookup
// Object file: patch.obj
//
// Layout:
//   +0x00: ERSoundEvent* m_event
// Size: 4 bytes
// ============================================================================
class cTrackCacheHandle {
public:
    ERSoundEvent* m_event;   // +0x00

    cTrackCacheHandle(ERSoundEvent* event);
    cTrack* GetTrackObject();
};

// ============================================================================
// cSoundCache - Cache of sound tracks
// Object file: patch.obj
//
// Layout:
//   +0x00: cTrack* m_tracks[64] (array of 64 track pointers)
//   +0x100: int m_field_100
// Size: >= 0x104
// ============================================================================
class cSoundCache {
public:
    cTrack* m_tracks[64];    // +0x00
    int m_field_100;         // +0x100

    cSoundCache();
    ~cSoundCache();
    void Shutdown();
    void KillAll();
    void CleanupIdleTracks();
    void UpdateDuckingPriorities();
    void PauseGroup(int group);
    void UnpauseGroup(int group);
    cTrack* GetTrackObject(ERSoundEvent* event, bool create);
    bool IsInMemory(cTrack* track) const;
    bool IsInMemory(ERSoundEvent* event) const;
    void onTrackDelete(cTrack* track);
    void printTrackList();
};

// ============================================================================
// cHitMan - Sound hit manager
// Object file: patch.obj
//
// Layout (from disassembly):
//   +0x30: bool (*m_sourceDataRequestHandler)(int, int, int*)
//   +0x50: cSoundCache m_cache
//   +0x54: int m_sequenceGroupTrackIds[...] (array indexed by id+10)
// ============================================================================
class cHitMan {
public:
    u8  m_pad00[0x30];
    void* m_sourceDataRequestHandler;  // +0x30 - function pointer
    u8  m_pad34[0x20];
    int m_sequenceGroupTrackIds[32];   // +0x54

    cHitMan();
    ~cHitMan();
    void Init();
    void Shutdown();
    void UpdateActiveTrackVolumes();
    void TimerCallback();
    void AddToUpdateList(cTrack* track);
    void RemoveFromUpdateList(cTrack* track);
    void DuckMapSetSndobPri(cTrack* track, int pri);
    int DuckMapMaxPri();
    int DuckMapSndobPri(cTrack* track);
    void DuckMapRemoveAll();
    void ClearControlGroups();
    cHitControlGroup* ControlGroup(int id);

    bool RegisterSourceDataRequestHandler(bool (*handler)(int, int, int*));
    bool GetSourceDataField(int param1, int param2, int* result);
    void SetSequenceGroupTrackId(int group, ERSoundEvent* event);
    ERSoundEvent* SequenceGroupTrackId(int group);
    bool StopCallbackTimer();
    bool StartCallbackTimer();
};

// ============================================================================
// cHitTimer - Simple timer for sound system
// Object file: boxx.obj (instantiated in boxx)
//
// Layout:
//   +0x00: int m_running
//   +0x04: int m_counter
// ============================================================================
class cHitTimer {
public:
    int m_running;    // +0x00
    int m_counter;    // +0x04

    bool Stop();
    bool Update();
};

// Global pointers
extern cHitMan* g_pHitMan;           // 0x804FFAD8
extern int g_musicMinVolume;          // 0x804FDD0C

#endif // PATCH_H
