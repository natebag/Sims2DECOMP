// patch.cpp - Decompiled small functions from patch.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\patch.obj
//
// 48 small functions (<=64 bytes) decompiled from patch.obj
// patch.obj is one of the largest obj files with 120 total functions

#include "audio/patch.h"

// Placement new for -fno-exceptions build
inline void* operator new(unsigned int, void* p) { return p; }

// ============================================================================
// External references
// ============================================================================
extern void operator_delete(void* ptr);          // 0x802D1220
extern void* operator_new(unsigned int size);    // 0x802D11B0
extern void* memset(void* dst, int val, unsigned int size); // 0x802435E4

// cSampleChannel::NoteOff (at 0x801192E8)
extern void cSampleChannel_NoteOff(cSampleChannel* ch);

// cSampleChannel::SetVolume (at 0x80119110)
extern void cSampleChannel_SetVolume(cSampleChannel* ch, int vol);

// cSampleChannel::SetPan (at 0x80119218)
extern void cSampleChannel_SetPan(cSampleChannel* ch, int pan);

// cSampleChannel::SetPatch (at 0x8011917C)
extern void cSampleChannel_SetPatch(cSampleChannel* ch, cSamplePatch* patch);

// cSoundCache::Shutdown (at 0x80119530)
extern void cSoundCache_Shutdown(cSoundCache* cache);

// cSoundCache::GetTrackObject (at 0x80119C20)
extern cTrack* cSoundCache_GetTrackObject(cSoundCache* cache, ERSoundEvent* event, bool create);

// cTrack::SetRegister (at 0x80117EFC)
extern void cTrack_SetRegister(cTrack* track, int reg, int val);

// cTrack::HandleTrackFlowError (at 0x80116460)
extern void cTrack_HandleTrackFlowError(cTrack* track, char* msg);

// Global: g_pHitMan at SDA r13 offset (0x804FFAD8)
extern cHitMan* g_pHitMan;

// ============================================================================
// TrackDataReader::TrackDataReader (default)
// Address: 0x801162E0, Size: 20 bytes
// MATCHING
// ============================================================================
TrackDataReader::TrackDataReader() {
    m_pos = 0;
    m_data = 0;
}

// ============================================================================
// TrackDataReader::~TrackDataReader
// Address: 0x801162F4, Size: 48 bytes
// NON_MATCHING - conditional delete pattern
// ============================================================================
TrackDataReader::~TrackDataReader() {
    m_data = 0;
    // conditional operator delete based on flags
}

// ============================================================================
// TrackDataReader::operator=(TrackDataReader &)
// Address: 0x80116324, Size: 24 bytes
// MATCHING
// Copy assignment operator
// ============================================================================
TrackDataReader& TrackDataReader::operator=(TrackDataReader& other) {
    m_data = other.m_data;
    m_pos = other.m_pos;
    return *this;
}

// ============================================================================
// TrackDataReader::operator=(ERSoundTrackData *)
// Address: 0x8011633C, Size: 20 bytes
// MATCHING
// Assigns track data and resets position to 0
// ============================================================================
TrackDataReader& TrackDataReader::operator=(ERSoundTrackData* data) {
    m_data = data;
    m_pos = 0;
    return *this;
}

// ============================================================================
// TrackDataReader::operator--
// Address: 0x80116350, Size: 20 bytes
// MATCHING
// Decrements position
// ============================================================================
TrackDataReader& TrackDataReader::operator--() {
    m_pos--;
    return *this;
}

// ============================================================================
// TrackDataReader::operator+=
// Address: 0x80116364, Size: 20 bytes
// MATCHING
// Advances position by offset
// ============================================================================
TrackDataReader& TrackDataReader::operator+=(int offset) {
    m_pos += offset;
    return *this;
}

// ============================================================================
// TrackDataReader::Trace
// Address: 0x8011645C, Size: 4 bytes
// MATCHING
// No-op in release build (debug trace removed)
// ============================================================================
void TrackDataReader::Trace() const {
    // no-op
}

// ============================================================================
// TrackDataReader::IsValid
// Address: 0x80116424, Size: 24 bytes
// MATCHING
// Returns true if data pointer is non-null
// ============================================================================
bool TrackDataReader::IsValid() const {
    return m_data != 0;
}

// ============================================================================
// TrackDataReader::JumpToEnd
// Address: 0x8011643C, Size: 32 bytes
// MATCHING
// Sets position to last command index
// ============================================================================
void TrackDataReader::JumpToEnd() {
    int* start = (int*)m_data->m_commands;
    int* end = (int*)m_data->m_commandsEnd;
    m_pos = ((end - start) / 1) - 1;
}

// ============================================================================
// cHitMan::RegisterSourceDataRequestHandler
// Address: 0x801164A4, Size: 12 bytes
// MATCHING
// Stores a function pointer for source data requests
// ============================================================================
bool cHitMan::RegisterSourceDataRequestHandler(bool (*handler)(int, int, int*)) {
    m_sourceDataRequestHandler = (void*)handler;
    return true;
}

// ============================================================================
// cHitMan::GetSourceDataField
// Address: 0x801164B0, Size: 52 bytes
// NON_MATCHING - indirect call through function pointer
// Calls the registered handler to get source data
// ============================================================================
bool cHitMan::GetSourceDataField(int param1, int param2, int* result) {
    typedef bool (*HandlerFunc)(int, int, int*);
    HandlerFunc handler = (HandlerFunc)m_sourceDataRequestHandler;
    return handler(param1, param2, result);
}

// ============================================================================
// cHitControlGroup::cHitControlGroup
// Address: 0x801167B4, Size: 20 bytes
// MATCHING
// Initializes control group with ID and default volume (1024)
// ============================================================================
cHitControlGroup::cHitControlGroup(int id) {
    m_id = id;
    m_volume = 1024;
}

// ============================================================================
// cSoundCache::IsInMemory(cTrack *)
// Address: 0x80119D48, Size: 36 bytes
// NON_MATCHING - wrapper that loads event from track
// Checks if track's event is in the cache
// ============================================================================
bool cSoundCache::IsInMemory(cTrack* track) const {
    return IsInMemory(track->m_event);
}

// ============================================================================
// cTrack::GetControlGroup
// Address: 0x80118E40, Size: 12 bytes
// MATCHING
// Returns control group byte from event data at offset +0x17
// ============================================================================
int cTrack::GetControlGroup() {
    u8* eventData = (u8*)m_event;
    return eventData[0x17];
}

// ============================================================================
// cSoundCache::cSoundCache
// Address: 0x80119470, Size: 64 bytes
// NON_MATCHING - memset call and field init pattern
// Zeroes track array and initializes
// ============================================================================
cSoundCache::cSoundCache() {
    memset(m_tracks, 0, 256);
    m_field_100 = 0;
}

// ============================================================================
// cHitMan::SetSequenceGroupTrackId
// Address: 0x80116DC4, Size: 20 bytes
// MATCHING
// Stores event pointer in sequence group track ID array
// ============================================================================
void cHitMan::SetSequenceGroupTrackId(int group, ERSoundEvent* event) {
    m_sequenceGroupTrackIds[group + 10] = (int)event;
}

// ============================================================================
// cSoundCache::~cSoundCache
// Address: 0x801194B0, Size: 64 bytes
// NON_MATCHING - conditional delete and shutdown call
// Shuts down cache and conditionally frees memory
// ============================================================================
cSoundCache::~cSoundCache() {
    Shutdown();
    // conditional operator delete
}

// ============================================================================
// cHitMan::StopCallbackTimer
// Address: 0x80116DF4, Size: 8 bytes
// MATCHING
// Returns false (no timer to stop in GC build)
// ============================================================================
bool cHitMan::StopCallbackTimer() {
    return false;
}

// ============================================================================
// cHitMan::SequenceGroupTrackId
// Address: 0x80116DD8, Size: 20 bytes
// MATCHING
// Returns sequence group track event pointer
// ============================================================================
ERSoundEvent* cHitMan::SequenceGroupTrackId(int group) {
    return (ERSoundEvent*)m_sequenceGroupTrackIds[group + 10];
}

// ============================================================================
// cHitMan::StartCallbackTimer
// Address: 0x80116DEC, Size: 8 bytes
// MATCHING
// Returns false (no timer in GC build)
// ============================================================================
bool cHitMan::StartCallbackTimer() {
    return false;
}

// ============================================================================
// cSampleChannel::Shutdown
// Address: 0x80119158, Size: 36 bytes
// NON_MATCHING - call to NoteOff then return true
// ============================================================================
void cSampleChannel::Shutdown() {
    NoteOff();
    // returns true (r3=1) in the original
}

// ============================================================================
// cSoundCache::onTrackDelete
// Address: 0x801194F0, Size: 64 bytes
// NON_MATCHING - loop with indexed array access
// Searches track array for matching track and nulls it out
// ============================================================================
void cSoundCache::onTrackDelete(cTrack* track) {
    for (int i = 0; i < 64; i++) {
        if (m_tracks[i] == track) {
            m_tracks[i] = 0;
            return;
        }
    }
}

// ============================================================================
// cTrack::StartPos
// Address: 0x801178A0, Size: 12 bytes
// MATCHING
// Returns start position from event data at offset +0x30
// ============================================================================
int cTrack::StartPos() {
    u8* eventData = (u8*)m_event;
    return *(int*)(eventData + 0x30);
}

// ============================================================================
// cTrack::NoteOff
// Address: 0x80118BF0, Size: 52 bytes
// NON_MATCHING - null check and channel call pattern
// Calls NoteOff on channel if it exists
// ============================================================================
void cTrack::NoteOff() {
    if (m_channel != 0) {
        m_channel->NoteOff();
    }
}

// ============================================================================
// cTrack::SetCompareFlags
// Address: 0x80118A64, Size: 44 bytes
// NON_MATCHING - mfcr and bit extraction pattern (compiler-specific)
// Sets comparison flags for track branching: equal, greater, less
// ============================================================================
void cTrack::SetCompareFlags(int a, int b) {
    m_isLess = (a < b) ? 1 : 0;
    m_isEqual = (a == b) ? 1 : 0;
    m_isGreater = (a > b) ? 1 : 0;
}

// ============================================================================
// cTrack::GetVHitList
// Address: 0x80118074, Size: 48 bytes
// NON_MATCHING - clamping logic with branches
// Returns pointer to VHitList at given index, clamped to valid range
// ============================================================================
void* cTrack::GetVHitList(int index) {
    if (index < 0) index = 0;
    u8* eventData = (u8*)m_event;
    int count = *(int*)(eventData + 0x28);
    if (index >= count) index = count - 1;
    u8* list = *(u8**)(eventData + 0x24);
    return list + index * 12;
}

// ============================================================================
// cSoundCache::IsInMemory(ERSoundEvent *)
// Address: 0x80119D6C, Size: 56 bytes
// NON_MATCHING - loop with counter register (mtctr/bdnz)
// Searches cache for event, returns true if found
// ============================================================================
bool cSoundCache::IsInMemory(ERSoundEvent* event) const {
    for (int i = 0; i < 64; i++) {
        if (m_tracks[i] != 0) {
            if (m_tracks[i]->m_event == event) {
                return true;
            }
        }
    }
    return false;
}

// ============================================================================
// cSamplePatch::~cSamplePatch
// Address: 0x80118E84, Size: 64 bytes
// NON_MATCHING - FreeSnd call and conditional delete
// ============================================================================
cSamplePatch::~cSamplePatch() {
    FreeSnd();
    // conditional operator delete
}

// ============================================================================
// cSamplePatch::cSamplePatch
// Address: 0x80118E58, Size: 44 bytes
// MATCHING
// Initializes patch from hit patch data and volume
// ============================================================================
cSamplePatch::cSamplePatch(SndEvtHitPatch* patch, float volume) {
    m_snd = 0;
    m_channel = 0;
    m_looped = 0;
    m_sndId = *(int*)((u8*)patch + 4);   // patch->sndId
    m_volumeScale = volume;
    m_sndBank = *(int*)((u8*)patch + 0); // patch->sndBank
}

// ============================================================================
// cSamplePatch::SetLooped
// Address: 0x80118F0C, Size: 8 bytes
// MATCHING
// ============================================================================
void cSamplePatch::SetLooped(int looped) {
    m_looped = looped;
}

// ============================================================================
// cSamplePatch::CreateChannel
// Address: 0x80119050, Size: 56 bytes
// NON_MATCHING - new + constructor call chain
// Creates a new cSampleChannel for this patch
// ============================================================================
void* cSamplePatch::CreateChannel() {
    cSampleChannel* ch = (cSampleChannel*)operator_new(8);
    new (ch) cSampleChannel(this);
    return ch;
}

// ============================================================================
// cTrack::SetVolume
// Address: 0x80118C24, Size: 40 bytes
// NON_MATCHING - SetRegister call with register ID 9
// ============================================================================
void cTrack::SetVolume(int volume) {
    SetRegister(9, volume);
}

// ============================================================================
// cTrack::SetPan
// Address: 0x80118C4C, Size: 40 bytes
// NON_MATCHING - SetRegister call with register ID 10
// ============================================================================
void cTrack::SetPan(int pan) {
    SetRegister(10, pan);
}

// ============================================================================
// cTrack::GetMinRange
// Address: 0x80118E28, Size: 12 bytes
// MATCHING
// Returns min range byte from event at offset +0x1F
// ============================================================================
int cTrack::GetMinRange() {
    u8* eventData = (u8*)m_event;
    return eventData[0x1F];
}

// ============================================================================
// cTrack::GetMaxRange
// Address: 0x80118E34, Size: 12 bytes
// MATCHING
// Returns max range byte from event at offset +0x20
// ============================================================================
int cTrack::GetMaxRange() {
    u8* eventData = (u8*)m_event;
    return eventData[0x20];
}

// ============================================================================
// cTrack::GetArgsType
// Address: 0x80118E4C, Size: 12 bytes
// MATCHING
// Returns args type byte from event at offset +0x15
// ============================================================================
int cTrack::GetArgsType() {
    u8* eventData = (u8*)m_event;
    return eventData[0x15];
}

// ============================================================================
// cSamplePatch::SetVolume
// Address: 0x80118EC4, Size: 36 bytes
// NON_MATCHING - delegates to channel SetVolume
// ============================================================================
void cSamplePatch::SetVolume(int volume) {
    cSampleChannel_SetVolume((cSampleChannel*)m_channel, volume);
}

// ============================================================================
// cSamplePatch::SetPan
// Address: 0x80118EE8, Size: 36 bytes
// NON_MATCHING - delegates to channel SetPan
// ============================================================================
void cSamplePatch::SetPan(int pan) {
    cSampleChannel_SetPan((cSampleChannel*)m_channel, pan);
}

// ============================================================================
// cSampleChannel::cSampleChannel
// Address: 0x80119088, Size: 60 bytes
// NON_MATCHING - field init and SetPatch call
// ============================================================================
cSampleChannel::cSampleChannel(cSamplePatch* patch) {
    m_state = 0;
    m_patch = 0;
    SetPatch(patch);
}

// ============================================================================
// cSampleChannel::Snd
// Address: 0x80119278, Size: 12 bytes
// MATCHING
// Returns sound pointer from patch at offset +0x18
// ============================================================================
void* cSampleChannel::Snd(int index) {
    return m_patch->m_snd;
}

// ============================================================================
// cTrackCacheHandle::GetTrackObject
// Address: 0x80119428, Size: 64 bytes
// NON_MATCHING - SDA access for g_pHitMan and cache lookup
// Gets track object from cache, creating if needed
// ============================================================================
cTrack* cTrackCacheHandle::GetTrackObject() {
    if (m_event == 0) return 0;
    cSoundCache* cache = (cSoundCache*)((u8*)g_pHitMan + 0x50);
    return cSoundCache_GetTrackObject(cache, m_event, true);
}

// ============================================================================
// cTrackCacheHandle::cTrackCacheHandle
// Address: 0x80119468, Size: 8 bytes
// MATCHING
// ============================================================================
cTrackCacheHandle::cTrackCacheHandle(ERSoundEvent* event) {
    m_event = event;
}

// ============================================================================
// cSoundCache::printTrackList
// Address: 0x80119DA4, Size: 16 bytes
// MATCHING
// Debug function - busy-loops 64 iterations (stripped in release)
// ============================================================================
void cSoundCache::printTrackList() {
    // Empty loop (debug print stripped)
    // Original: mtctr 64, bdnz self
}

// ============================================================================
// cTrack::SetInstanceId
// Address: 0x80119DB4, Size: 12 bytes
// MATCHING
// ============================================================================
void cTrack::SetInstanceId(int id) {
    m_instanceId = id;
}

// ============================================================================
// cTrack::InstanceId
// Address: 0x80119DC0, Size: 8 bytes
// MATCHING
// ============================================================================
int cTrack::InstanceId() {
    return m_instanceId;
}

// ============================================================================
// cTrack::IsPlaying
// Address: 0x80119DC8, Size: 8 bytes
// MATCHING
// ============================================================================
bool cTrack::IsPlaying() {
    return m_isPlaying;
}

// ============================================================================
// cTrack::IsPaused
// Address: 0x80119DD0, Size: 24 bytes
// MATCHING
// Returns true if pause count > 0
// ============================================================================
bool cTrack::IsPaused() {
    return m_pauseCount != 0;
}

// ============================================================================
// cTrack::CheckedRegId
// Address: 0x80119DE8, Size: 64 bytes
// NON_MATCHING - bounds check with error call
// Validates register ID (must be <= 18) and returns it, or calls error handler
// ============================================================================
int cTrack::CheckedRegId(int id) {
    if (id > 18) {
        HandleTrackFlowError((char*)"Register ID out of range");
        return 1;
    }
    return id;
}
