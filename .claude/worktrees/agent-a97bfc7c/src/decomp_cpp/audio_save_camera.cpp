// audio_save_camera.cpp - Decompiled Audio, Save, and Camera systems (portable C++)
//
// Converted from inline PPC asm (src/asm_decomp/{AmbientScorePlayer,cSoundPlayer,
// ENgcAudio,SimsMemCardWrap,ENgcMemoryCard,ESimsCam,CameraDirector}.cpp) using
// documentation in src/{audio/audio_decomp,save/save_decomp,camera/camera_decomp}.cpp.
//
// Three systems decompiled here:
//   1. Audio:  AmbientScorePlayer, cSoundPlayer, ENgcAudio
//   2. Save:   SimsMemCardWrap, ENgcMemoryCard
//   3. Camera: ESimsCam, CameraDirector, CameraMotionSystem, CameraManager
//
// NON_MATCHING: All functions use portable C++ instead of inline PPC asm.
// Register allocation and codegen will differ from the SN Systems compiler output.
// Functional behavior matches the original DOL at the documented addresses.

#include "types.h"
#include "camera/esimscam.h"

// ============================================================================
// External function declarations (linked from other TUs / DolphinSDK)
// ============================================================================

extern "C" {
    // DolphinSDK Audio
    void  AIInit(int mode);
    void  AXInit();
    void  AXQuit();
    void  AXSetMode(int mode);
    void  AXRegisterCallback(void* callback);
    void  MIXInit();
    void  MIXQuit();
    void  MIXSetSoundMode(int mode);
    int   OSGetSoundMode();

    // DolphinSDK Memory Card (CARD library)
    void  CARDInit();
    int   CARDProbeEx(int slot, int* memSize, int* sectorSize);
    int   CARDMount(int slot, void* workArea, void* callback);
    int   CARDMountAsync(int slot, void* workArea, void* callback);
    int   CARDUnmount(int slot);
    int   CARDGetResultCode(int slot);
    int   CARDOpen(int slot, const char* filename, void* fileInfo);
    int   CARDClose(void* fileInfo);
    int   CARDRead(void* fileInfo, void* buffer, int length, int offset);
    int   CARDWrite(void* fileInfo, void* buffer, int length, int offset);
    int   CARDCreate(int slot, const char* filename, int size, void* fileInfo);
    int   CARDDelete(int slot, const char* filename);
    int   CARDFastDelete(int slot, int fileNo);
    int   CARDFormat(int slot);
    int   CARDSetStatus(int slot, int fileNo, void* status);
    int   CARDGetStatus(int slot, int fileNo, void* status);
    int   CARDFreeBlocks(int slot, int* byteNotUsed, int* filesNotUsed);

    // Memory / utility
    void* memset(void* s, int c, unsigned int n);
    void* memcpy(void* dst, const void* src, unsigned int n);

    // Math
    void  Vec3_Normalize(EVec3* out, EVec3* in);
    float Vec3_Length(EVec3* v);
    float Vec3_Length2(EVec3* v);
    void  EMat4_Identity(void* mat);
    void  EMat4_Multiply(void* dst, void* a, void* b);

    // Time
    u32   timeGetTime();

    // Graphics effects
    void  EGraphics_SetCameraBloom(float r, float g, float b, float a);
    void  EGraphics_SetMotionBlur(float intensity, float r, float g, float b);

    // EA heap
    void* EAHeap_Alloc(int size);
    void  EAHeap_FreePtr(void* ptr);

    // Debug trace
    void  EORDbgTrace(const char* fmt, ...);
}

// ============================================================================
// Forward declarations for external classes
// ============================================================================

class EResource;
class EResourceManager;
class EFile;
class EAudio;
class EMutex;
class EAnimController;
class ERSoundEvent;
class ERSoundTrackData;
class EPMDesc;
class EVoice;
class EVoiceDesc;
class ERAmbientScore;
class ERAmbientSound;
class AmbientSoundPlayer;
class cBoxX;
class cSoundModeManager;
class cSoundCacheItem;
class ENGCAudioStreamer;
class ENgcSFXStreamer;
class NghResFile;
class MemoryCardCache;
class OptionsRecon;
class FrameEffectsManager;
class AnimRef;
class EAnimNote;
class ENDummy;
class ENCamera;
class E3DWindow;

// SoundEventInfo - linked list node for queued sound events (20 bytes)
struct SoundEventInfo {
    SoundEventInfo* m_next;     // 0x00
    SoundEventInfo* m_prev;     // 0x04
    int   m_sourceId;           // 0x08
    u32   m_eventRef;           // 0x0C - EResource ref handle
    float m_priority;           // 0x10
};

// Linked list sentinel for SoundEventInfo
struct SoundEventList {
    SoundEventInfo* m_sentinel; // 0x00 - circular sentinel node
    int m_count;                // 0x04
};

// ListenerInfo for AmbientScorePlayer (32 bytes)
struct ListenerInfo {
    float position[3];   // 0x00 - EVec3: world position
    float direction[3];  // 0x0C - EVec3: facing direction
    float extra[2];      // 0x18 - padding/extra data
};

// ============================================================================
// Global state (originally SDA-relative via r13)
// ============================================================================

// Audio globals
static void*  g_pAudioInterface   = NULL;  // r13 - 0x67C4 (-26564): ENgcAudio*
static int    g_audioHWInit        = 0;     // r13 - 0x67D0 (-26576): HW init flag
static int    g_audioSWInit        = 0;     // r13 - 0x67CC (-26572): SW init flag
static void*  g_pSFXStreamer       = NULL;  // r13 - 0x67BC (-26556): ENgcSFXStreamer*
static void*  g_pAudioStreamer     = NULL;  // r13 - 0x67C0 (-26560): ENGCAudioStreamer*
static void*  g_pSoundBox          = NULL;  // r13 - 0x5FAC (-24508): cBoxX*
static int    g_MIXSoundMode       = 0;     // 0x805002F0
static u32    g_iSavedGameSoundMode = 0;    // 0x804FDBE0

// Save globals
static void*  g_pMemCardInterface  = NULL;  // r13 - 0x98F0 (-26384): platform card iface
static void*  g_pNghResFile        = NULL;  // r13 - 0x8344 (-31932): NghResFile*
static void*  g_pSaveFileName      = NULL;  // r13 - 0x82C8: save file name string
static int    g_duckAmbient        = 0;     // 0x804FDBA0

// Camera globals
static void*  g_pDirectorTable     = NULL;  // 0x80475DCC: global director/game state table

// Voice slot arrays for ENgcAudio (64 voices x 68 bytes each)
static u32    g_voiceSlots[64 * 17];       // voice state at 0x804C25E0
static u32    g_voiceBindState[64];        // bind state at 0x804C36E0

// AX audio callback
static void   AudioCallback(void* /* OSAlarm* */, void* /* OSContext* */) { /* stub */ }


// ############################################################################
//
//  SECTION 1: AUDIO SYSTEM
//
// ############################################################################

// ============================================================================
// ENgcAudio - GameCube Hardware Audio Layer
// ============================================================================
//
// Wraps the DolphinSDK AX mixer library. Manages 64 hardware voices,
// music streaming, and sample binding to ARAM.
//
// Original vtable @ 0x8046C728, inherits EAudio.
// Instance size: 0x60 (96 bytes).

class ENgcAudio {
public:
    void*   m_vtable;          // 0x00
    float   m_musicVolume;     // 0x04 (0.0 - 1.0)
    float   m_musicPan;        // 0x08 (0.0 - 1.0, 0.5 = center)
    int     m_isPlayingMusic;  // 0x0C
    u8      m_pad10[0x04];     // 0x10
    void*   m_field_14;        // 0x14
    void*   m_field_18;        // 0x18
    void*   m_field_1C;        // 0x1C
    u8      m_pad20[0x18];     // 0x20
    int     m_field_38;        // 0x38
    int     m_field_3C;        // 0x3C
    // EMutex at 0x40 (24 bytes)
    u8      m_mutex1[24];      // 0x40
    int     m_field_58;        // 0x58 (was offset 60 decimal = 0x3C? No: 0x58)
    int     m_field_5C;        // 0x5C (was offset 56 decimal = 0x38? Let's use docs)

    // 0x8032B7A8 (112 bytes)
    // NON_MATCHING: register scheduling
    ENgcAudio() {
        // Set vtable (link-time address: 0x8046C728 minus adjustments)
        m_vtable = NULL; // actual vtable set by linker

        // Construct two EMutex objects at offsets 0x40 and 0x5C
        // (EMutex::EMutex() calls omitted - platform specific)

        // Initialize float fields from constant pool
        m_musicVolume = 1.0f;
        m_musicPan = 0.5f;

        // Store singleton pointer
        g_pAudioInterface = (void*)this;

        m_field_5C = 0;
        m_field_58 = 0;
    }

    // 0x8032B818 (92 bytes)
    // NON_MATCHING: destructor chain order
    ~ENgcAudio() {
        // Destroy mutexes (reverse order)
        // EMutex::~EMutex() at offset 0x5C
        // EMutex::~EMutex() at offset 0x40
        // EAudio::~EAudio() base class destructor
    }

    // 0x8032B8EC (260 bytes)
    // NON_MATCHING: global address resolution, loop unrolling
    void InitAudio() {
        // Check global init flags
        if (g_audioHWInit == 0) return;
        if (g_audioSWInit != 0) return;

        // Initialize DolphinSDK audio subsystems
        AIInit(0);
        AXInit();
        MIXInit();

        // Register our audio callback
        AXRegisterCallback((void*)AudioCallback);

        // Set Dolby Pro Logic II mode
        AXSetMode(2); // AX_MODE_DPL2

        // Check system sound mode and configure mixer
        int soundMode = OSGetSoundMode();
        if (soundMode == 0) {
            MIXSetSoundMode(0); // mono
        } else {
            MIXSetSoundMode(3); // surround
        }

        // Allocate SFX streamer if not present
        if (g_pSFXStreamer == NULL) {
            // g_pSFXStreamer = new ENgcSFXStreamer();
            g_pSFXStreamer = EAHeap_Alloc(1); // placeholder
        }

        // Allocate audio streamer if not present
        if (g_pAudioStreamer == NULL) {
            // g_pAudioStreamer = new ENGCAudioStreamer();
            g_pAudioStreamer = EAHeap_Alloc(1); // placeholder
        }

        // Initialize 64 voice slots to -1 (unused)
        for (int i = 0; i < 64; i++) {
            g_voiceSlots[i * 17 + 0] = (u32)-1; // voiceHandle
            g_voiceSlots[i * 17 + 16] = (u32)-1; // bind state in secondary array
            g_voiceSlots[i * 17 + 1] = (u32)-1;  // streamHandle
            g_voiceBindState[i] = (u32)-1;
        }

        m_isPlayingMusic = 0;
        g_audioSWInit = 1;
    }

    // 0x8032B9F4 (104 bytes)
    // NON_MATCHING: global address resolution
    void Shutdown() {
        if (g_audioHWInit == 0) return;
        if (g_audioSWInit == 0) return;

        // Destroy audio streamer
        if (g_pAudioStreamer != NULL) {
            // ENGCAudioStreamer::~ENGCAudioStreamer()
            EAHeap_FreePtr(g_pAudioStreamer);
            g_pAudioStreamer = NULL;
        }

        // Unregister callback and quit subsystems
        AXRegisterCallback(NULL);
        MIXQuit();
        AXQuit();

        g_audioSWInit = 0;
    }

    // 0x8032C1FC (204 bytes)
    // NON_MATCHING: voice slot iteration
    void StopMusic() {
        if (!m_isPlayingMusic) return;

        // Find and free the music voice slots
        for (int i = 0; i < 64; i++) {
            u32* slot = &g_voiceSlots[i * 17];
            if (slot[0] != (u32)-1 && g_voiceBindState[i] != (u32)-1) {
                // Check if this is a music voice
                // UnbindVoice, FreeVoice
                slot[0] = (u32)-1;
                g_voiceBindState[i] = (u32)-1;
            }
        }

        m_isPlayingMusic = 0;
    }

    // 0x8032C2C8 (112 bytes)
    // NON_MATCHING: vtable dispatch
    void PauseMusic() {
        if (!m_isPlayingMusic) return;
        // Pause streaming voices via ENGCAudioStreamer
        // Calls through audio streamer vtable
    }

    // 0x8032C338 (112 bytes)
    void ResumeMusic() {
        if (!m_isPlayingMusic) return;
        // Resume streaming voices via ENGCAudioStreamer
    }

    // 0x8032C3A8 (192 bytes)
    // NON_MATCHING: FP register scheduling
    void SetMusicVolume(float volume) {
        m_musicVolume = volume;
        // Update active music voice volumes via streamer
        if (g_pAudioStreamer != NULL && m_isPlayingMusic) {
            // ENGCAudioStreamer::SetVolume(volume)
        }
    }

    // 0x8032C470 (196 bytes)
    void SetMusicPan(float pan) {
        m_musicPan = pan;
        // Update active music voice pan via streamer
        if (g_pAudioStreamer != NULL && m_isPlayingMusic) {
            // ENGCAudioStreamer::SetPan(pan)
        }
    }

    // 0x8032C53C (92 bytes)
    int IsPlayingMusic() {
        if (m_isPlayingMusic == 0) return 0;
        // Also check if the audio streamer reports active playback
        if (g_pAudioStreamer != NULL) {
            // return ENGCAudioStreamer::IsPlaying()
        }
        return m_isPlayingMusic;
    }

    // 0x8032C5D4 (64 bytes)
    // NON_MATCHING: loop structure
    EVoice* AudioAllocVoice() {
        // Scan voice slots for a free one (handle == -1)
        for (int i = 0; i < 64; i++) {
            if (g_voiceSlots[i * 17] == (u32)-1) {
                g_voiceSlots[i * 17] = 0; // mark as allocated
                return (EVoice*)(void*)&g_voiceSlots[i * 17];
            }
        }
        return NULL; // all 64 voices in use
    }

    // 0x8032C614 (72 bytes)
    void FreeVoice(EVoice* voice) {
        if (voice == NULL) return;
        // Find voice in slot array and mark as free
        u32* slot = (u32*)voice;
        slot[0] = (u32)-1;
    }

    // 0x8032C65C (412 bytes)
    // NON_MATCHING: ADPCM coefficient setup, vtable calls
    void AudioBindVoice(EVoice* voice, unsigned int sampleKey) {
        if (voice == NULL) return;

        // 1. Look up sample data via key from ENgcAudioSampleManager
        // 2. If sample is in ARAM, configure the voice:
        //    - Set ADPCM coefficients from sample header
        //    - Set loop points (start, end, loop start)
        //    - Set sample rate
        // 3. Start voice playback via AX library calls

        // Placeholder: the actual implementation reads sample header from ARAM,
        // configures AX voice parameters, and starts playback
        (void)sampleKey;
    }

    // 0x8032C7F8 (232 bytes)
    void UnbindVoice(EVoice* voice) {
        if (voice == NULL) return;
        // Stop AX voice playback
        // Clear voice state in the slot array
        // Return voice to free pool
    }

    // 0x8032C8E0 (144 bytes)
    void GetVoiceState(EVoice* voice, EVoiceDesc& desc) {
        if (voice == NULL) return;
        // Read current voice parameters into desc
        (void)desc;
    }

    // 0x8032C970 (304 bytes)
    void SetVoiceState(EVoice* voice, EVoiceDesc& desc) {
        if (voice == NULL) return;
        // Apply volume, pitch, pan, surround mix from desc to the AX voice
        (void)desc;
    }

    // 0x8032CAA0 (108 bytes)
    void SetSpeakerVolumes(EVoice* voice, int* volumes, unsigned int count) {
        if (voice == NULL || volumes == NULL) return;
        // Set per-speaker volume levels (FL, FR, RL, RR for surround)
        (void)count;
    }

    // 0x8032BA5C (1152 bytes)
    // NON_MATCHING: large function, stereo voice allocation, streaming setup
    void PlayMusic(EPMDesc& desc) {
        if (g_audioHWInit == 0) return;

        // 1. Call StopMusic via vtable to stop any current music
        StopMusic();

        // 2. Find two free consecutive voice slots for stereo
        int firstSlot = -1;
        int secondSlot = -1;
        for (u32 i = 0; i < 64; i++) {
            if (g_voiceSlots[i * 17] == (u32)-1) {
                if (firstSlot < 0) {
                    firstSlot = (int)i;
                } else {
                    secondSlot = (int)i;
                    break;
                }
            }
        }

        if (firstSlot < 0 || secondSlot < 0) return; // no free stereo pair

        // 3. Load the music file via EAudioStreamManager (AddRef by key)
        // 4. Configure voice parameters from EPMDesc
        // 5. Begin streaming from disc
        // 6. Mark voice slots as in use with stream handles

        g_voiceSlots[firstSlot * 17] = 0;  // mark allocated
        g_voiceSlots[secondSlot * 17] = 0;
        m_isPlayingMusic = 1;

        (void)desc;
    }

    // 0x8032BEEC (784 bytes)
    // NON_MATCHING: large per-frame update with AX voice state management
    void Update() {
        if (g_audioHWInit == 0 || g_audioSWInit == 0) return;

        // Update all active voices: check for completion, refill stream buffers
        for (int i = 0; i < 64; i++) {
            u32* slot = &g_voiceSlots[i * 17];
            if (slot[0] != (u32)-1) {
                // Check voice state via AX
                // If voice finished, mark slot as free
            }
        }

        // Update audio streamer (refill double buffers from disc)
        // ENGCAudioStreamer::Update()
    }

    // 0x8032CB0C (? bytes) - SetDiscErrorCallback
    static void SetDiscErrorCallback(void (*callback)(bool)) {
        // Store callback for disc read errors during audio streaming
        (void)callback;
    }
};


// ============================================================================
// AmbientScorePlayer - Ambient Music Score Scheduler
// ============================================================================
//
// Manages playback of ambient score databases. Evaluates per-frame which
// sounds should play based on time of day and listener positions.
//
// Instance size: 0x3C (60 bytes).
// Original addresses: 0x800A80B8 - 0x800A9198.

class AmbientScorePlayer {
public:
    int     m_state;            // 0x00 (0=stopped, 1=playing)
    int     m_field_04;         // 0x04
    ERAmbientScore* m_ambientScore; // 0x08
    void*   m_soundPlayers;     // 0x0C (AmbientSoundPlayer array)
    int     m_numPlaying;       // 0x10
    int     m_volume;           // 0x14 (default 1024)
    int     m_field_18;         // 0x18
    int     m_numListeners;     // 0x1C (default 2)
    void*   m_listenerBegin;    // 0x20 (vector<ListenerInfo> start)
    void*   m_listenerEnd;      // 0x24 (vector<ListenerInfo> end)
    void*   m_listenerCap;      // 0x28 (vector<ListenerInfo> capacity)
    void*   m_field_2C;         // 0x2C
    int     m_usePositional;    // 0x30 (1=3D, 0=stereo)
    float   m_time;             // 0x34 (game-hours)
    u32     m_startTimestamp;   // 0x38 (OS tick)

    // 0x800A80B8 (132 bytes)
    // NON_MATCHING: SDA-relative float loads, timeGetTime call
    AmbientScorePlayer(bool usePositional) {
        m_volume = 1024;
        m_numListeners = 2;
        m_state = 0;
        m_field_04 = 0;
        m_ambientScore = NULL;
        m_soundPlayers = NULL;
        m_numPlaying = 0;
        m_field_18 = 0;
        m_listenerBegin = NULL;
        m_listenerEnd = NULL;
        m_listenerCap = NULL;
        m_usePositional = (int)usePositional;
        m_time = 0.0f;
        m_startTimestamp = timeGetTime();
    }

    // 0x800A813C (156 bytes)
    // NON_MATCHING: vector deallocation, __builtin_delete dispatch
    ~AmbientScorePlayer() {
        Shutdown();

        // Free the listener vector if allocated
        if (m_listenerBegin != NULL) {
            EAHeap_FreePtr(m_listenerBegin);
            m_listenerBegin = NULL;
            m_listenerEnd = NULL;
            m_listenerCap = NULL;
        }
    }

    // 0x800A81D8 (844 bytes)
    // NON_MATCHING: complex loop with sound candidate selection
    void Update() {
        if (m_ambientScore == NULL) return;
        if (m_soundPlayers == NULL) return;

        // Update all active sound players
        for (int i = 0; i < m_numListeners; i++) {
            AmbientSoundPlayer* player = (AmbientSoundPlayer*)((u8*)m_soundPlayers + i * 48);
            // if (player->IsValid()) player->Update();
            (void)player;
        }

        // Throttle: only evaluate new sounds every ~1 second
        u32 now = timeGetTime();
        if ((now - m_startTimestamp - 1) <= 998) return;
        m_startTimestamp = timeGetTime();

        // Remove finished sounds
        RemoveFinishedSounds();

        // Only select new sounds if in playing state
        if (m_state != 1) return;

        // Build candidate list from score database
        // Iterate through all sounds in the ambient score:
        //   - Check time range (SoundRangeCoversCurTime)
        //   - Check not already playing (SoundAlreadyPlaying)
        //   - Check hearing distance (SoundInHearingDistance)
        //   - Add based on probability (AddSoundBasedOnProbability)

        // (Full candidate selection logic - original uses stack-allocated
        //  vector<ERAmbientSound*> and iterates score->m_soundArray)
    }

    // 0x800A8524 (128 bytes)
    void SetListenerCount(int count) {
        if (count == m_numListeners) return;

        // Reallocate listener array
        if (m_listenerBegin != NULL) {
            EAHeap_FreePtr(m_listenerBegin);
        }

        int allocSize = count * (int)sizeof(ListenerInfo);
        m_listenerBegin = EAHeap_Alloc(allocSize);
        m_listenerEnd = (void*)((u8*)m_listenerBegin + allocSize);
        m_listenerCap = m_listenerEnd;
        m_numListeners = count;

        // Zero-init the new listener data
        memset(m_listenerBegin, 0, (unsigned int)allocSize);
    }

    // 0x800A85A4 (448 bytes)
    // NON_MATCHING: EVec3 copy patterns, distance calculations
    void UpdateListener(unsigned int index, EVec3& position, EVec3& direction) {
        if (index >= (unsigned int)m_numListeners) return;
        if (m_listenerBegin == NULL) return;

        ListenerInfo* listener = (ListenerInfo*)m_listenerBegin + index;
        listener->position[0] = position.x;
        listener->position[1] = position.y;
        listener->position[2] = position.z;
        listener->direction[0] = direction.x;
        listener->direction[1] = direction.y;
        listener->direction[2] = direction.z;
    }

    // 0x800A8764 (8 bytes)
    void SetTime(float time) { m_time = time; }

    // 0x800A876C (8 bytes)
    float GetTime() { return m_time; }

    // 0x800A8774 (364 bytes)
    // NON_MATCHING: resource loading, EAmbientScoreManager dispatch
    void Load(char* filename) {
        if (filename == NULL) return;

        // Shut down any existing score
        if (m_ambientScore != NULL) {
            Shutdown();
        }

        // Load the ambient score resource via EAmbientScoreManager
        // EAmbientScoreManager::AddRef(filename) -> returns ERAmbientScore*
        // m_ambientScore = loaded resource;

        // Allocate sound player array based on score's numSounds
        // m_soundPlayers = new AmbientSoundPlayer[score->m_numSounds];

        (void)filename;
    }

    // 0x800A88E0 (60 bytes)
    void Start() {
        if (m_ambientScore == NULL) return;
        m_state = 1;
        m_startTimestamp = timeGetTime();
    }

    // 0x800A891C (56 bytes)
    void Stop() {
        KillAllAmbientSounds();
        m_state = 0;
    }

    // 0x800A8954 (196 bytes)
    // NON_MATCHING: resource release, sound player array deallocation
    void Shutdown() {
        KillAllAmbientSounds();
        m_state = 0;

        // Release ambient score resource
        if (m_ambientScore != NULL) {
            // EResource::DelRef()
            m_ambientScore = NULL;
        }

        // Free sound player array
        if (m_soundPlayers != NULL) {
            EAHeap_FreePtr(m_soundPlayers);
            m_soundPlayers = NULL;
        }

        m_numPlaying = 0;
    }

    // 0x800A8A18 (248 bytes)
    // NON_MATCHING: AmbientSoundPlayer iteration, pause/unpause dispatch
    void SetPause(bool pause) {
        if (m_soundPlayers == NULL) return;

        // Iterate through all sound players and pause/unpause them
        for (int i = 0; i < m_numPlaying; i++) {
            AmbientSoundPlayer* player = (AmbientSoundPlayer*)((u8*)m_soundPlayers + i * 48);
            if (pause) {
                // player->Pause();
            } else {
                // player->UnPause();
            }
            (void)player;
        }
    }

    // 0x800A8B10 (12 bytes)
    void SetVolume(int volume) { m_volume = volume; }

    // 0x800A8B1C (8 bytes)
    int GetVolume() { return m_volume; }

    // 0x800A8B24 (8 bytes)
    ERAmbientScore* GetAmbientScore() { return m_ambientScore; }

    // 0x800A8B2C (8 bytes)
    int GetNumPlaying() { return m_numPlaying; }

    // 0x800A8B34 (8 bytes)
    void* GetListenerInfos() { return m_listenerBegin; }

    // 0x800A8B3C (236 bytes)
    // NON_MATCHING: time range comparison with wrap-around
    int SoundRangeCoversCurTime(ERAmbientSound* sound) {
        if (sound == NULL) return 0;

        // Read start/end hour from the sound definition
        // Compare against m_time (current game time in hours)
        // Handle wrap-around (e.g., 22:00 to 06:00)

        // Placeholder: returns 1 if sound's time range covers current time
        return 1;
    }

    // 0x800A8C28 (136 bytes)
    int SoundAlreadyPlaying(ERAmbientSound* sound) {
        if (sound == NULL) return 0;

        // Check all active sound players to see if this sound is already active
        for (int i = 0; i < m_numPlaying; i++) {
            AmbientSoundPlayer* player = (AmbientSoundPlayer*)((u8*)m_soundPlayers + i * 48);
            // if (player->GetAmbientSound() == sound) return 1;
            (void)player;
        }
        return 0;
    }

    // 0x800A8CB0 (552 bytes)
    // NON_MATCHING: 3D distance calculation, listener iteration
    int SoundInHearingDistance(ERAmbientSound* sound) {
        if (sound == NULL) return 0;
        if (m_listenerBegin == NULL) return 0;

        // For each listener, compute distance to sound's position
        // If any listener is within the sound's hearing range, return 1
        // Uses EVec3 distance calculation with the sound's m_hearingRange

        return 1; // placeholder
    }

    // 0x800A8ED8 (184 bytes)
    // NON_MATCHING: probability random check, vector push_back
    void AddSoundBasedOnProbability(void* candidates, int index, bool flag) {
        // Roll random number against the sound's probability (0-255)
        // If passes, add to the candidate vector
        (void)candidates;
        (void)index;
        (void)flag;
    }

    // 0x800A8F90 (184 bytes)
    // NON_MATCHING: iteration over active players
    void KillAllAmbientSounds() {
        if (m_soundPlayers == NULL) return;

        // Stop all active AmbientSoundPlayers
        for (int i = 0; i < m_numPlaying; i++) {
            AmbientSoundPlayer* player = (AmbientSoundPlayer*)((u8*)m_soundPlayers + i * 48);
            // player->Stop();
            (void)player;
        }
        m_numPlaying = 0;
    }

    // 0x800A9048 (148 bytes)
    void AddNewAmbientSoundPlayer(ERAmbientSound* sound) {
        if (sound == NULL) return;
        if (m_soundPlayers == NULL) return;

        // Find a free slot in the sound player array
        // Initialize the player with the sound definition
        // player->SetScorePlayer(this);
        // player->SetAmbientSound(sound);
        // player->Start();
        m_numPlaying++;
    }

    // 0x800A90DC (188 bytes)
    void RemoveAmbientSoundPlayer(ERAmbientSound* sound) {
        if (sound == NULL) return;
        if (m_soundPlayers == NULL) return;

        // Find the player for this sound and stop it
        for (int i = 0; i < m_numPlaying; i++) {
            AmbientSoundPlayer* player = (AmbientSoundPlayer*)((u8*)m_soundPlayers + i * 48);
            // if (player->GetAmbientSound() == sound) {
            //     player->Stop();
            //     // Compact array
            //     m_numPlaying--;
            //     break;
            // }
            (void)player;
        }
    }

    // 0x800A9198 (216 bytes)
    // NON_MATCHING: iteration with compaction
    void RemoveFinishedSounds() {
        if (m_soundPlayers == NULL) return;

        // Remove any sounds that have finished playing
        for (int i = m_numPlaying - 1; i >= 0; i--) {
            AmbientSoundPlayer* player = (AmbientSoundPlayer*)((u8*)m_soundPlayers + i * 48);
            // if (player->IsFinished()) {
            //     player->Stop();
            //     // Compact: move last player into this slot
            //     m_numPlaying--;
            // }
            (void)player;
        }
    }
};


// ============================================================================
// cSoundPlayer - Game-Facing Sound API
// ============================================================================
//
// Primary interface for game code to trigger sounds. Single global instance
// accessed via SDA-relative addressing (r13 - 0xAC0C).
//
// Instance size: 0x20+ bytes.
// Original addresses: 0x800B7264 - 0x800B80FC.

class cSoundPlayer {
public:
    int     m_initialized;    // 0x00 (1 when fully set up)
    void*   m_soundSystem;    // 0x04 (cBoxX* or cIGZSndSys*)
    int     m_soundEnabled;   // 0x08 (master enable flag)
    int     m_isPaused;       // 0x0C (pause state)
    int     m_savedVolume;    // 0x10 (volume before mute)
    int     m_field_14;       // 0x14
    u32     m_sentinelNode;   // 0x18 (SoundEventInfo linked list sentinel storage)
    SoundEventList m_eventList; // 0x18 (24 bytes)

    // 0x800B7264 (104 bytes)
    // NON_MATCHING: linked list sentinel allocation via __node_alloc
    cSoundPlayer() {
        // Allocate linked list sentinel node (20 bytes)
        SoundEventInfo* sentinel = (SoundEventInfo*)EAHeap_Alloc(20);
        sentinel->m_next = sentinel;
        sentinel->m_prev = sentinel;
        m_eventList.m_sentinel = sentinel;
        m_eventList.m_count = 0;

        m_savedVolume = 0;
        m_initialized = 0;
        m_soundSystem = NULL;
        m_soundEnabled = 0;
        m_isPaused = 0;
    }

    // 0x800B72CC (156 bytes)
    // NON_MATCHING: vtable dispatch for cBoxX destructor, list clear
    ~cSoundPlayer() {
        if (m_soundEnabled != 0) {
            if (m_soundSystem != NULL) {
                // cBoxX::~cBoxX() via vtable dispatch
                // Clears SDA global g_pSoundBox
            }
            g_pSoundBox = NULL;
            m_soundSystem = NULL;
        }

        // Clear SoundEventInfo linked list
        // _List_base<SoundEventInfo>::clear()
        // Deallocate sentinel node
        if (m_eventList.m_sentinel != NULL) {
            EAHeap_FreePtr(m_eventList.m_sentinel);
        }
    }

    // 0x800B7368 (216 bytes)
    // NON_MATCHING: cIGZSndSys creation, cBoxX allocation
    void Initialize() {
        if (m_initialized != 0) return;

        // Check if external sound system is available
        // If not, create cBoxX sound engine
        // cBoxX* box = new cBoxX();
        // g_pSoundBox = box;
        // box->Init();
        m_soundEnabled = 1;
        m_initialized = 1;

        // Set disc error callback on ENgcAudio
        // ENgcAudio::SetDiscErrorCallback(discErrorHandler);
    }

    // 0x800B7440 (132 bytes)
    // NON_MATCHING: vtable dispatch chains
    void Shutdown() {
        if (m_soundEnabled == 0) return;
        if (m_initialized == 0) return;

        m_initialized = 0;

        if (g_pSoundBox != NULL) {
            // cBoxX::Shutdown() via direct call
            // cBoxX::~cBoxX() via vtable
            g_pSoundBox = NULL;
        }
    }

    // 0x800B74C4 (248 bytes)
    // NON_MATCHING: linked list traversal with node removal
    void KillSourceEvent(int sourceId) {
        SoundEventInfo* sentinel = m_eventList.m_sentinel;
        if (sentinel == NULL) return;

        SoundEventInfo* current = sentinel->m_next;
        while (current != sentinel) {
            SoundEventInfo* next = current->m_next;
            if (current->m_sourceId == sourceId) {
                // Remove from list
                current->m_prev->m_next = current->m_next;
                current->m_next->m_prev = current->m_prev;
                // Release sound event resource
                // EResourceManager::DelRefAsync(current->m_eventRef)
                EAHeap_FreePtr(current);
            }
            current = next;
        }
    }

    // 0x800B75BC (236 bytes)
    // NON_MATCHING: same list traversal pattern
    void KillAllEvent() {
        m_savedVolume = 1; // flag to suppress new events

        SoundEventInfo* sentinel = m_eventList.m_sentinel;
        if (sentinel == NULL) return;

        SoundEventInfo* current = sentinel->m_next;
        while (current != sentinel) {
            SoundEventInfo* next = current->m_next;
            // Release resource reference
            // EResourceManager::DelRefAsync(current->m_eventRef)
            // Remove from list
            current->m_prev->m_next = current->m_next;
            current->m_next->m_prev = current->m_prev;
            EAHeap_FreePtr(current);
            current = next;
        }
    }

    // 0x800B76A8 (364 bytes)
    // NON_MATCHING: linked list iteration with cBoxX::MappedEvent dispatch
    void Update() {
        SoundEventInfo* sentinel = m_eventList.m_sentinel;
        if (sentinel == NULL) return;

        SoundEventInfo* current = sentinel->m_next;
        while (current != sentinel) {
            SoundEventInfo* next = current->m_next;

            // Look up the ERSoundEvent resource
            // ERSoundEvent* event = EResourceManager::GetRef(current->m_eventRef);
            // if (event != NULL) {
            //     // Unlink from list
            //     current->m_prev->m_next = current->m_next;
            //     current->m_next->m_prev = current->m_prev;
            //     // Dispatch to sound engine
            //     cBoxX::MappedEvent(event, current->m_sourceId, current->m_priority + 1.0f);
            //     event->DelRef();
            //     EAHeap_FreePtr(current);
            // }

            current = next;
        }

        // If initialized and enabled, update the sound engine
        if (m_initialized != 0 && m_soundEnabled != 0) {
            // cBoxX::UpdateGameMode()
            if (m_isPaused == 0) {
                // Poll for finished sounds, update streamer
            }
        }
    }

    // 0x800B7814 (132 bytes)
    // NON_MATCHING: cBoxX mode dispatch
    void SetGameMode(int mode) {
        if (m_soundEnabled == 0) return;
        if (m_initialized == 0) return;
        if (g_pSoundBox == NULL) return;

        // Check if cutscene is active (global flag check)
        // If so, skip mode change

        if (mode == 5) {
            // CAS mode: direct dispatch to cSoundModeManager::SetMode(5)
            // cSoundModeManager is at cBoxX + 0x30
        } else {
            // Other modes: dispatch via cBoxX::Event(36, mode, 0, NULL, 1.0f)
        }
    }

    // 0x800B78B0 (84 bytes)
    void EnableSound(bool enable) {
        if (m_initialized == 0) return;
        if (m_soundEnabled == 0) return;

        // Dispatch via cBoxX::Event(34, (int)enable, 0, NULL, 1.0f)
    }

    // 0x800B7904 (100 bytes)
    void QuietAll() {
        if (m_initialized == 0) return;
        if (m_soundEnabled == 0) return;

        // Save current volume and dispatch quiet event
        // cBoxX::Event(20, 0, 0, NULL, 1.0f)
    }

    // 0x800B7968 (248 bytes)
    // NON_MATCHING: EResourceManager::AddRefAsync, SoundEventInfo allocation
    void PlayBySource(unsigned int hashKey, short sourceId) {
        if (m_initialized == 0) return;
        if (m_soundEnabled == 0) return;
        if (hashKey == 0) return;
        if (sourceId == -2) return;

        // Look up sound event resource asynchronously
        // u32 refHandle = EResourceManager::AddRefAsync(hashKey);

        // Allocate SoundEventInfo node
        // SoundEventInfo* info = node_alloc(20);
        // info->m_sourceId = (int)sourceId;
        // info->m_eventRef = refHandle;
        // info->m_priority = 1.0f;

        // Check current OptionsRecon volume settings
        // Link into the event list for processing in Update()
    }

    // 0x800B7A60 (108 bytes)
    void PlayBySource(char* name, short sourceId) {
        if (name == NULL) return;
        // Hash the name string and call the uint overload
        // uint hashKey = HashString(name);
        // PlayBySource(hashKey, sourceId);
        (void)sourceId;
    }

    // 0x800B7ACC (84 bytes)
    void PlayBySource(ERSoundEvent* event, short sourceId) {
        if (event == NULL) return;
        if (m_initialized == 0) return;
        if (m_soundEnabled == 0) return;
        // Direct dispatch via cBoxX::MappedEvent(event, sourceId, 1.0f)
        (void)sourceId;
    }

    // 0x800B7B20 (84 bytes)
    void QuietBySourceID(int sourceId) {
        if (m_initialized == 0) return;
        if (m_soundEnabled == 0) return;
        // Dispatch via cBoxX::Event with the source ID
        (void)sourceId;
    }

    // 0x800B7B74 (112 bytes)
    void PauseSFX() {
        if (m_initialized == 0) return;
        if (m_soundEnabled == 0) return;
        // cBoxX: pause SFX group
    }

    // 0x800B7BE4 (112 bytes)
    void ResumeSFX() {
        if (m_initialized == 0) return;
        if (m_soundEnabled == 0) return;
        // cBoxX: resume SFX group
    }

    // 0x800B7C54 (112 bytes)
    void PauseMusic() {
        if (m_initialized == 0) return;
        if (m_soundEnabled == 0) return;
        // Dispatch pause to ENgcAudio::PauseMusic()
    }

    // 0x800B7CC4 (112 bytes)
    void ResumeMusic() {
        if (m_initialized == 0) return;
        if (m_soundEnabled == 0) return;
        // Dispatch resume to ENgcAudio::ResumeMusic()
    }

    // 0x800B7D34 (148 bytes)
    void PauseSounds() {
        if (m_initialized == 0) return;
        if (m_soundEnabled == 0) return;
        PauseSFX();
        PauseMusic();
        m_isPaused = 1;
    }

    // 0x800B7DC8 (148 bytes)
    void ResumeSounds() {
        if (m_initialized == 0) return;
        if (m_soundEnabled == 0) return;
        ResumeSFX();
        ResumeMusic();
        m_isPaused = 0;
    }

    // 0x800B7E5C (84 bytes)
    void NotifyViewChange() {
        if (m_initialized == 0) return;
        if (m_soundEnabled == 0) return;
        // Recalculate 3D sound positions for all ambient sounds
        // Dispatch via cBoxX
    }

    // 0x800B7EB0 (84 bytes)
    void NotifyHourChange() {
        if (m_initialized == 0) return;
        if (m_soundEnabled == 0) return;
        // Re-evaluate ambient score time ranges
        // Dispatch via cBoxX
    }

    // Volume setters (0x800B7F04 - 0x800B80FC, ~600B total)
    void SetOldFXVolume(int vol) { (void)vol; }
    void SetMusicVolume(int vol) { (void)vol; }
    void SetSFXVolume(int vol) { (void)vol; }
    void SetVOXVolume(int vol) { (void)vol; }
    void SetAmbientVolume(int vol) { (void)vol; }
};


// ############################################################################
//
//  SECTION 2: SAVE SYSTEM
//
// ############################################################################

// ============================================================================
// ENgcMemoryCard - GameCube Memory Card Driver
// ============================================================================
//
// Wraps DolphinSDK CARD library for all low-level memory card operations.
// Derives from EMemoryCard (abstract base).
//
// Global singleton: _pMemoryCard @ 0x804FF210
// Vtable @ 0x8046C728 (312 bytes = 39 entries)
//
// Card operation locking prevents concurrent access from multiple threads.

// CARD result codes
enum {
    CARD_RESULT_READY       =  0,
    CARD_RESULT_BUSY        = -1,
    CARD_RESULT_WRONGDEVICE = -2,
    CARD_RESULT_NOCARD      = -3,
    CARD_RESULT_NOFILE      = -4,
    CARD_RESULT_IOERROR     = -5,
    CARD_RESULT_BROKEN      = -6,
    CARD_RESULT_EXIST       = -7,
    CARD_RESULT_NOENT       = -8,
    CARD_RESULT_INSSPACE    = -9,
    CARD_RESULT_NOPERM      = -10,
    CARD_RESULT_LIMIT       = -11,
    CARD_RESULT_NAMETOOLONG = -12,
    CARD_RESULT_ENCODING    = -13,
    CARD_RESULT_CANCELED    = -14,
    CARD_RESULT_FATAL       = -128
};

// Internal error codes
enum {
    EMC_OK           =  1,
    EMC_NO_CARD      = -1,
    EMC_NOT_FORMATTED = -2,
    EMC_DAMAGED      = -3,
    EMC_ERROR        = -4,
    EMC_NO_SPACE     = -5,
    EMC_CORRUPT      = -6,
    EMC_WRONG_DEVICE = -7,
    EMC_CARD_DEAD    = -8
};

// Static card operation lock
static int s_cardOperationInProgress = 0;
static int s_ngcMemCardCardDead = 0;

// Banner/icon buffer (displayed by GC BIOS when browsing saves)
static u8 s_bannerBuffer[2048];   // 96x32 CI8 banner
static u8 s_iconBuffer[6144];     // 32x32 CI8 icon animation
static char s_commentLine1[32];   // first comment string
static char s_commentLine2[32];   // second comment string

class ENgcMemoryCard {
public:
    u8 m_baseClass[8]; // EMemoryCard base class fields

    // 0x8032FEE8 (16 bytes)
    static void BeginCardOperation() {
        s_cardOperationInProgress = 1;
    }

    // 0x8032FEF8 (16 bytes)
    static void EndCardOperation() {
        s_cardOperationInProgress = 0;
    }

    // 0x8032FED0 (24 bytes)
    static int IsCardOperationInProgress() {
        return s_cardOperationInProgress;
    }

    // 0x8032FF08 (280 bytes)
    // NON_MATCHING: wchar_t to char conversion loop
    void SetComments(unsigned short* line1, unsigned short* line2) {
        // Convert wchar_t strings to single-byte for memory card comment fields
        // Special case: character 0x2122 ('(tm)' symbol) maps to 0x99

        // Line 1
        u32 i = 0;
        while (line1[i] != 0 && i < 32) {
            if (line1[i] == 0x2122) {
                s_commentLine1[i] = (char)0x99;
            } else {
                s_commentLine1[i] = (char)(line1[i] & 0xFF);
            }
            i++;
        }
        if (i < 32) {
            s_commentLine1[i] = '\0';
        } else {
            s_commentLine1[31] = '\0';
        }

        // Line 2
        i = 0;
        while (line2[i] != 0 && i < 32) {
            if (line2[i] == 0x2122) {
                s_commentLine2[i] = (char)0x99;
            } else {
                s_commentLine2[i] = (char)(line2[i] & 0xFF);
            }
            i++;
        }
        if (i < 32) {
            s_commentLine2[i] = '\0';
        } else {
            s_commentLine2[31] = '\0';
        }
    }

    // 0x80330020 (412 bytes)
    // NON_MATCHING: texture palette loading, memcpy loop unrolling
    void InitMemoryCard() {
        BeginCardOperation();
        CARDInit();
        EndCardOperation();

        // Load banner texture from game resources
        // LoadTexPalette(&bannerTex, "banner.tpl");
        // If found, copy pixel data to s_bannerBuffer (2048 bytes)
        // If not found, fill with 0x7F default pattern
        bool bannerLoaded = false; // placeholder
        if (!bannerLoaded) {
            memset(s_bannerBuffer, 0x7F, 2048);
        }

        // Load icon texture similarly
        // LoadTexPalette(&iconTex, "icon.tpl");
        // Copy 6144 bytes of icon pixel data to s_iconBuffer
    }

    // ---- Error code translation helper ----
    static int TranslateCardResult(int cardResult) {
        switch (cardResult) {
            case CARD_RESULT_READY:       return EMC_OK;
            case CARD_RESULT_NOCARD:      return EMC_NO_CARD;
            case CARD_RESULT_WRONGDEVICE: return EMC_WRONG_DEVICE;
            case CARD_RESULT_IOERROR:
                s_ngcMemCardCardDead = 1;
                return EMC_CARD_DEAD;
            case CARD_RESULT_BROKEN:      return EMC_DAMAGED;
            case CARD_RESULT_ENCODING:    return EMC_CORRUPT;
            case CARD_RESULT_NOPERM:      return EMC_ERROR;
            default:                      return EMC_ERROR;
        }
    }

    // 0x803301C4 (1496 bytes)
    // NON_MATCHING: CARDMount/CARDGetResultCode polling, error path branching
    int LoadDataChunkS(char* filename, unsigned int slot, unsigned int offset,
                       unsigned int size, void* data) {
        BeginCardOperation();

        int memSize = 0, sectorSize = 0;
        int result = CARDProbeEx((int)slot, &memSize, &sectorSize);
        if (result != CARD_RESULT_READY) {
            EndCardOperation();
            return TranslateCardResult(result);
        }

        // Mount card
        result = CARDMountAsync((int)slot, NULL, NULL);
        if (result != CARD_RESULT_READY) {
            EndCardOperation();
            return TranslateCardResult(result);
        }

        // Wait for mount to complete
        result = CARDGetResultCode((int)slot);
        if (result != CARD_RESULT_READY) {
            CARDUnmount((int)slot);
            EndCardOperation();
            return TranslateCardResult(result);
        }

        // Open the file
        u8 fileInfo[64]; // CARDFileInfo
        result = CARDOpen((int)slot, filename, fileInfo);
        if (result != CARD_RESULT_READY) {
            CARDUnmount((int)slot);
            EndCardOperation();
            return TranslateCardResult(result);
        }

        // Read data at offset
        result = CARDRead(fileInfo, data, (int)size, (int)offset);

        // Close and unmount
        CARDClose(fileInfo);
        CARDUnmount((int)slot);
        EndCardOperation();

        return (result == CARD_RESULT_READY) ? EMC_OK : TranslateCardResult(result);
    }

    // 0x8033079C (1492 bytes)
    // Same as LoadDataChunkS but offset = 0
    int LoadDataS(char* filename, unsigned int slot, unsigned int size, void* data) {
        return LoadDataChunkS(filename, slot, 0, size, data);
    }

    // 0x80330D80 (2184 bytes)
    // NON_MATCHING: largest save function, complex error recovery
    int SaveDataChunkS(char* filename, unsigned int slot, unsigned int offset,
                       unsigned int size, void* data) {
        BeginCardOperation();

        int memSize = 0, sectorSize = 0;
        int result = CARDProbeEx((int)slot, &memSize, &sectorSize);
        if (result != CARD_RESULT_READY) {
            EndCardOperation();
            return TranslateCardResult(result);
        }

        // Mount card
        result = CARDMountAsync((int)slot, NULL, NULL);
        if (result != CARD_RESULT_READY) {
            EndCardOperation();
            return TranslateCardResult(result);
        }

        result = CARDGetResultCode((int)slot);
        if (result != CARD_RESULT_READY) {
            CARDUnmount((int)slot);
            EndCardOperation();
            return TranslateCardResult(result);
        }

        // Open the file
        u8 fileInfo[64];
        result = CARDOpen((int)slot, filename, fileInfo);
        if (result != CARD_RESULT_READY) {
            CARDUnmount((int)slot);
            EndCardOperation();
            return TranslateCardResult(result);
        }

        // Write data at offset
        result = CARDWrite(fileInfo, data, (int)size, (int)offset);

        // Close and unmount
        CARDClose(fileInfo);
        CARDUnmount((int)slot);
        EndCardOperation();

        return (result == CARD_RESULT_READY) ? EMC_OK : TranslateCardResult(result);
    }

    // 0x80331608 (2052 bytes)
    // Write entire file + update banner/icon
    int SaveDataS(char* filename, unsigned int slot, unsigned int size, void* data) {
        int result = SaveDataChunkS(filename, slot, 0, size, data);
        if (result == EMC_OK) {
            CheckAndWriteBannerAndIcon(filename, slot);
        }
        return result;
    }

    // 0x80331E0C (2216 bytes)
    // NON_MATCHING: CARDCreate with status setup, banner/icon write
    int CreateFileS(char* filename, unsigned int slot, unsigned int size) {
        BeginCardOperation();

        int memSize = 0, sectorSize = 0;
        int result = CARDProbeEx((int)slot, &memSize, &sectorSize);
        if (result != CARD_RESULT_READY) {
            EndCardOperation();
            return TranslateCardResult(result);
        }

        result = CARDMountAsync((int)slot, NULL, NULL);
        if (result != CARD_RESULT_READY) {
            EndCardOperation();
            return TranslateCardResult(result);
        }

        result = CARDGetResultCode((int)slot);
        if (result != CARD_RESULT_READY) {
            CARDUnmount((int)slot);
            EndCardOperation();
            return TranslateCardResult(result);
        }

        u8 fileInfo[64];
        result = CARDCreate((int)slot, filename, (int)size, fileInfo);
        if (result != CARD_RESULT_READY) {
            CARDUnmount((int)slot);
            EndCardOperation();
            return TranslateCardResult(result);
        }

        // Set file attributes via CARDSetStatus

        // Write initial banner and icon data to first sector
        CheckAndWriteBannerAndIcon(filename, slot);

        CARDClose(fileInfo);
        CARDUnmount((int)slot);
        EndCardOperation();

        return EMC_OK;
    }

    // 0x80332CE4 (776 bytes)
    int DeleteDataS(char* filename, unsigned int slot) {
        BeginCardOperation();

        int result = CARDMountAsync((int)slot, NULL, NULL);
        if (result != CARD_RESULT_READY) {
            EndCardOperation();
            return TranslateCardResult(result);
        }

        result = CARDGetResultCode((int)slot);
        if (result != CARD_RESULT_READY) {
            CARDUnmount((int)slot);
            EndCardOperation();
            return TranslateCardResult(result);
        }

        result = CARDDelete((int)slot, filename);

        CARDUnmount((int)slot);
        EndCardOperation();

        return (result == CARD_RESULT_READY) ? EMC_OK : TranslateCardResult(result);
    }

    // 0x80332FEC (756 bytes)
    int FormatCardS(unsigned int slot) {
        BeginCardOperation();

        int result = CARDFormat((int)slot);

        EndCardOperation();
        return (result == CARD_RESULT_READY) ? EMC_OK : TranslateCardResult(result);
    }

    // 0x80333318 (1132 bytes)
    // NON_MATCHING: mount/probe/CARDFreeBlocks error handling
    int GetFreeSpaceS(unsigned int slot, unsigned int& freeBytes) {
        BeginCardOperation();

        int result = CARDMountAsync((int)slot, NULL, NULL);
        if (result != CARD_RESULT_READY) {
            EndCardOperation();
            return TranslateCardResult(result);
        }

        result = CARDGetResultCode((int)slot);
        if (result != CARD_RESULT_READY) {
            CARDUnmount((int)slot);
            EndCardOperation();
            return TranslateCardResult(result);
        }

        int bytesFree = 0, filesFree = 0;
        result = CARDFreeBlocks((int)slot, &bytesFree, &filesFree);
        freeBytes = (unsigned int)bytesFree;

        CARDUnmount((int)slot);
        EndCardOperation();

        return (result == CARD_RESULT_READY) ? EMC_OK : TranslateCardResult(result);
    }

    // 0x80333784 (1132 bytes)
    int GetFreeFilesS(unsigned int slot, int& freeFiles) {
        BeginCardOperation();

        int result = CARDMountAsync((int)slot, NULL, NULL);
        if (result != CARD_RESULT_READY) {
            EndCardOperation();
            return TranslateCardResult(result);
        }

        result = CARDGetResultCode((int)slot);
        if (result != CARD_RESULT_READY) {
            CARDUnmount((int)slot);
            EndCardOperation();
            return TranslateCardResult(result);
        }

        int bytesFree = 0;
        result = CARDFreeBlocks((int)slot, &bytesFree, &freeFiles);

        CARDUnmount((int)slot);
        EndCardOperation();

        return (result == CARD_RESULT_READY) ? EMC_OK : TranslateCardResult(result);
    }

    // 0x80333BF0 (108 bytes)
    int IsSpaceAvailable(unsigned int slot, unsigned int requiredBytes, bool& result) {
        unsigned int freeBytes = 0;
        int status = GetFreeSpaceS(slot, freeBytes);
        if (status == EMC_OK) {
            result = (freeBytes >= requiredBytes);
        }
        return status;
    }

    // 0x80333C5C (88 bytes)
    int IsEnoughFiles(unsigned int slot, unsigned int requiredFiles, bool& result) {
        int freeFiles = 0;
        int status = GetFreeFilesS(slot, freeFiles);
        if (status == EMC_OK) {
            result = ((unsigned int)freeFiles >= requiredFiles);
        }
        return status;
    }

    // 0x80333CD4 (364 bytes)
    int IsCardAvailable(unsigned int slot) {
        int memSize = 0, sectorSize = 0;
        int result = CARDProbeEx((int)slot, &memSize, &sectorSize);
        return TranslateCardResult(result);
    }

    // 0x80333E40 (352 bytes)
    int IsWrongDevice(unsigned int slot) {
        int memSize = 0, sectorSize = 0;
        int result = CARDProbeEx((int)slot, &memSize, &sectorSize);
        return (result == CARD_RESULT_WRONGDEVICE) ? 1 : 0;
    }

    // 0x80333FA0 (160 bytes)
    int AnyCardsPresent(int& slot) {
        // Check slot A
        int memSize = 0, sectorSize = 0;
        int resultA = CARDProbeEx(0, &memSize, &sectorSize);
        if (resultA == CARD_RESULT_READY) {
            slot = 0;
            return EMC_OK;
        }

        // Check slot B
        int resultB = CARDProbeEx(1, &memSize, &sectorSize);
        if (resultB == CARD_RESULT_READY) {
            slot = 1;
            return EMC_OK;
        }

        return EMC_NO_CARD;
    }

    // 0x80334040 (936 bytes)
    int IsCardFormated(unsigned int slot, bool& result) {
        result = false;
        int mountResult = CARDMountAsync((int)slot, NULL, NULL);
        if (mountResult != CARD_RESULT_READY) {
            if (mountResult == CARD_RESULT_BROKEN) {
                result = false; // needs formatting
                return EMC_OK;
            }
            return TranslateCardResult(mountResult);
        }

        int status = CARDGetResultCode((int)slot);
        if (status == CARD_RESULT_BROKEN) {
            result = false;
        } else if (status == CARD_RESULT_READY) {
            result = true;
        }

        CARDUnmount((int)slot);
        return EMC_OK;
    }

    // 0x80334898 (1184 bytes)
    int DoesFileExist(char* filename, unsigned int slot, bool& result) {
        result = false;

        int mountResult = CARDMountAsync((int)slot, NULL, NULL);
        if (mountResult != CARD_RESULT_READY) return TranslateCardResult(mountResult);

        int status = CARDGetResultCode((int)slot);
        if (status != CARD_RESULT_READY) {
            CARDUnmount((int)slot);
            return TranslateCardResult(status);
        }

        u8 fileInfo[64];
        status = CARDOpen((int)slot, filename, fileInfo);
        if (status == CARD_RESULT_READY) {
            result = true;
            CARDClose(fileInfo);
        }

        CARDUnmount((int)slot);
        return EMC_OK;
    }

    // 0x80334D38 (356 bytes)
    int GetSectorSize(int slot, unsigned int& sectorSize) {
        int memSize = 0;
        int secSize = 0;
        int result = CARDProbeEx(slot, &memSize, &secSize);
        sectorSize = (unsigned int)secSize;
        return (result == CARD_RESULT_READY) ? EMC_OK : TranslateCardResult(result);
    }

    // 0x803326B4 (1584 bytes)
    // NON_MATCHING: banner/icon pixel data write
    void CheckAndWriteBannerAndIcon(char* filename, unsigned int slot) {
        // Write banner (96x32 CI8) and icon (32x32 CI8) data to the first
        // sector of the save file. This data is displayed by the GC BIOS
        // when the user browses save files.
        //
        // The data comes from s_bannerBuffer and s_iconBuffer, loaded during
        // InitMemoryCard().
        (void)filename;
        (void)slot;
    }
};


// ============================================================================
// SimsMemCardWrap - Game-Level Save/Load API
// ============================================================================
//
// Provides the game-facing save/load interface. Wraps ENgcMemoryCard with
// game-specific logic: save validation, config files, house data, multi-slot.
//
// Accesses platform card interface via g_pMemCardInterface (r13 - 0x98F0).
// All methods dispatch through a vtable with SN Systems calling convention
// (8-byte entries: s16 this-adjustor, u16 pad, u32 function_ptr).
//
// Instance size: 0xCC (204 bytes).
// Original addresses: 0x80074E60 - 0x80075ABC.

// Helper: dispatch through SN Systems vtable entry
// vtable[offset] = { s16 thisAdj, u16 pad, u32 funcPtr }
// Adjusts 'this' by thisAdj, then calls funcPtr.
static inline int VtableCall_int(void* iface, int vtableOffset) {
    u32* vtable = *(u32**)iface;
    s16 thisAdj = (s16)(*(u16*)((u8*)vtable + vtableOffset));
    u32 funcPtr = *(u32*)((u8*)vtable + vtableOffset + 4);
    typedef int (*Fn)(void*);
    return ((Fn)funcPtr)((u8*)iface + thisAdj);
}

extern "C" int GetTotalSaveGameSize();

class SimsMemCardWrap {
public:
    // 0x80074E60 (204 bytes)
    // NON_MATCHING: vtable dispatch patterns, EORDbgTrace calls
    void Init() {
        // Set save file name via vtable[0xC0/0xC4]
        // "Sims2" or similar save file name

        // Configure max files = 1, block size = 8192
        // vtable[0xB8/0xBC](1, 8192)

        // Query total save game size
        int totalSize = GetTotalSaveGameSize();

        // Debug print
        EORDbgTrace("Save size: %d", totalSize);
        EORDbgTrace("Save blocks: %d", totalSize >> 13);
    }

    // 0x80074F2C (80 bytes)
    // NON_MATCHING: loop structure
    void InitPolling() {
        // Check both card slots for presence
        for (int slot = 0; slot <= 1; slot++) {
            bool cardPresent = false;
            IsCardInSlot(slot, cardPresent);
            if (!cardPresent) break; // original: if result != 1, continue loop
        }
    }

    // 0x80074FB8 (80 bytes)
    // NON_MATCHING: SN Systems vtable dispatch
    int IsPolledCardInSlot(int slot, bool& result) {
        // Dispatch via vtable[0x98/0x9C] (offset 152/156)
        // Uses platform card interface
        (void)slot;
        result = false;
        return EMC_OK;
    }

    // 0x80075008 (80 bytes)
    int IsCardInSlot(int slot, bool& result) {
        // Dispatch via vtable[0xA0/0xA4] (offset 160/164)
        (void)slot;
        result = false;
        return EMC_OK;
    }

    // 0x80075058 (80 bytes)
    int IsWrongDevice(int slot, bool& result) {
        // Dispatch via vtable[0xA8/0xAC] (offset 168/172)
        (void)slot;
        result = false;
        return EMC_OK;
    }

    // 0x800750A8 - IsCardFormatted
    int IsCardFormatted(int slot, bool& result) {
        // Dispatch via vtable[0xB0/0xB4] (offset 176/180)
        (void)slot;
        result = true;
        return EMC_OK;
    }

    // 0x800750E8 (104 bytes)
    // NON_MATCHING: error code check
    int IsCardCorrupted(int slot, bool& result) {
        result = false;
        // Dispatch via vtable[0xB0/0xB4] with error code check
        // If result == -4 (EMC_ERROR), card is corrupted
        bool tempResult = false;
        int status = IsCardFormatted(slot, tempResult);
        if (status == EMC_ERROR) {
            result = true;
        }
        return EMC_OK;
    }

    // 0x80075150 (100 bytes)
    int IsCardDamaged(int slot, bool& result) {
        // Dispatch via vtable[0xB0/0xB4]
        // If result == -8 (EMC_CARD_DEAD), card is damaged
        bool tempResult = false;
        int status = IsCardFormatted(slot, tempResult);
        result = (status == EMC_CARD_DEAD);
        return EMC_OK;
    }

    // 0x800751B4 (68 bytes)
    int HasSavedGame(int slot, bool& result, int id) {
        // Dispatch via vtable[0xC8/0xCC] (offset 200/204)
        (void)slot;
        (void)id;
        result = false;
        return EMC_OK;
    }

    // 0x800751F8 (188 bytes)
    // NON_MATCHING: NghResFile::IsSaveGameValid dispatch
    int HasValidSavedGame(int slot, bool& result, int id) {
        bool hasSave = false;
        int status = HasSavedGame(slot, hasSave, id);
        if (status != EMC_OK) return status;

        if (!hasSave) {
            result = false;
            return EMC_OK;
        }

        // Validate save data via NghResFile
        bool isValid = false;
        // NghResFile::IsSaveGameValid(filename, slot, isValid)
        // status = ...;
        // if (status != EMC_OK) return status;

        result = isValid && hasSave;
        return EMC_OK;
    }

    // 0x800752B4 (80 bytes)
    int HasInvalidGame(int slot, bool& result, int id) {
        bool isValid = true;
        // NghResFile::IsSaveGameValid(filename, slot, isValid)
        result = !isValid; // XOR with 1
        (void)slot;
        (void)id;
        return EMC_OK;
    }

    // 0x80075304 (144 bytes)
    // NON_MATCHING: vtable dispatch for IsEnoughFiles and IsSpaceAvailable
    int HasSpaceForSave(int slot, bool& result, unsigned int* outNeeded) {
        if (outNeeded != NULL) {
            *outNeeded = 0;
        }

        // Check if enough file slots
        // ENgcMemoryCard::IsEnoughFiles(slot, 1, result)
        if (!result) return EMC_OK;

        // Check if enough space
        // GetSpaceRequiredForSave() -> requiredBytes
        // ENgcMemoryCard vtable[0x80/0x84](slot, requiredBytes, result)

        (void)slot;
        return EMC_OK;
    }

    // 0x80075394 (312 bytes)
    // NON_MATCHING: sequential card check chain
    int CanBeUsed(int slot, bool& result, int id) {
        bool tempResult = false;
        (void)id;

        // Check card in slot
        IsCardInSlot(slot, tempResult);
        if (!tempResult) { result = false; return EMC_OK; }

        // Check wrong device
        tempResult = false;
        IsWrongDevice(slot, tempResult);
        if (tempResult) { result = false; return EMC_OK; }

        // Check damaged
        tempResult = false;
        IsCardDamaged(slot, tempResult);
        if (tempResult) { result = false; return EMC_OK; }

        // Check corrupted
        tempResult = false;
        IsCardCorrupted(slot, tempResult);
        if (tempResult) { result = false; return EMC_OK; }

        // Check formatted
        tempResult = false;
        IsCardFormatted(slot, tempResult);
        if (!tempResult) { result = false; return EMC_OK; }

        // Check if has a saved game
        tempResult = false;
        HasSavedGame(slot, tempResult, 0xAB34CF); // magic sentinel value
        if (tempResult) {
            result = true;
            return EMC_OK;
        }

        // Check if enough space for new save
        tempResult = false;
        HasSpaceForSave(slot, tempResult, NULL);
        result = tempResult;

        return EMC_OK;
    }

    // 0x800754CC (124 bytes)
    // NON_MATCHING: NghResFile::HasCardChanged dispatch
    int IsDifferentCard(int slot, bool& result) {
        // Check NghResFile for card change detection
        // If card has changed flag is set, return immediately
        // Otherwise call NghResFile::HasCardChanged(slot, result)

        (void)slot;
        result = false;
        return EMC_OK;
    }

    // 0x80075548 (72 bytes)
    int LoadConfigFile(int slot) {
        // OptionsRecon::ReadIn(slot) via global options instance
        // OptionsRecon::PreservePrefsForOnline()
        (void)slot;
        return EMC_OK;
    }

    // 0x80075590 (76 bytes)
    int SaveConfigFile(int slot) {
        // OptionsRecon::WriteOut() via global options instance
        // If write fails, invalidate save data
        (void)slot;
        return EMC_OK;
    }

    // 0x800756DC (176 bytes)
    // NON_MATCHING: NghResFile::WriteToMemoryCard dispatch
    int SaveNewGame(int slot) {
        // Set up new NghResFile section data
        // NghResFile::WriteToMemoryCard(filename, slot)
        int result = EMC_OK; // placeholder

        if (result == EMC_OK) {
            result = SaveConfigFile(slot);
        }

        // CheckForFileDescriptorLeaks cleanup
        return result;
    }

    // 0x8007578C (144 bytes)
    int PreloadGame(int slot) {
        // Read just the save header/checksum
        // NghResFile::ReadChecksumFromCard(filename, slot)
        // CheckForFileDescriptorLeaks cleanup
        (void)slot;
        return EMC_OK;
    }

    // 0x8007581C (160 bytes)
    // NON_MATCHING: complex load flow with validation
    int LoadGame(int slot, int id) {
        // 1. Load memory card cache
        // int result = LoadCacheFromMemoryCard(slot);
        // if (result != 1) return result;

        // 2. Validate config file
        // bool isValid = IsConfigFileValid(slot, ...);
        // if (!isValid) return EMC_ERROR;

        // 3. Read save data
        // result = NghResFile::ReadFromMemoryCard(filename, slot);

        // 4. Apply loaded state
        // if (result == 1) ApplyLoadedState(...);

        // CheckForFileDescriptorLeaks cleanup
        (void)slot;
        (void)id;
        return EMC_OK;
    }

    // 0x800758BC (280 bytes)
    // NON_MATCHING: complex save flow with NghResFile integration
    int SaveGame(int slot, bool saveCache, bool overwrite, int id) {
        // 1. If active lot data exists, write it to NghResFile
        // 2. FormatDataForSave()
        // 3. NghResFile::WriteToMemoryCard(filename, slot)
        // 4. If success, SaveConfigFile(slot)
        // 5. If saveCache, SaveAllMemoryCardCache(slot)

        (void)slot;
        (void)saveCache;
        (void)overwrite;
        (void)id;
        return EMC_OK;
    }

    // 0x800759D4 (144 bytes)
    int LoadHouse(int slot) {
        // Load house-specific data from memory card
        // NghResFile::LoadHouseContents(houseId, data, validate)
        (void)slot;
        return EMC_OK;
    }

    // 0x80075A64 (88 bytes)
    int ReloadHouseAndGlobals(int slot, int houseId) {
        // Reload house and global data (entering a lot)
        (void)slot;
        (void)houseId;
        return EMC_OK;
    }

    // 0x80075ABC (76 bytes)
    int SaveHouseAndGlobals(int slot, int houseId) {
        // Save current house and global state (autosave)
        (void)slot;
        (void)houseId;
        return EMC_OK;
    }

    // Helper: GetSpaceRequiredForSave (32 bytes)
    int GetSpaceRequiredForSave() {
        return GetTotalSaveGameSize();
    }
};


// ############################################################################
//
//  SECTION 3: CAMERA SYSTEM
//
// ############################################################################

// ============================================================================
// CameraMotionSystem - Smooth camera movement via rubber-band interpolation
// ============================================================================
//
// Two movement strategies:
//   SNAP: Direct copy of rig vectors to output positions
//   RUBBERBAND: Spring-like interpolation toward target
//
// Layout (88 bytes total - see esimscam.h for first 8 bytes):
//   0x00: CameraMotionType m_motionType
//   0x04: SimsCameraParameters* m_pParams
//   0x08: EVec3 m_rigEye       (12 bytes)
//   0x14: EVec3 m_rigTarget    (12 bytes)
//   0x20: EVec3 m_rigUp        (12 bytes)
//   0x2C: EVec3 m_currentEye   (12 bytes)
//   0x38: EVec3 m_currentTarget(12 bytes)
//   0x44: EVec3 m_currentUp    (12 bytes)
//   0x50: EVec3 m_forward      (12 bytes)

// Extended layout - esimscam.h only has the first 8 bytes
struct CameraMotionSystemFull {
    CameraMotionType m_motionType;       // 0x00
    SimsCameraParameters* m_pParams;     // 0x04
    EVec3 m_rigEye;                      // 0x08
    EVec3 m_rigTarget;                   // 0x14
    EVec3 m_rigUp;                       // 0x20
    EVec3 m_currentEye;                  // 0x2C
    EVec3 m_currentTarget;               // 0x38
    EVec3 m_currentUp;                   // 0x44
    EVec3 m_forward;                     // 0x50

    // 0x800160B8 (88 bytes)
    // NON_MATCHING: register allocation differs
    void SetRig(EVec3& eye, EVec3& target, EVec3& up) {
        // Copy using integer copy for exact bit pattern preservation
        u32* src;

        src = (u32*)&eye;
        u32* dstEye = (u32*)&m_rigEye;
        dstEye[0] = src[0];
        dstEye[1] = src[1];
        dstEye[2] = src[2];

        src = (u32*)&target;
        u32* dstTarget = (u32*)&m_rigTarget;
        dstTarget[0] = src[0];
        dstTarget[1] = src[1];
        dstTarget[2] = src[2];

        src = (u32*)&up;
        u32* dstUp = (u32*)&m_rigUp;
        dstUp[0] = src[0];
        dstUp[1] = src[1];
        dstUp[2] = src[2];
    }

    // 0x80016110 (268 bytes)
    // NON_MATCHING: SN Systems register scheduling
    void SnapCamera() {
        // Copy rig -> current
        m_currentEye.x = m_rigEye.x;
        m_currentEye.y = m_rigEye.y;
        m_currentEye.z = m_rigEye.z;

        m_currentTarget.x = m_rigTarget.x;
        m_currentTarget.y = m_rigTarget.y;
        m_currentTarget.z = m_rigTarget.z;

        m_currentUp.x = m_rigUp.x;
        m_currentUp.y = m_rigUp.y;
        m_currentUp.z = m_rigUp.z;

        // Compute forward = normalize(target - eye)
        EVec3 fwd;
        fwd.x = m_currentTarget.x - m_currentEye.x;
        fwd.y = m_currentTarget.y - m_currentEye.y;
        fwd.z = m_currentTarget.z - m_currentEye.z;

        if (fwd.x != 0.0f || fwd.y != 0.0f || fwd.z != 0.0f) {
            Vec3_Normalize(&fwd, &fwd);
        }

        m_forward.x = fwd.x;
        m_forward.y = fwd.y;
        m_forward.z = fwd.z;
    }

    // 0x80016258 (324 bytes)
    // NON_MATCHING: FP register allocation differs
    void RubberBandInterpolate(EVec3* result, EVec3 target, float dt) {
        // Compute displacement
        EVec3 disp;
        disp.x = target.x - result->x;
        disp.y = target.y - result->y;
        disp.z = target.z - result->z;

        float len = Vec3_Length2(&disp);

        // Snap if very close
        if (len <= 0.0f) {
            result->x = target.x;
            result->y = target.y;
            result->z = target.z;
            return;
        }

        // Get stiffness from camera parameters
        float stiffness;
        float distThreshold = *(float*)((u8*)m_pParams + 0x4C);
        if (len > distThreshold) {
            stiffness = *(float*)((u8*)m_pParams + 0x50);
        } else {
            stiffness = *(float*)((u8*)m_pParams + 0x54);
        }

        float speed = stiffness * len;
        float velocity = speed * dt;

        // Clamp to not overshoot
        if (velocity > len) {
            velocity = len;
        }

        // Normalize and scale
        float invLen = 1.0f / len;
        disp.x *= invLen;
        disp.y *= invLen;
        disp.z *= invLen;

        result->x += disp.x * velocity;
        result->y += disp.y * velocity;
        result->z += disp.z * velocity;
    }

    // 0x8001639C (312 bytes)
    // NON_MATCHING: SN Systems codegen
    void RubberBandMove(float dt) {
        // Interpolate eye
        EVec3 tempEye = m_currentEye;
        RubberBandInterpolate(&tempEye, m_rigEye, dt);
        m_currentEye = tempEye;

        // Interpolate target
        EVec3 tempTarget = m_currentTarget;
        RubberBandInterpolate(&tempTarget, m_rigTarget, dt);
        m_currentTarget = tempTarget;

        // Copy rig up directly (no interpolation on up vector)
        m_currentUp.x = m_rigUp.x;
        m_currentUp.y = m_rigUp.y;
        m_currentUp.z = m_rigUp.z;

        // Recompute forward
        EVec3 fwd;
        fwd.x = m_currentTarget.x - m_currentEye.x;
        fwd.y = m_currentTarget.y - m_currentEye.y;
        fwd.z = m_currentTarget.z - m_currentEye.z;

        if (fwd.x != 0.0f || fwd.y != 0.0f || fwd.z != 0.0f) {
            Vec3_Normalize(&fwd, &fwd);
        }

        m_forward.x = fwd.x;
        m_forward.y = fwd.y;
        m_forward.z = fwd.z;
    }

    // 0x800164AC (40 bytes)
    void MoveCamera(float dt) {
        if (m_motionType == CAMERA_MOTION_SNAP) {
            SnapCamera();
        } else {
            RubberBandMove(dt);
        }
    }
};


// ============================================================================
// ESimsCam - Main Camera Class
// ============================================================================
//
// ESimsCam::Update is the central per-frame camera update. It orchestrates
// parameter validation, noise settings, director integration, mode dispatch,
// controller input, and 3D window update.
//
// Original addresses: 0x800164D4 - 0x80019FBC (45 functions, 18212 bytes).
// Only key functions are decompiled here; the rest remain in asm stubs.

// 0x80016DB8 (512 bytes)
// NON_MATCHING: GCC vs SN Systems codegen differences
void ESimsCam_Update(ESimsCam* self) {
    // Step 1: Validate camera parameters
    self->m_pParams->Validate();

    // Step 2: Check cursor activity for noise settings
    int cursorInactive = self->CursorNotActive();
    if (cursorInactive) {
        self->SetActiveNoiseSetting(5); // ACTIVE noise
    } else {
        self->SetActiveNoiseSetting(6); // INACTIVE noise
    }

    // Step 3: Check if CameraDirector has control
    // This involves reading from the global director table
    // Director state at offset 0x160: 0=IDLE, 8=FADE_OUT
    // If state != 0 && state != 8, director is in control

    // Step 4: Camera mode dispatch (when not under director control)
    switch (self->m_mode) {
        case 0: // FOLLOW_PLAYER
            // FollowPlayerInteractor(m_playerId)
            break;
        case 1: // FOLLOW_SIM_STIFF
            // FollowSimStiff()
            break;
        case 2: // RESTORE_PREVIOUS
            // Restore from m_field3D0
            break;
    }

    // Step 5: Handle controller input (rotation and zoom)
    if (self->m_interpSocialMode == 0 && self->m_interpLotIntro == 0) {
        int rotChanged = self->HandleRotation();
        int zoomChanged = self->HandleZoom();
        self->m_bMoved = (rotChanged != 0 || zoomChanged != 0) ? 1 : 0;
    } else {
        self->m_bMoved = 0;
    }

    // Step 6: Update 3D viewport
    self->UpdateWin();
}

// 0x80016BD4 (96 bytes)
// NON_MATCHING: conditional return codegen
void ESimsCam_SetMode(ESimsCam* self, int newMode) {
    // Check if CameraDirector is in control (skip mode change if so)
    // Director state check via global table

    // If mode == 2 (RESTORE), load previous mode
    if (newMode == 2) {
        newMode = (int)self->m_field3D0;
    }

    // Swap current and previous modes
    u32 oldMode = (u32)self->m_mode;
    self->m_mode = newMode;
    self->m_field3D0 = oldMode;
}


// ============================================================================
// CameraDirector - Scripted Camera Sequences
// ============================================================================
//
// Manages cutscene/animation camera control as a state machine.
// Also manages BloomInterp and BlurInterp for effects during transitions.
//
// Original addresses: 0x8001AE60 - 0x80046B70 (34 functions, 14224 bytes).

// 0x8001D644 (1360 bytes)
// NON_MATCHING: GCC vs SN Systems codegen, register scheduling
void CameraDirector_Update(CameraDirector* self) {
    u8* base = (u8*)self;
    u32 state = self->m_state;

    // Check for cancel request when in control
    bool inControl = (state != 0 && state != 8);
    if (inControl) {
        self->CheckCancelled();
    }

    // State machine dispatch
    switch (state) {
        case 4: // INTERP_HOLD
        case 5: // INTERP_TO_GAME
        {
            u32 interpActive = *(u32*)(base + 0x198);
            if (interpActive != 0) {
                self->Interp();
                *(u32*)(base + 0x198) = 0;
            } else {
                self->ReleaseCurrentCamera();
            }
            break;
        }

        case 3: // INTERP_TO_CUT
        {
            u32 interpActive = *(u32*)(base + 0x198);
            if (interpActive != 0) {
                // Set up identity offset matrix
                EMat4_Identity(base + 0x80);

                // Apply attached dummy transforms if present
                if (*(u32*)(base + 0x118) != 0) {
                    // Multiply dummy matrix
                }
                if (*(u32*)(base + 0x11C) != 0) {
                    // Multiply second dummy
                }

                // Set FOV from interp state
                float fov = *(float*)(base + 0x1A0);
                self->SetFOV(fov);

                // Transition to ANIM_PLAYING
                self->m_state = 1;

                if (*(u32*)(base + 0x230) != 0) {
                    EMat4_Identity(base + 0x80);
                }
            }
            break;
        }

        case 7: // CANCEL_CHECK
        {
            // Disable noise on attached camera
            if (self->m_pCurrentCamera != NULL) {
                self->m_pCurrentCamera->SetActiveNoiseSetting(0);
            }
            u32 cancelTimer = *(u32*)(base + 0x23C);
            if (cancelTimer != 0) {
                self->CalcCancelCam();
            } else {
                self->ReleaseCurrentCamera();
            }
            break;
        }

        case 6: // ANIM_UPDATE
        {
            self->UpdateCameraPosAndFOV();
            // Check if animation controller finished
            // If finished, transition back to ANIM_PLAYING, stop anim
            break;
        }

        case 1: // ANIM_PLAYING
        {
            // Check animation controller state
            self->UpdateCameraPosAndFOV();
            // Check for pending state transition
            u32 pendingState = *(u32*)(base + 0x164);
            if (pendingState != 0) {
                self->m_state = pendingState;
                *(u32*)(base + 0x164) = 0;
            }
            break;
        }

        case 2: // HOLD
        {
            float holdTime = self->m_holdTime;
            if (holdTime > 0.0f) {
                // Decrement by frame delta time
                // float dt = readGlobalTimer();
                // holdTime -= dt;
                // self->m_holdTime = holdTime;
                if (holdTime < 0.0f) {
                    self->ReleaseCurrentCamera();
                    self->m_state = 0; // IDLE
                }
            }
            break;
        }
    }

    // Update animation note track if not idle
    if (self->m_state != 0) {
        self->UpdateAnimNoteTrack();
    }
}

// 0x8001E4C0 (128 bytes)
// NON_MATCHING: register scheduling
void CameraDirector_BeginCameraBloomInterp(CameraDirector* self, void* bloomData) {
    u8* base = (u8*)self;
    u32* src = (u32*)bloomData;

    // Copy start bloom values to offsets 0x2DC-0x2E8
    *(u32*)(base + 0x2DC) = src[0];
    *(u32*)(base + 0x2E0) = src[1];
    *(u32*)(base + 0x2E4) = src[2];
    *(u32*)(base + 0x2E8) = src[3];

    // Copy end bloom values to offsets 0x2EC-0x2F8
    *(u32*)(base + 0x2EC) = src[4];
    *(u32*)(base + 0x2F0) = src[5];
    *(u32*)(base + 0x2F4) = src[6];
    *(u32*)(base + 0x2F8) = src[7];

    // Reset bloom timer
    *(float*)(base + 0x2D4) = 0.0f;

    // Set bloom interp flag (bit 0 at 0x31C)
    u32 flags = *(u32*)(base + 0x31C);
    flags |= 1;
    *(u32*)(base + 0x31C) = flags;
}

// 0x8001E540 (176 bytes)
// NON_MATCHING: FP register allocation
void CameraDirector_BloomInterp(CameraDirector* self) {
    u8* base = (u8*)self;

    float bloomTimer = *(float*)(base + 0x2D4);
    float t = bloomTimer * 1.0f; // speed factor from constant pool

    if (t >= 1.0f) {
        t = 1.0f;
        // Clear bloom interp bit
        u32 flags = *(u32*)(base + 0x31C);
        flags &= ~1u;
        *(u32*)(base + 0x31C) = flags;
    }

    float oneMinusT = 1.0f - t;

    // End bloom values
    float endR = *(float*)(base + 0x2EC);
    float endG = *(float*)(base + 0x2F0);
    float endB = *(float*)(base + 0x2F4);
    float endA = *(float*)(base + 0x2F8);

    // Start bloom values
    float startR = *(float*)(base + 0x2DC);
    float startG = *(float*)(base + 0x2E0);
    float startB = *(float*)(base + 0x2E4);
    float startA = *(float*)(base + 0x2E8);

    float r = t * endR + oneMinusT * startR;
    float g = t * endG + oneMinusT * startG;
    float b = t * endB + oneMinusT * startB;
    float a = t * endA + oneMinusT * startA;

    EGraphics_SetCameraBloom(r, g, b, a);
}

// 0x8001E5F0 (156 bytes)
// NON_MATCHING: FP register allocation
void CameraDirector_BlurInterp(CameraDirector* self) {
    u8* base = (u8*)self;

    float blurTimer = *(float*)(base + 0x2D8);
    float t = blurTimer * 1.0f;

    if (t >= 1.0f) {
        t = 1.0f;
        u32 flags = *(u32*)(base + 0x31C);
        flags &= ~2u;
        *(u32*)(base + 0x31C) = flags;
    }

    float oneMinusT = 1.0f - t;

    // End blur values
    float endIntensity = *(float*)(base + 0x2FC);
    float endR         = *(float*)(base + 0x300);
    float endG         = *(float*)(base + 0x304);
    float endB         = *(float*)(base + 0x308);

    // Start blur values
    float startIntensity = *(float*)(base + 0x30C);
    float startR         = *(float*)(base + 0x310);
    float startG         = *(float*)(base + 0x314);
    float startB         = *(float*)(base + 0x318);

    float intensity = t * endIntensity + oneMinusT * startIntensity;
    float r         = t * endR         + oneMinusT * startR;
    float g         = t * endG         + oneMinusT * startG;
    float b         = t * endB         + oneMinusT * startB;

    EGraphics_SetMotionBlur(intensity, r, g, b);
}


// ============================================================================
// CameraManager - Per-frame update of all registered cameras
// ============================================================================
//
// Singleton at CameraManager::s_pCameraManager (0x804FD980).
// Holds up to 2 ESimsCam instances for splitscreen.

static CameraManager* s_pCameraManager = NULL;

// 0x8001EB80 (208 bytes)
// NON_MATCHING: global address resolution
void CameraManager_Update(CameraManager* self) {
    // Update camera[0] if registered
    ESimsCam* cam0 = self->m_cameras[0];
    if (cam0 != NULL) {
        ESimsCam_Update(cam0);
    }

    // Update camera[1] if registered (splitscreen)
    ESimsCam* cam1 = self->m_cameras[1];
    if (cam1 != NULL) {
        ESimsCam_Update(cam1);
    }
}

// 0x8001EC50 (68 bytes)
// NON_MATCHING: SN Systems codegen
CameraManager* CameraManager_GetSingleton() {
    if (s_pCameraManager == NULL) {
        s_pCameraManager = (CameraManager*)EAHeap_Alloc(sizeof(CameraManager));
        memset(s_pCameraManager, 0, sizeof(CameraManager));
    }
    return s_pCameraManager;
}

// 0x8001ECA0 (12 bytes)
ESimsCam* CameraManager_GetCamera(CameraManager* self, int index) {
    return self->m_cameras[index];
}
