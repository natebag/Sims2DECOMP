// audio_decomp.cpp - Sims 2 GameCube Audio System Decompilation
// Comprehensive documentation of the ambient music, sound effects, and audio
// engine architecture, derived from symbol analysis and disassembly of the
// original SN Systems-compiled DOL.
//
// ==========================================================================
//  AUDIO SYSTEM ARCHITECTURE OVERVIEW
// ==========================================================================
//
// The Sims 2 GC audio system is a layered architecture:
//
//   Layer 4 (Game Logic):    cSoundPlayer          -- game-facing sound API
//   Layer 3 (Mode Manager):  cSoundModeManager     -- music mode state machine
//   Layer 2 (Ambient):       AmbientScorePlayer    -- time-based ambient music
//                            AmbientSoundPlayer    -- individual ambient voices
//   Layer 1 (Sound Engine):  cBoxX                 -- sound event dispatcher
//                            cSoundCache           -- sample caching / LRU
//                            cHitMan               -- sound track sequencer
//   Layer 0 (Hardware):      ENgcAudio             -- GameCube DSP voice mgmt
//                            ENgcAudioSampleManager -- ARAM sample heap
//                            ENGCAudioStreamer      -- streaming audio playback
//
// The entire audio pipeline starts from ESimsApp::UpdateAudio() (0x800056F0),
// which is called once per frame from the main game loop.
//
// ==========================================================================
//  SECTION 1: HOW AMBIENT MUSIC WORKS
// ==========================================================================
//
// Ambient music in The Sims 2 GC uses a score-database system where .amb
// resource files define collections of sound events that play based on:
//   - Time of day (game simulation time)
//   - Listener proximity (3D distance from Sim/camera)
//   - Random probability per sound entry
//
// --------------------------------------------------------------------------
//  1.1 Score Database (ERAmbientScore / ERAmbientSound)
// --------------------------------------------------------------------------
//
// ERAmbientScore is an EResource (ref-counted, serializable) loaded from
// .amb files via the EAmbientScoreManager resource manager.
//
// ERAmbientScore layout (0x34 = 52 bytes):
//   +0x00: void**      vtable           (EResource vtable)
//   +0x04: [EResource base class fields: refcount, file, key, etc.]
//   +0x14: u32         m_startTime      (start of time range, game-hours)
//   +0x18: u32         m_endTime        (end of time range, game-hours)
//   +0x1C: u32         m_field_1C       (unknown, loaded from file)
//   +0x20: void*       m_soundArray     (heap-allocated array of ERAmbientSound)
//   +0x24: u32         m_field_24       (unknown)
//   +0x28: u8          m_numSounds      (count of sounds in array)
//   +0x29: u8          m_flags_29       (loaded from file)
//   +0x2A: u8          m_flags_2A       (loaded from file)
//   +0x2C: void*       m_field_2C       (heap pointer, freed in destructor)
//   +0x30: u32         m_field_30
//
// ERAmbientScore::Load() (0x80366E90, 580 bytes) reads fields sequentially
// from an EFile stream: startTime, endTime, field_1C, then a count of
// ERAmbientSound entries. It allocates an array and calls ERAmbientSound::Load()
// for each entry.
//
// ERAmbientSound layout (0x28 = 40 bytes):
//   +0x00: void**      vtable
//   +0x04: u32         m_soundEventKey  (key into ERSoundEvent resources)
//   +0x08: u32         m_field_08       (loaded as 4 bytes)
//   +0x0C: u32         m_field_0C       (loaded as 4 bytes)
//   +0x10: u32         m_posX           (3D position X, loaded from file)
//   +0x14: u32         m_posY           (3D position Y)
//   +0x18: u8          m_startHour      (hour range start)
//   +0x19: u8          m_endHour        (hour range end)
//   +0x1A: u8          m_looping        (looping flag)
//   +0x1B: u8          m_probability    (0-255, chance of triggering)
//   +0x1C: u8          m_hearingRange   (max distance for audibility)
//   +0x1D: u8          m_flags_1D       (additional flags)
//   +0x1E: u8          m_flags_1E
//   +0x1F: u8          m_flags_1F
//   +0x20: u8          m_flags_20
//   +0x21: u8          m_flags_21
//   +0x24: void*       m_field_24       (heap pointer, freed in destructor)
//
// ERAmbientSound::Load() (0x80366A70, 736 bytes) reads each field from the
// file stream using the EFile vtable read function (vtable[0x18/0x1C]).
// The function reads 4-byte fields first (event key, positions, etc.)
// then single-byte fields (hours, probability, flags).
//
// The resource managers for these types:
//   EAmbientScoreManager (0x80322BA0) -- manages ERAmbientScore resources
//   ESoundEventManager   (0x80328374) -- manages ERSoundEvent resources
//   ESoundTrackDataManager (0x803284F8) -- manages ERSoundTrackData resources
//   EAudioSampleManager  (0x8032CC80) -- manages audio sample data
//
// --------------------------------------------------------------------------
//  1.2 AmbientScorePlayer - The Score Scheduler
// --------------------------------------------------------------------------
//
// AmbientScorePlayer (0x3C = 60 bytes) manages playback of an ambient score.
// It runs a per-frame update loop that evaluates which sounds should be
// playing based on the current time of day and listener positions.
//
// AmbientScorePlayer layout:
//   +0x00: int         m_state          (0=stopped, 1=playing)
//   +0x04: int         m_field_04       (linked list or count)
//   +0x08: ERAmbientScore* m_ambientScore  (currently loaded score)
//   +0x0C: void*       m_soundPlayers   (linked list of AmbientSoundPlayers)
//   +0x10: int         m_numPlaying     (count of active sound players)
//   +0x14: int         m_volume         (master volume, default 1024)
//   +0x18: int         m_field_18       (score metadata)
//   +0x1C: int         m_numListeners   (default 2, typically camera + sim)
//   +0x20: void*       m_listenerBegin  (vector<ListenerInfo> start)
//   +0x24: void*       m_listenerEnd    (vector<ListenerInfo> end)
//   +0x28: void*       m_listenerCap    (vector<ListenerInfo> capacity)
//   +0x2C: void*       m_field_2C
//   +0x30: int         m_usePositional  (1=use 3D positioning, 0=stereo)
//   +0x34: float       m_time           (current score time in game-hours)
//   +0x38: u32         m_startTimestamp  (OS tick when playback started)
//
// ListenerInfo (0x20 = 32 bytes per listener):
//   +0x00: float[3]    position         (EVec3 - world position)
//   +0x0C: float[3]    direction        (EVec3 - facing direction)
//   +0x18: float[2]    padding/extra
//
// Static member:
//   AmbientScorePlayer::s_duckAmbient @ 0x804FDBA0 (4 bytes)
//   -- ambient ducking level, used to lower ambient volume during dialogue
//
// --------------------------------------------------------------------------
//  1.3 Update Loop and Sound Selection (per frame)
// --------------------------------------------------------------------------
//
// AmbientScorePlayer::Update() (0x800A81D8, 844 bytes):
//
// Pseudocode:
//   void AmbientScorePlayer::Update() {
//       if (!m_ambientScore || !m_soundPlayers) return;
//
//       // Update all active sound players
//       for (int i = 0; i < m_numListeners; i++) {
//           AmbientSoundPlayer* player = &m_soundPlayers[i];
//           if (player->IsValid()) {
//               player->Update();  // update pan/volume/position
//           }
//       }
//
//       // Throttle: only evaluate new sounds every ~1 second
//       u32 now = timeGetTime();
//       if (now - m_startTimestamp < 999) return;
//       m_startTimestamp = now;
//
//       // Remove any sounds that finished
//       RemoveFinishedSounds();
//
//       // If not in playing state, skip sound selection
//       if (m_state != 1) return;
//
//       // Build candidate list from score database
//       // (uses stack-allocated vector)
//       vector<ERAmbientSound*> candidates;
//
//       ERAmbientScore* score = m_ambientScore;
//       int numSounds = score->m_numSounds;
//       void* soundArray = score->m_soundArray;
//
//       for (each sound in score) {
//           if (!SoundRangeCoversCurTime(sound)) continue;
//           if (SoundAlreadyPlaying(sound))      continue;
//           if (!SoundInHearingDistance(sound))   continue;
//
//           // Sound is eligible - add based on probability
//           AddSoundBasedOnProbability(candidates, i, flag);
//       }
//   }
//
// --------------------------------------------------------------------------
//  1.4 Transitions - How Music Changes
// --------------------------------------------------------------------------
//
// Music transitions are handled by cSoundModeManager, which manages the
// current audio mode (front-end, live mode, build/buy, CAS, loading, demo).
//
// cSoundModeManager layout (0x34 = 52 bytes):
//   +0x00: void**  vtable
//   +0x04: int     m_mode            (current mode: 0=none, 1=frontend, 2=live, 3=loading, etc.)
//   +0x08: float   m_musicFadeTarget (target music volume for fade)
//   +0x0C: float   m_musicFadeCurrent (current music volume during fade)
//   +0x10: float   m_sfxFadeTarget
//   +0x14: float   m_sfxFadeCurrent
//   +0x18: float   m_sfxFadeRate
//   +0x1C: int     m_loadMusicState  (loading music state machine)
//   +0x20: int     m_loadMusicTrack  (current loading track index)
//   +0x24: int     m_loadMusicReady  (is loading music loaded?)
//   +0x30: int     m_currentTrackIdx (current frontend track index)
//
// Mode transitions:
//   cSoundModeManager::SetMode(int mode) @ 0x800B0498 (196 bytes)
//   -- Triggers volume fades and music track changes
//   -- Mode 0: silence, Mode 1: frontend music, Mode 2: live mode (ambient)
//   -- Mode 3: loading screen music
//
// Fade system:
//   cSoundModeManager::FadeOutMusic(uint ms) @ 0x800B0458  -- start music fade-out
//   cSoundModeManager::FadeInMusic(uint ms)  @ 0x800B0468  -- start music fade-in
//   cSoundModeManager::FadeOutSFX(uint ms)   @ 0x800B0478  -- start SFX fade-out
//   cSoundModeManager::FadeInSFX(uint ms)    @ 0x800B0488  -- start SFX fade-in
//
// UpdateMusicVolume() (0x800B055C, 848 bytes) smoothly interpolates between
// current and target volume each frame, updating ENgcAudio's music volume.
//
// UpdateLoadMusic() (0x800B0B00, 836 bytes) implements a state machine for
// loading screen music:
//   - Checks if audio streamer is active (streaming tracks from disc)
//   - When mode == 3 (loading) and no music playing, picks a track
//   - Calls StartMusicTrack() to begin streaming
//   - Monitors stream completion and loops or advances
//
// Track selection:
//   GetFrontEndMusicTrack(bool next) @ 0x800B0E44  -- returns track name
//   NextFrontEndTrack() / PrevFrontEndTrack()       -- cycle through playlist
//   StartFrontEndMusic() @ 0x800B0EB0              -- begin frontend music
//   StartBuildBuyMusic() @ 0x800B104C              -- begin build/buy music
//   StartCASMusic()      @ 0x800B10F0              -- begin CAS music
//
// StartMusicTrack() (0x800B0F70, 220 bytes) loads a music file by name and
// calls ENgcAudio::PlayMusic() with an EPMDesc (play music descriptor).
//
// --------------------------------------------------------------------------
//  1.5 AmbientSoundPlayer - Individual Voice Management
// --------------------------------------------------------------------------
//
// AmbientSoundPlayer (0x30 = 48 bytes) handles a single ambient sound voice:
//
//   +0x00: void**      vtable
//   +0x04: AmbientScorePlayer* m_scorePlayer  (parent score player)
//   +0x08: int         m_isFinished     (1 when playback complete)
//   +0x0C: int         m_voiceHandle    (ENgcAudio voice handle)
//   +0x10: int         m_panValue       (current pan)
//   +0x14: float       m_posX           (current 3D position X)
//   +0x18: float       m_posY           (current 3D position Y)
//   +0x1C: float       m_posZ           (current 3D position Z)
//   +0x20: float       m_prevPosX       (previous position for interpolation)
//   +0x24: float       m_prevPosY
//   +0x28: ERAmbientSound* m_ambientSound  (the sound definition)
//   +0x2A: u8          m_currentVolume  (0-255)
//   +0x2C: int         m_state          (playback state)
//
// Start() (0x800A9374, 964 bytes):
//   - Loads the ERSoundEvent via resource key from the ERAmbientSound
//   - Calls SetInitialSoundPosition() to compute 3D world position
//   - Binds an ENgcAudio voice via AudioBindVoice()
//   - Sets initial volume and pan based on listener distance
//
// SetInitialSoundPosition() (0x800A983C, 2068 bytes):
//   - Large function that computes the 3D world position for the sound
//   - Uses the sound's stored coordinates and the current lot/room geometry
//   - Handles indoor vs outdoor positioning differently
//
// UpdatePanAndVolume() (0x800AA5B8, 844 bytes):
//   - Per-frame update of pan and volume based on listener proximity
//   - Calculates distance from each listener to the sound
//   - Uses closest listener for volume/pan computation
//   - Implements distance attenuation curve
//   - Calls ENgcAudio::SetVoiceState() to apply changes
//
// UpdateLoopingSoundPosition() (0x800AA0A4, 1300 bytes):
//   - For looping sounds, smoothly moves the sound position
//   - Implements wandering/drifting behavior for atmospheric sounds
//
// ==========================================================================
//  SECTION 2: HOW SOUND EFFECTS ARE TRIGGERED
// ==========================================================================
//
// --------------------------------------------------------------------------
//  2.1 cSoundPlayer - Game-Facing Sound API
// --------------------------------------------------------------------------
//
// cSoundPlayer is the primary interface for game code to trigger sounds.
// There is a single global instance accessed via SDA-relative addressing:
//   g_pSoundPlayer @ r13 - 0xAC0C
//
// cSoundPlayer layout (0x20+ bytes):
//   +0x00: int         m_initialized    (1 when fully set up)
//   +0x04: cBoxX*      m_soundSystem    (the sound engine instance)
//   +0x08: int         m_soundEnabled   (master enable flag)
//   +0x0C: int         m_isPaused       (pause state)
//   +0x10: int         m_savedVolume    (volume before mute)
//   +0x14: int         m_field_14
//   +0x18: int         m_field_18
//   +0x1C: void*       m_listSentinel   (SoundEventInfo linked list)
//
// Global references:
//   g_pSoundBox     @ r13 - 0xA044  -- cBoxX* (main sound engine)
//   g_pSoundBoxInst @ r13 - 0xA070  -- secondary ref to sound box

// Volume settings are stored in OptionsRecon:
//   OptionsRecon + 0x1C: s8 m_sfxVolume     (0-100)
//   OptionsRecon + 0x1D: s8 m_musicVolume   (0-100)
//   OptionsRecon + 0x28: s8 m_voxVolume     (0-100)
//   OptionsRecon + 0x29: s8 m_ambientVolume (0-100)
//
// --------------------------------------------------------------------------
//  2.2 Sound Trigger Flow
// --------------------------------------------------------------------------
//
// Game code triggers sounds through three PlayBySource overloads:
//
//   PlayBySource(unsigned int hashKey, short sourceId)
//     @ 0x800B7968, 248 bytes
//     -- Looks up ERSoundEvent by hash key from the ESoundEventManager
//     -- Creates a SoundEventInfo struct on the heap
//     -- Dispatches to cBoxX::Event()
//
//   PlayBySource(char* name, short sourceId)
//     @ 0x800B7A60, 108 bytes
//     -- Looks up ERSoundEvent by name string
//     -- Calls the hash-key overload
//
//   PlayBySource(ERSoundEvent* event, short sourceId)
//     @ 0x800B7ACC, 84 bytes
//     -- Direct event pointer, dispatches immediately
//
// PlayBySource(uint, short) pseudocode:
//   void cSoundPlayer::PlayBySource(uint hashKey, short sourceId) {
//       if (!m_initialized || !m_soundEnabled) return;
//       if (hashKey == 0 || sourceId == -2) return;
//
//       // Look up sound event resource
//       ERSoundEvent* event = ESoundEventManager::GetByKey(hashKey);
//
//       // Build SoundEventInfo descriptor
//       SoundEventInfo info;
//       info.event = event;
//       info.sourceId = sourceId;
//       info.priority = 1.0f;  // default priority
//       info.volume = m_savedVolume;
//
//       // Dispatch to sound engine
//       // SoundEventInfo is 20 bytes: event*, sourceId, priority, volume, flags
//       HeapAlloc(sizeof(SoundEventInfo));
//       memcpy(...);
//       AddToEventList(info);
//   }
//
// --------------------------------------------------------------------------
//  2.3 cBoxX - Sound Event Dispatcher
// --------------------------------------------------------------------------
//
// cBoxX is the core sound event dispatcher that handles sound event routing,
// surround sound panning, volume management, and instance tracking.
//
// Key methods:
//   Event(int, int, int, ERSoundEvent*, float) @ 0x800AEB0C (2472 bytes)
//     -- Main event dispatch: creates sound instances, manages ducking/priority
//     -- Handles event types: one-shot, looping, streaming, sequence
//
//   MappedEvent(ERSoundEvent*, int, float) @ 0x800AEADC (48 bytes)
//     -- Simplified dispatch for pre-mapped events
//
//   GetSurroundVol(AmbientScorePlayer*, EVec3&, float, float,
//                  int&, int&, int&, int&) @ 0x800ADB48 (856 bytes)
//     -- Calculates surround sound volume levels for 4 speakers
//     -- Uses listener position relative to sound position
//     -- Computes front/rear, left/right ratios
//
//   SetAmbientScore(int) @ 0x800AF4B4 (264 bytes)
//     -- Binds an ambient score to the sound engine for background music
//
//   FindSndobInstancePair(ERSoundEvent*, int) @ 0x800AF61C (272 bytes)
//     -- Looks up active instance of a sound event using a red-black tree
//     -- Key = (ERSoundEvent*, instanceId) pair
//
//   UpdateSndobVolPan(ERSoundEvent*) @ 0x800AFB00 (216 bytes)
//     -- Updates volume and pan for all instances of a given sound event
//
// Instance tracking uses std::map<ERSoundEvent*, int> (red-black tree):
//   _Rb_tree operations at 0x803A2BA0-0x803A2D10
//
// --------------------------------------------------------------------------
//  2.4 Sound Cache and Track System
// --------------------------------------------------------------------------
//
// cSoundCache manages loaded audio samples with LRU eviction:
//
//   +0x00: [fields]
//   IsInMemory(cTrack*) @ 0x80119D48    -- check if a track is loaded
//   IsInMemory(ERSoundEvent*) @ 0x80119D6C -- check by event reference
//   GetTrackObject(ERSoundEvent*, bool) @ 0x80119C20 (296 bytes)
//     -- Returns cached cTrack for an event, loading if needed
//   CleanupIdleTracks() @ 0x8011959C (1120 bytes)
//     -- LRU eviction of idle tracks to free ARAM
//   UpdateDuckingPriorities() @ 0x801199FC (212 bytes)
//     -- Updates priority-based ducking (e.g., music ducks under dialogue)
//   PauseGroup(int) / UnpauseGroup(int)
//     -- Group-based pause/unpause (music, SFX, ambient, etc.)
//
// cTrack (constructed at 0x801175E0, 268 bytes) wraps an ERSoundEvent with
// playback state, volume, and the cHitMan sequencer for complex sounds.
//
// ERSoundEvent layout (0x34 = 52 bytes):
//   +0x00: void**    vtable
//   +0x04: [EResource base: refcount, file, etc.]
//   +0x10: u32       m_field_10    (loaded from file, contains track data ref)
//   +0x24: u32       m_field_24    (sub-event reference)
//   +0x30: u32       m_field_30    (event flags)
//   -- Event properties accessed via:
//     GetEventType() @ 0x8036A050  -- returns event type enum
//     GetVolume()    @ 0x8036A058  -- returns volume (0-100)
//     GetProb()      @ 0x8036A060  -- returns probability (0-100)
//
// ERSoundTrackData (0x1C = 28 bytes):
//   +0x00: void**    vtable
//   +0x04: u32       m_field_04     (loaded from file)
//   +0x10: u32       m_programData  (compiled track program data)
//   +0x14: void*     m_instructions (instruction array for sequencer)
//   +0x18: u32       m_field_18
//   -- GetInstruction(uint idx) @ 0x8036A6C4 (20 bytes)
//   -- GetProgramSize()         @ 0x8036A6D4 (20 bytes)
//   -- The track data is a bytecode program interpreted by cHitMan
//
// --------------------------------------------------------------------------
//  2.5 Game Mode Sound Management
// --------------------------------------------------------------------------
//
// cSoundPlayer::SetGameMode(snd::eMode) @ 0x800B7814 (132 bytes)
//   Routes to cSoundModeManager::SetMode() on the sound box
//
// Game modes (snd::eMode enum, stored at iSavedGameSoundMode @ 0x804FDBE0):
//   0 = None/Silent
//   1 = Frontend (menu music)
//   2 = Live Mode (ambient score + SFX)
//   3 = Loading Screen
//   4 = Build/Buy Mode
//   5 = CAS (Create-A-Sim)
//   6 = Demo Mode
//
// cSoundPlayer::NotifyHourChange() @ 0x800B7EB0 (84 bytes)
//   Called when the game clock advances an hour; triggers AmbientScorePlayer
//   to re-evaluate which sounds should be playing based on time ranges.
//
// cSoundPlayer::NotifyViewChange() @ 0x800B7E5C (84 bytes)
//   Called when camera view changes; triggers recalculation of 3D sound
//   positions and panning for all active ambient sounds.
//
// ==========================================================================
//  SECTION 3: ENgcAudio - GameCube Hardware Audio Layer
// ==========================================================================
//
// ENgcAudio (0x60 = 96 bytes) is the platform-specific audio driver for
// GameCube, wrapping the DolphinSDK AX (audio mixer) library.
//
// ENgcAudio layout:
//   +0x00: void**    vtable           (EAudio base class vtable, 208-byte vtable)
//   +0x04: float     m_musicVolume    (0.0 - 1.0)
//   +0x08: float     m_musicPan       (0.0 - 1.0, 0.5 = center)
//   +0x0C: int       m_isPlayingMusic (flag)
//   +0x10-0x13:      padding
//   +0x14: void*     m_field_14       (music stream handle?)
//   +0x18: void*     m_field_18       (music data pointer?)
//   +0x1C: void*     m_field_1C       (current voice array?)
//   +0x38: int       m_field_38       (update counter)
//   +0x3C: int       m_field_3C       (update counter 2)
//   +0x40: void*     m_musicVoice     (current music voice)
//   +0x5C: void*     m_voicePool      (voice allocation pool)
//
// Global instances:
//   _ngcAudioSampleMan @ 0x804C39E0 (3368 bytes) -- ENgcAudioSampleManager
//   _pMemoryCard      @ 0x804FF210 (4 bytes)      -- ENgcMemoryCard*
//   __MIXSoundMode    @ 0x805002F0 (4 bytes)      -- current mix mode
//
// --------------------------------------------------------------------------
//  3.1 Initialization
// --------------------------------------------------------------------------
//
// ENgcAudio::InitAudio() (0x8032B8EC, 260 bytes):
//   1. Checks global flags (r13-26576, r13-26572) for init state
//   2. Calls AIInit() (DolphinSDK audio interface init)
//   3. Calls AXInit() (DolphinSDK audio mixer init)
//   4. Calls AXSetCompressor(AX_COMPRESSOR_OFF)
//   5. Calls AXSetMode(AX_MODE_DPL2) -- Dolby Pro Logic II
//   6. Checks OSGetSoundMode() to determine mono/stereo/surround
//   7. Calls MIXSetSoundMode() accordingly (0=mono, 3=surround)
//   8. Allocates ENGCAudioStreamer for streaming music
//   9. Initializes 64 voice slots (array at 0x804C25E0, 68 bytes each)
//      Each slot = {u32 voiceHandle, u32 streamHandle, u32 bindState, ...}
//      Slots initialized to -1 (unused)
//
// --------------------------------------------------------------------------
//  3.2 Voice Management
// --------------------------------------------------------------------------
//
// The GameCube AX library provides 64 hardware voices. ENgcAudio maps these
// to a pool of EVoice objects.
//
// AudioAllocVoice() (0x8032C5D4, 64 bytes):
//   Returns the next free voice from the pool, or NULL if all 64 are in use.
//
// AudioBindVoice(EVoice*, uint sampleKey) (0x8032C65C, 412 bytes):
//   1. Looks up sample data via key from ENgcAudioSampleManager
//   2. If sample is in ARAM, configures the voice:
//      - Sets ADPCM coefficients from sample header
//      - Sets loop points (start, end, loop start)
//      - Sets sample rate
//   3. Starts voice playback via AX library calls
//
// UnbindVoice(EVoice*) (0x8032C7F8, 232 bytes):
//   Stops playback and returns the voice to the free pool.
//
// SetVoiceState(EVoice*, EVoiceDesc&) (0x8032C970, 304 bytes):
//   Updates voice parameters: volume, pitch, pan, surround mix.
//
// SetSpeakerVolumes(EVoice*, int*, uint) (0x8032CAA0, 108 bytes):
//   Sets per-speaker volume levels (FL, FR, RL, RR for surround).
//
// FreeVoice(EVoice*) (0x8032C614, 72 bytes):
//   Returns a voice to the free pool.
//
// --------------------------------------------------------------------------
//  3.3 Music Playback (Streaming)
// --------------------------------------------------------------------------
//
// ENgcAudio::PlayMusic(EPMDesc&) (0x8032BA5C, 1152 bytes):
//   1. Searches for two free consecutive voice slots (for stereo)
//   2. Loads the music file via EAudioStreamManager
//   3. Calls ENGCAudioStreamer::AllocateStereo() for stereo streams
//   4. Configures voice parameters from EPMDesc (volume, pan, loop)
//   5. Begins streaming from disc via DVDLowAudioStream
//
// ENGCAudioStreamer (constructed at 0x8034E004, 228 bytes):
//   Manages streaming audio from disc using double-buffering.
//   Allocate()       -- allocates mono stream
//   AllocateStereo() -- allocates stereo stream pair
//   Update()         -- refills buffers from disc (called each frame)
//   Free()           -- releases stream resources
//   SetVolume()      -- adjusts stream volume
//   SetPan()         -- adjusts stream pan
//
// ENgcAudio::StopMusic() (0x8032C1FC, 204 bytes):
//   Stops the current music stream and frees the voice slots.
//
// ENgcAudio::PauseMusic() / ResumeMusic():
//   Pauses/resumes the music stream without releasing resources.
//
// --------------------------------------------------------------------------
//  3.4 ARAM Sample Manager
// --------------------------------------------------------------------------
//
// ENgcAudioSampleManager (0xD28 = 3368 bytes) manages audio sample storage
// in the GameCube's Auxiliary RAM (ARAM), which is 16MB of dedicated audio
// memory separate from main RAM.
//
// heapInit() (0x8032D0B8, 476 bytes):
//   Initializes the ARAM heap with a single large free block.
//
// heapAlloc(uint size) (0x8032D294, 408 bytes):
//   First-fit allocation from the ARAM free list.
//   Returns ARAM address (not main RAM pointer).
//
// heapFree(uint aramAddr) (0x8032D634, 336 bytes):
//   Frees an ARAM block and coalesces adjacent free blocks.
//
// AllocateAndLoadResource(EFile*, uint, uint) (0x8032CDE4, 504 bytes):
//   Loads a sample from disc into ARAM:
//   1. Reads sample header (format, loop points, ADPCM coefficients)
//   2. Allocates ARAM block via heapAlloc()
//   3. DMA transfers sample data from main RAM to ARAM
//
// The heap uses a linked list of ARAMBlock structures with resort operations
// (heapResortSmaller/heapResortLarger) to maintain sorted free list.
//
// --------------------------------------------------------------------------
//  3.5 UIAUDIO - UI Sound Effects
// --------------------------------------------------------------------------
//
// UIAUDIO provides a simple interface for UI code to play sound effects:
//
//   UIAUDIO::s_pInstance @ 0x804FDDF0 (singleton pointer)
//   UIAUDIO::Instance() @ 0x801779DC -- returns/creates singleton
//   UIAUDIO::PlaySound(uint hashKey) @ 0x80177670 (236 bytes)
//   UIAUDIO::StopSound(int handle) @ 0x80177948 (148 bytes)
//   UIAUDIO::Update() @ 0x8017775C (68 bytes) -- called per frame
//   UIAUDIO::UpdateAudioLoad(int) @ 0x801777A0 (424 bytes)
//
//   UIAUDIO::UIAUDIORecord -- entry in the UI sound table:
//     Contains name string, hash key, ERSoundEvent reference
//
//   UIAUDIOTarget -- APT UI binding for audio control:
//     Constructed at 0x80180348 (1092 bytes) with many callback registrations
//     Allows ActionScript UI code to trigger sounds via SetVariable()
//
// ==========================================================================
//  SECTION 4: cAudioInfo - World Audio State
// ==========================================================================
//
// cAudioInfo provides environmental audio information to the sound engine:
//
//   CurrentSimSpeed()  @ 0x800AAC34 (56 bytes)
//     -- Returns current simulation speed (affects ambient update rate)
//
//   GetObjectPosition(int objId, cAudioWorldCoord&) @ 0x800AAC6C (240 bytes)
//     -- Gets 3D world position of a game object for positional audio
//
//   GetObjectData(int objId, DataIdx) @ 0x800AAD5C (964 bytes)
//     -- Queries object properties relevant to audio (material, size, etc.)
//     -- Large switch statement over DataIdx enum
//
//   OutdoorTileRatio() @ 0x800AB120 (428 bytes)
//     -- Returns ratio of outdoor to indoor tiles in current view
//     -- Used to blend between indoor/outdoor reverb settings
//
// ==========================================================================
//  AUDIO SYSTEM FUNCTION INDEX
// ==========================================================================
//
// AmbientScorePlayer (26 functions, ~4.5KB total):
//   0x800A80B8  AmbientScorePlayer(bool)           132B  ctor
//   0x800A813C  ~AmbientScorePlayer()               156B  dtor
//   0x800A81D8  Update()                             844B  per-frame update
//   0x800A8524  SetListenerCount(int)                128B  reallocate listeners
//   0x800A85A4  UpdateListener(uint, EVec3&, EVec3&) 448B  update listener pos
//   0x800A8764  SetTime(float)                        8B  set score time
//   0x800A876C  GetTime()                             8B  get score time
//   0x800A8774  Load(char*)                         364B  load score file
//   0x800A88E0  Start()                              60B  begin playback
//   0x800A891C  Stop()                               56B  stop playback
//   0x800A8954  Shutdown()                           196B  full shutdown
//   0x800A8A18  SetPause(bool)                      248B  pause/unpause
//   0x800A8B10  SetVolume(int)                       12B  set master volume
//   0x800A8B1C  GetVolume()                           8B  get master volume
//   0x800A8B24  GetAmbientScore()                     8B  get score ptr
//   0x800A8B2C  GetNumPlaying()                       8B  get active count
//   0x800A8B34  GetListenerInfos()                    8B  get listener array
//   0x800A8B3C  SoundRangeCoversCurTime(...)        236B  time range check
//   0x800A8C28  SoundAlreadyPlaying(...)             136B  duplicate check
//   0x800A8CB0  SoundInHearingDistance(...)          552B  3D distance check
//   0x800A8ED8  AddSoundBasedOnProbability(...)      184B  probability gate
//   0x800A8F90  KillAllAmbientSounds()               184B  stop all sounds
//   0x800A9048  AddNewAmbientSoundPlayer(...)        148B  start new sound
//   0x800A90DC  RemoveAmbientSoundPlayer(...)        188B  stop specific sound
//   0x800A9198  RemoveFinishedSounds()               216B  cleanup finished
//
// AmbientSoundPlayer (15 functions, ~7KB total):
//   0x800A9270  AmbientSoundPlayer()                  76B  ctor
//   0x800A92BC  ~AmbientSoundPlayer()                116B  dtor
//   0x800A9330  SetScorePlayer(AmbientScorePlayer*)    8B
//   0x800A9338  SetAmbientSound(ERAmbientSound*)       8B
//   0x800A9340  Update()                              52B  per-frame update
//   0x800A9374  Start()                              964B  begin playback
//   0x800A9738  Stop()                               124B  stop playback
//   0x800A97B4  Pause()                               68B
//   0x800A97F8  UnPause()                             68B
//   0x800A983C  SetInitialSoundPosition()           2068B  compute 3D position
//   0x800AA050  UpdateSoundPosition()                 84B
//   0x800AA0A4  UpdateLoopingSoundPosition()        1300B  animate position
//   0x800AA5B8  UpdatePanAndVolume()                 844B  distance-based pan
//   0x800AA904  UpdateSoundVolume()                  176B  apply volume
//   0x800AA9B4  GetAmbientSound()                     8B
//   0x800AA9BC  IsFinished()                          92B
//   0x800AAA18  IsValid()                             40B
//
// cSoundPlayer (26 functions, ~3KB total):
//   0x800B7264  cSoundPlayer()                       104B  ctor
//   0x800B72CC  ~cSoundPlayer()                      156B  dtor
//   0x800B7368  Initialize()                         216B  full init
//   0x800B7440  Shutdown()                           132B
//   0x800B74C4  KillSourceEvent(int)                 248B
//   0x800B75BC  KillAllEvent()                       236B
//   0x800B76A8  Update()                             364B  per-frame
//   0x800B7814  SetGameMode(snd::eMode)              132B
//   0x800B7898  GetGameMode()                         24B
//   0x800B78B0  EnableSound(bool)                     84B
//   0x800B7904  QuietAll()                           100B
//   0x800B7968  PlayBySource(uint, short)            248B  play by hash
//   0x800B7A60  PlayBySource(char*, short)           108B  play by name
//   0x800B7ACC  PlayBySource(ERSoundEvent*, short)    84B  play by event
//   0x800B7B20  QuietBySourceID(int)                  84B
//   0x800B7B74  PauseSFX()                           112B
//   0x800B7BE4  ResumeSFX()                          112B
//   0x800B7C54  PauseMusic()                         112B
//   0x800B7CC4  ResumeMusic()                        112B
//   0x800B7D34  PauseSounds()                        148B
//   0x800B7DC8  ResumeSounds()                       148B
//   0x800B7E5C  NotifyViewChange()                    84B
//   0x800B7EB0  NotifyHourChange()                    84B
//   0x800B7F04-0x800B80FC  Get/Set volume functions   ~600B total
//
// ENgcAudio (24 functions, ~5KB total):
//   0x8032B7A8  ENgcAudio()                          112B  ctor
//   0x8032B818  ~ENgcAudio()                          92B  dtor
//   0x8032B8EC  InitAudio()                          260B  HW init
//   0x8032B9F0  AudioAlarmHandler(OSAlarm*, OSContext*) 4B  stub
//   0x8032B9F4  Shutdown()                           104B
//   0x8032BA5C  PlayMusic(EPMDesc&)                 1152B  stream music
//   0x8032BEDC  GetIndexFromVoice(EVoice*)             8B
//   0x8032BEE4  GetVoiceFromIndex(uchar)               8B
//   0x8032BEEC  Update()                             784B  per-frame
//   0x8032C1FC  StopMusic()                          204B
//   0x8032C2C8  PauseMusic()                         112B
//   0x8032C338  ResumeMusic()                        112B
//   0x8032C3A8  SetMusicVolume(float)                192B
//   0x8032C468  GetMusicVolume()                       8B
//   0x8032C470  SetMusicPan(float)                   196B
//   0x8032C534  GetMusicPan()                          8B
//   0x8032C53C  IsPlayingMusic()                      92B
//   0x8032C5D4  AudioAllocVoice()                     64B
//   0x8032C614  FreeVoice(EVoice*)                    72B
//   0x8032C65C  AudioBindVoice(EVoice*, uint)        412B  bind sample
//   0x8032C7F8  UnbindVoice(EVoice*)                 232B
//   0x8032C8E0  GetVoiceState(EVoice*, EVoiceDesc&)  144B
//   0x8032C970  SetVoiceState(EVoice*, EVoiceDesc&)  304B
//   0x8032CAA0  SetSpeakerVolumes(EVoice*, int*, uint) 108B
