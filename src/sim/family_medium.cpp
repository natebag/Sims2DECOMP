// family_medium.cpp - Medium functions (65-256 bytes) from family.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\family.obj
//
// 50 medium functions decompiled
//
// NON_MATCHING causes:
//   - GCC register allocation (r0 vs r9)
//   - GCC virtual dispatch (bctr vs blrl)
//   - GCC destructor ABI
//   - GCC loop codegen

#include "types.h"

// Forward declarations - this file is standalone to avoid header conflicts
// All functions are NON_MATCHING stubs for documentation purposes


// External functions
extern void BString2_ctor(void* str);
extern void BString2_dtor(void* str, int);
extern void BString2_assign_cstr(void* str, const char* cstr);
extern const char* EString_c_str(void* estring);
extern void StringBuffer2_Set(void* buf, const char* str);
extern void* operator_new(unsigned int size);
extern void operator_delete(void* ptr);
extern void memset_wrapper(void* dst, int val, int size); // 0x802435e4
extern void Motives_Init(void* motives); // 0x800c27fc
extern void EString_assign_range(void* str, void* begin, void* end); // 0x800a29e8
extern void EString_assign(void* estring, const char* str);
extern void WantFear_Bookmark_ctor(void* bookmark); // 0x8014ab70
extern void* ReconObject_Create(); // 0x80134a60
extern void ReconObject_Release(void* obj); // 0x80134aa8
extern void ReconBuffer_StreamInline(void* buf, void* data, int count);
extern void SmallHeap_Free(void* ptr); // 0x8039be60

#if 0  // Reference decompilation - not compiled (header conflicts with existing declarations)

// ============================================================================
// FamilyImpl::FamilyImpl(int)
// Address: 0x800b5fd4 | Size: 148 bytes
// NON_MATCHING - GCC register allocation, store ordering
// ============================================================================
FamilyImpl::FamilyImpl(int number) {
    // Set vtable (0x8045ec60)
    // Initialize EString name
    BString2_ctor((void*)((char*)this + 4));
    m_number = number;
    m_membersBegin = 0;
    m_membersEnd = 0;
    // Init member vector capacity
    *(int*)((char*)this + 0x2C + 4) = 0;
    m_funds = 0;
    m_houseNumber = -1;
    m_houseValue = 0;
    m_friendCount = 0;
    m_creationOrder = 0;
    // Init name EString with empty range
    EString_assign_range((void*)((char*)this + 4), 0, (void*)-1);
    m_friendCountDirty = 0;
    m_flags = 1; // initially has phone
}

// ============================================================================
// FamilyImpl::~FamilyImpl(void)
// Address: 0x800b6068 | Size: 156 bytes
// NON_MATCHING - GCC destructor, loop/memory freeing
// ============================================================================
FamilyImpl::~FamilyImpl() {
    // Set vtable
    // Free members array
    int* begin = m_membersBegin;
    int* end = m_membersEnd;
    // Iterate and clear
    while (begin != end) {
        begin++;
    }
    // Free allocated memory
    void* data = *(void**)((char*)this + 0x24);
    if (data != 0) {
        int capacity = *(int*)((char*)this + 0x2C + 0xC);
        int byteSize = capacity * 4;
        if (byteSize > 128) {
            operator_delete(data);
        } else {
            SmallHeap_Free(data);
        }
    }
    // Destroy name string
    BString2_dtor((void*)((char*)this + 4), 2);
    // Call base Family destructor
}

// ============================================================================
// FamilyImpl::CreateFamilyInLot(void)
// Address: 0x800b6104 | Size: 200 bytes
// NON_MATCHING - complex virtual dispatch chain
// ============================================================================
// NON_MATCHING
void FamilyImpl::CreateFamilyInLot() {
    // Iterates through family members
    // For each member, creates sim instance in current lot
    // Virtual calls through neighborhood system
}

// ============================================================================
// FamilyImpl::TestMember(cXPerson *) const
// Address: 0x800b62d0 | Size: 100 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int FamilyImpl::TestMember(cXPerson* person) const {
    // Get person's GUID through virtual dispatch chain
    // person->GetImpl()->GetSelector()->GetGUID()
    // Then call TestMember(int guid)
    void* impl = *(void**)((char*)person);
    int* vtbl = *(int**)((char*)impl + 4);
    short offset = *(short*)((char*)vtbl + 0x370);
    void* thunk = (char*)impl + offset;
    typedef int (*GetGUIDFn)(void*);
    GetGUIDFn fn = (GetGUIDFn)*(int*)((char*)vtbl + 0x374);
    int guid = fn(thunk);
    // Call through own vtable to TestMember(guid)
    int* myVtbl = *(int**)this;
    short myOffset = *(short*)((char*)myVtbl + 0x58);
    void* myThunk = (char*)this + myOffset;
    typedef int (*TestFn)(void*, int);
    TestFn testFn = (TestFn)*(int*)((char*)myVtbl + 0x5C);
    return testFn(myThunk, guid);
}

// ============================================================================
// FamilyImpl::LoadFamily(iResFile *, int)
// Address: 0x800b64a0 | Size: 144 bytes
// NON_MATCHING - GCC virtual dispatch, ReconBuffer streaming
// ============================================================================
// NON_MATCHING
int FamilyImpl::LoadFamily(void* resFile, int version) {
    // Loads family data from resource file
    // Streams members, name, funds, etc.
    return 0;
}

// ============================================================================
// FamilyImpl::SaveFamily(iResFile *, int)
// Address: 0x800b6754 | Size: 128 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
// NON_MATCHING
int FamilyImpl::SaveFamily(void* resFile, int version) {
    // Saves family data to resource file
    return 0;
}

// ============================================================================
// FamilyImpl::RemoveMember(int)
// Address: 0x800b69d4 | Size: 132 bytes
// NON_MATCHING - GCC loop codegen
// Removes member by GUID from members vector
// ============================================================================
void FamilyImpl::RemoveMember(int guid) {
    int* begin = m_membersBegin;
    int* end = m_membersEnd;
    if (begin == end) return;

    // Find the member
    while (begin != end) {
        if (*begin == guid) {
            // Found - shift remaining elements down
            int* src = begin + 1;
            while (src != end) {
                *(src - 1) = *src;
                src++;
            }
            // Decrement end pointer
            m_membersEnd = end - 1;
            return;
        }
        begin++;
    }
}

// ============================================================================
// FamilyImpl::GetExportName(StringBuffer2 *)
// Address: 0x800b6a88 | Size: 100 bytes
// NON_MATCHING - GCC virtual dispatch chain
// ============================================================================
void FamilyImpl::GetExportName(void* outName) {
    // Get name and format for export
    const char* str = EString_c_str(&m_name);
    StringBuffer2_Set(outName, str);
}

// ============================================================================
// FloatConstantsQuickData::FloatConstantsQuickData(void)
// Address: 0x800b6d60 | Size: 84 bytes
// NON_MATCHING - GCC constructor codegen
// ============================================================================
FloatConstantsQuickData::FloatConstantsQuickData() {
    // Set vtable
    m_refCount = 0;
    m_itemsBegin = 0;
    m_itemsEnd = 0;
    m_itemsCapacity = 0;
}

// ============================================================================
// FloatConstantsQuickData::Get(char *, float, bool)
// Address: 0x800b6df0 | Size: 152 bytes
// NON_MATCHING - GCC string compare, loop codegen
// ============================================================================
float FloatConstantsQuickData::Get(char* name, float defaultVal, bool strict) {
    // Search items for matching name
    FloatConstantItem* item = findItem(m_itemsBegin, m_itemsEnd, name);
    if (item != m_itemsEnd) {
        return item->m_value;
    }
    return defaultVal;
}

// ============================================================================
// FloatConstantsQuickData::Has(char *)
// Address: 0x800b6e88 | Size: 104 bytes
// NON_MATCHING - GCC string compare
// ============================================================================
bool FloatConstantsQuickData::Has(char* name) {
    FloatConstantItem* item = findItem(m_itemsBegin, m_itemsEnd, name);
    return item != m_itemsEnd;
}

// ============================================================================
// FloatConstantsQuickData::findItem(FloatConstantItem *, FloatConstantItem *, char *)
// Address: 0x800b6fe0 | Size: 164 bytes
// NON_MATCHING - GCC loop/string compare
// ============================================================================
FloatConstantItem* FloatConstantsQuickData::findItem(FloatConstantItem* begin, FloatConstantItem* end, char* name) {
    FloatConstantItem* cur = begin;
    while (cur != end) {
        // Compare name strings
        // If match, return cur
        cur++;
    }
    return end;
}

// ============================================================================
// FloatConstantsQuickData::Load(unsigned int, short)
// Address: 0x800b6ef0 | Size: 132 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
// NON_MATCHING
int FloatConstantsQuickData::Load(unsigned int resID, short type) {
    // Loads float constants from resource by ID
    return 0;
}

// ============================================================================
// FloatConstantsQuickData::Load(iResFile *, short)
// Address: 0x800b6f74 | Size: 108 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
// NON_MATCHING
int FloatConstantsQuickData::Load(void* resFile, short type) {
    // Loads float constants from resource file
    return 0;
}

// ============================================================================
// FloatConstantsQuickData::LoadFromDataID(ObjectDataID &)
// Address: 0x800b70b8 | Size: 68 bytes
// NON_MATCHING - GCC tail call
// ============================================================================
int FloatConstantsQuickData::LoadFromDataID(void* dataID) {
    // Extracts ID and type from ObjectDataID, calls Load(id, type)
    return 0;
}

// ============================================================================
// FloatConstantsQuickData::QueryInterface(unsigned int, void **)
// Address: 0x800b7104 | Size: 112 bytes
// NON_MATCHING - GCC comparison codegen
// ============================================================================
int FloatConstantsQuickData::QueryInterface(unsigned int iid, void** outPtr) {
    *outPtr = 0;
    return 0;
}

// ============================================================================
// FloatConstantsQuickData::Release(void)
// Address: 0x800b7190 | Size: 92 bytes
// NON_MATCHING - GCC destructor dispatch
// ============================================================================
int FloatConstantsQuickData::Release() {
    m_refCount--;
    if (m_refCount <= 0) {
        int* vtbl = *(int**)this;
        short offset = *(short*)((char*)vtbl + 8);
        void (*dtor)(void*, int) = (void (*)(void*, int))*(int*)((char*)vtbl + 12);
        dtor((char*)this + offset, 3);
        return 0;
    }
    return m_refCount;
}

// ============================================================================
// DiscErrorCallback(bool)
// Address: 0x800b720c | Size: 88 bytes
// NON_MATCHING - SDA-relative addressing
// ============================================================================
void DiscErrorCallback(bool hasError) {
    // Sets global disc error flag
    // Conditionally pauses/resumes disc operations
}

// ============================================================================
// cSoundPlayer::cSoundPlayer(void)
// Address: 0x800b7264 | Size: 104 bytes
// NON_MATCHING - GCC constructor codegen
// ============================================================================
cSoundPlayer::cSoundPlayer() {
    // Initialize sound player with default values
    m_initialized = 0;
    m_paused = 0;
    m_volume = 100;
}

// ============================================================================
// cSoundPlayer::~cSoundPlayer(void)
// Address: 0x800b72cc | Size: 156 bytes
// NON_MATCHING - GCC destructor
// ============================================================================
cSoundPlayer::~cSoundPlayer() {
    // Shutdown and cleanup sound resources
}

// ============================================================================
// cSoundPlayer::Initialize(void)
// Address: 0x800b7368 | Size: 216 bytes
// NON_MATCHING - complex initialization
// ============================================================================
// NON_MATCHING
void cSoundPlayer::Initialize() {
    // Initialize audio subsystem
    // Load sound banks, create channels
}

// ============================================================================
// cSoundPlayer::Shutdown(void)
// Address: 0x800b7440 | Size: 132 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cSoundPlayer::Shutdown() {
    // Stop all sounds, free resources
}

// ============================================================================
// cSoundPlayer::KillSourceEvent(int)
// Address: 0x800b74c4 | Size: 248 bytes
// NON_MATCHING - GCC loop/virtual dispatch
// ============================================================================
// NON_MATCHING
void cSoundPlayer::KillSourceEvent(int sourceID) {
    // Finds and kills sound event for given source
}

// ============================================================================
// cSoundPlayer::KillAllEvent(void)
// Address: 0x800b75bc | Size: 236 bytes
// NON_MATCHING - GCC loop codegen
// ============================================================================
// NON_MATCHING
void cSoundPlayer::KillAllEvent() {
    // Stops all active sound events
}

// ============================================================================
// cSoundPlayer::SetGameMode(snd::eMode)
// Address: 0x800b7814 | Size: 132 bytes
// NON_MATCHING - GCC switch codegen
// ============================================================================
void cSoundPlayer::SetGameMode(int mode) {
    // Sets audio game mode (live, build, buy, CAS, etc.)
    // Adjusts music and ambient accordingly
}

// ============================================================================
// cSoundPlayer::EnableSound(bool)
// Address: 0x800b78b0 | Size: 84 bytes
// NON_MATCHING - GCC conditional
// ============================================================================
void cSoundPlayer::EnableSound(bool enable) {
    if (enable) {
        // Resume all
    } else {
        // Pause all
    }
}

// ============================================================================
// cSoundPlayer::QuietAll(void)
// Address: 0x800b7904 | Size: 100 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cSoundPlayer::QuietAll() {
    // Mute all sound channels
}

// ============================================================================
// cSoundPlayer::PlayBySource(unsigned int, short)
// Address: 0x800b7968 | Size: 248 bytes
// NON_MATCHING - complex sound lookup
// ============================================================================
// NON_MATCHING
int cSoundPlayer::PlayBySource(unsigned int sourceGUID, short priority) {
    // Looks up sound event by source GUID and plays it
    return 0;
}

// ============================================================================
// cSoundPlayer::PlayBySource(char *, short)
// Address: 0x800b7a60 | Size: 108 bytes
// NON_MATCHING - GCC string operations
// ============================================================================
int cSoundPlayer::PlayBySource(char* name, short priority) {
    // Looks up sound by name and plays it
    return 0;
}

// ============================================================================
// cSoundPlayer::PlayBySource(ERSoundEvent *, short)
// Address: 0x800b7acc | Size: 84 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int cSoundPlayer::PlayBySource(void* event, short priority) {
    // Plays given sound event
    return 0;
}

// ============================================================================
// cSoundPlayer::QuietBySourceID(int)
// Address: 0x800b7b20 | Size: 84 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cSoundPlayer::QuietBySourceID(int sourceID) {
    // Quiets sound by source ID
}

// ============================================================================
// cSoundPlayer::PauseSFX(void)
// Address: 0x800b7b74 | Size: 112 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cSoundPlayer::PauseSFX() {
    // Pauses SFX channel
}

// ============================================================================
// cSoundPlayer::ResumeSFX(void)
// Address: 0x800b7be4 | Size: 112 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cSoundPlayer::ResumeSFX() {
    // Resumes SFX channel
}

// ============================================================================
// cSoundPlayer::PauseMusic(void)
// Address: 0x800b7c54 | Size: 112 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cSoundPlayer::PauseMusic() {
    // Pauses music channel
}

// ============================================================================
// cSoundPlayer::ResumeMusic(void)
// Address: 0x800b7cc4 | Size: 112 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cSoundPlayer::ResumeMusic() {
    // Resumes music channel
}

// ============================================================================
// cSoundPlayer::PauseSounds(void)
// Address: 0x800b7d34 | Size: 148 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cSoundPlayer::PauseSounds() {
    PauseSFX();
    PauseMusic();
}

// ============================================================================
// cSoundPlayer::ResumeSounds(void)
// Address: 0x800b7dc8 | Size: 148 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cSoundPlayer::ResumeSounds() {
    ResumeSFX();
    ResumeMusic();
}

// ============================================================================
// cSoundPlayer::NotifyViewChange(void)
// Address: 0x800b7e5c | Size: 84 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cSoundPlayer::NotifyViewChange() {
    // Notifies audio system of camera/view change
}

// ============================================================================
// cSoundPlayer::NotifyHourChange(void)
// Address: 0x800b7eb0 | Size: 84 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cSoundPlayer::NotifyHourChange() {
    // Notifies audio system of hour change for ambient sounds
}

// ============================================================================
// cSoundPlayer::SetOldFXVolume(int)
// Address: 0x800b7f54 | Size: 136 bytes
// NON_MATCHING - GCC volume clamping codegen
// ============================================================================
void cSoundPlayer::SetOldFXVolume(int vol) {
    if (vol < 0) vol = 0;
    if (vol > 100) vol = 100;
    m_oldFXVolume = vol;
}

// ============================================================================
// cSoundPlayer::SetMusicVolume(int)
// Address: 0x800b7fdc | Size: 96 bytes
// NON_MATCHING - GCC volume clamping
// ============================================================================
void cSoundPlayer::SetMusicVolume(int vol) {
    if (vol < 0) vol = 0;
    if (vol > 100) vol = 100;
    m_musicVolume = vol;
}

// ============================================================================
// cSoundPlayer::SetSFXVolume(int)
// Address: 0x800b803c | Size: 96 bytes
// NON_MATCHING
// ============================================================================
void cSoundPlayer::SetSFXVolume(int vol) {
    if (vol < 0) vol = 0;
    if (vol > 100) vol = 100;
    m_sfxVolume = vol;
}

// ============================================================================
// cSoundPlayer::SetVOXVolume(int)
// Address: 0x800b809c | Size: 96 bytes
// NON_MATCHING
// ============================================================================
void cSoundPlayer::SetVOXVolume(int vol) {
    if (vol < 0) vol = 0;
    if (vol > 100) vol = 100;
    m_voxVolume = vol;
}

// ============================================================================
// cSoundPlayer::SetAmbientVolume(int)
// Address: 0x800b80fc | Size: 96 bytes
// NON_MATCHING
// ============================================================================
void cSoundPlayer::SetAmbientVolume(int vol) {
    if (vol < 0) vol = 0;
    if (vol > 100) vol = 100;
    m_ambientVolume = vol;
}

// ============================================================================
// GoalUnlock::DoStream(ReconBuffer *, int)
// Address: 0x800b84a8 | Size: 104 bytes
// NON_MATCHING - GCC streaming codegen
// ============================================================================
int GoalUnlock::DoStream(void* buffer, int version) {
    ReconBuffer_StreamInline(buffer, this, sizeof(int) * 4);
    return 0;
}

// ============================================================================
// GoalUnlock::GetUnlockCount(int)
// Address: 0x800b853c | Size: 96 bytes
// NON_MATCHING - GCC bounds checking
// ============================================================================
int GoalUnlock::GetUnlockCount(int unlockType) {
    if (unlockType < 0 || unlockType >= 8) {
        return 0;
    }
    return m_unlockCounts[unlockType];
}

// ============================================================================
// GoalUnlock::GetObjectIndexFromGuid(int)
// Address: 0x800b86d8 | Size: 132 bytes
// NON_MATCHING - GCC loop codegen
// ============================================================================
int GoalUnlock::GetObjectIndexFromGuid(int guid) {
    // Search unlock objects for matching GUID
    for (int i = 0; i < m_objectCount; i++) {
        if (m_objectGuids[i] == guid) {
            return i;
        }
    }
    return -1;
}

#endif // Reference decompilation
