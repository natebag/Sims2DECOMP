#ifndef SANIMATOR2_H
#define SANIMATOR2_H

#include "types.h"

// Forward declarations
class cXPerson;
class cXObject;
class ERC;
class EShader;
class E3DWindow;
class EACTrack;
class ERAnim;
class AnimRef;
class PropRef;
class ReconBuffer;
class StackElem;
class TileList;
class CTilePt;
class EAnimNote;
class REffectsAttachment;
class RumbleDataElement;
class CameraBloomDataElement;
class CameraBlurDataElement;
class AnimParticleData;
class IdleAnimateParam;
class AnimateNewParam;
class CasSimDescriptionS2C;
template <typename K, typename V> class TRedBlackTree;
class EBoneParticle;

// ============================================================================
// EVec2 - 2D vector
// ============================================================================
struct EVec2 {
    float x, y;
};

// ============================================================================
// EVec3 - 3D vector (12 bytes)
// ============================================================================
struct EVec3 {
    float x, y, z;
};

// ============================================================================
// EMat4 - 4x4 matrix
// ============================================================================
class EMat4 {
public:
    float m[4][4];
};

// ============================================================================
// EHeadOrient - Head orientation data
// ============================================================================
struct EHeadOrient {
    char _data[0x78]; // opaque
};

// ============================================================================
// AwarenessManager - Manages sim awareness state
// Embedded in SAnimator2 at offset +0x620
// ============================================================================
class AwarenessManager {
public:
    void SetIsRaining(bool raining);
    void SetPlayerControl(bool control);
    void SetAwareOfObject(cXObject* obj);
    void SetAwareOfObjectKilled(cXObject* obj);
    void ClearAwareOfObject(cXObject* obj);

    char _data[0x1C]; // opaque internal data
};

// ============================================================================
// EAnimController - Animation controller (embedded in ESim at +0x334)
// ============================================================================
class EAnimController {
public:
    u32 m_flags;                         // +0x000
    char _pad004[0x04];                  // +0x004
    int m_skillTrackIndex;               // +0x008
    char _pad00C[0x38];                  // +0x00C
    u32 m_trackData;                     // +0x044

    void SetAllTrackSpeed(float speed);
    void SetTrackBlendFactors(EACTrack* track, float* factors);
    void SetTrackBlendFactors(u32 trackFlags, float* factors);
    void CalcNodeOrient(int boneIdx, EMat4& outMat);
};

// ============================================================================
// ESim - Sim entity, contains the EAnimController
// ============================================================================
class ESim {
public:
    char _pad000[0x334];                 // +0x000
    EAnimController m_animController;    // +0x334
};

// ============================================================================
// EGraphics - Graphics system singleton
// ============================================================================
class EGraphics {
public:
    void SetMotionBlur(float a, float b, float c, float d);
};

// ============================================================================
// EAHeap - EA heap allocator
// ============================================================================
class EAHeap {
public:
    static void* MallocAligned(u32 size, u32 align, u32 flags, int pool);
    static void Free(void* ptr);
};

// ============================================================================
// Globals struct - at 0x80475DCC (_globals)
// ============================================================================
struct Globals {
    char _pad000[0xBC];          // +0x000
    cXPerson* m_simPlayers[2];   // +0x0BC (player 0), +0x0C0 (player 1)
};

extern Globals _globals;
extern EGraphics* _pGfx;

// External memory functions
extern "C" void* MainHeap();
extern "C" void* memset(void* dst, int val, u32 size);

// ============================================================================
// SAnimator - Base class for sim animators
// ============================================================================
class SAnimator {
public:
    virtual ~SAnimator();
};

// ============================================================================
// SAnimator2 - Primary sim animation controller
//
// Member offsets derived from disassembly:
//   +0x000: vtable (inherited from SAnimator)
//   +0x004: cXPerson* m_pPerson
//   +0x008: ESim* m_pSim
//   +0x010: int m_followState
//   +0x018: int m_followMode
//   +0x01C: EVec3 m_pos
//   +0x028: int m_snapToGrid
//   +0x02C: int m_animState
//   +0x030: float m_animDirection
//   +0x0B0: int m_desiredAnimState
//   +0x0B8: float m_cameraZoomRatio
//   +0x0C8: int m_skillTrackIndex
//   +0x0D0: float m_blendTime
//   +0x0D4: AnimRef* m_currentAnimRef
//   +0x0DC: int m_prevTick
//   +0x0E0: int m_currentTick
//   +0x0FC: float m_timeMultiplier
//   +0x100: float m_desiredTimeMultiplier
//   +0x104: float m_pauseMultiplier
//   +0x120: int m_idleInitialized
//   +0x130: int m_lastCostume
//   +0x180: EHeadOrient m_headOrient
//   +0x5F8: s8 m_portalMode
//   +0x604: CasSimDescriptionS2C* m_pNormalSimDescription
//   +0x60C: int m_boneIndices[4]
//   +0x61C: u32 m_flags
//   +0x620: AwarenessManager m_awarenessMgr
//   +0x63C: cXObject* m_pAwareOfObject
//   +0x650: float m_savedPauseMultiplier
// ============================================================================
class SAnimator2 : public SAnimator {
public:
    // Enums
    enum eAnimState {};

    enum eFollowMode {
        FOLLOW_NONE = 0,
        FOLLOW_START = 1,
        FOLLOW_TURN = 2,
        FOLLOW_MIDDLE = 3,
        FOLLOW_MOVE_TO_TURN = 4,
        FOLLOW_DONE = 5,
    };

    enum eWalkRunStyle {};

    // Members at exact offsets
    cXPerson* m_pPerson;                     // +0x004
    ESim* m_pSim;                            // +0x008
    char _pad00C[0x04];                      // +0x00C
    int m_followState;                       // +0x010
    char _pad014[0x04];                      // +0x014
    int m_followMode;                        // +0x018
    EVec3 m_pos;                             // +0x01C (x=+0x1C, y=+0x20, z=+0x24)
    char _pad028[0x04];                      // +0x028
    int m_animState;                         // +0x02C
    float m_animDirection;                   // +0x030
    char _pad034[0x7C];                      // +0x034
    int m_desiredAnimState;                  // +0x0B0
    char _pad0B4[0x04];                      // +0x0B4
    float m_cameraZoomRatio;                 // +0x0B8
    char _pad0BC[0x0C];                      // +0x0BC
    int m_skillTrackIndex;                   // +0x0C8
    char _pad0CC[0x04];                      // +0x0CC
    float m_blendTime;                       // +0x0D0
    AnimRef* m_currentAnimRef;               // +0x0D4
    char _pad0D8[0x04];                      // +0x0D8
    int m_prevTick;                          // +0x0DC
    int m_currentTick;                       // +0x0E0
    char _pad0E4[0x18];                      // +0x0E4
    float m_timeMultiplier;                  // +0x0FC
    float m_desiredTimeMultiplier;           // +0x100
    float m_pauseMultiplier;                 // +0x104
    char _pad108[0x18];                      // +0x108
    int m_idleInitialized;                   // +0x120
    char _pad124[0x0C];                      // +0x124
    int m_lastCostume;                       // +0x130
    char _pad134[0x4C];                      // +0x134
    EHeadOrient m_headOrient;                // +0x180
    char _pad1F8[0x400];                     // +0x1F8
    s8 m_portalMode;                         // +0x5F8
    char _pad5F9[0x0B];                      // +0x5F9
    CasSimDescriptionS2C* m_pNormalSimDescription; // +0x604
    char _pad608[0x04];                      // +0x608
    int m_boneIndices[4];                    // +0x60C
    u32 m_flags;                             // +0x61C
    AwarenessManager m_awarenessMgr;         // +0x620
    cXObject* m_pAwareOfObject;              // +0x63C
    char _pad640[0x10];                      // +0x640
    float m_savedPauseMultiplier;            // +0x650

    // Static members
    static int m_pendingCount;
    static float* m_DualArmCarryIndexArray;

    // Constructor / Destructor
    SAnimator2();
    ~SAnimator2();

    // Stubs
    void Render(int arg);
    void ResetSuits();
    void SetAnimDisplacements(float dx, float dy, float dz);
    void ResetCensorship();
    void SetPixelated(int pixelated);
    void AlignCensorToCamera(EVec3& a, EVec3& b, E3DWindow* wnd);

    // Initialization
    void Initialize(cXPerson* person);
    void InitStaticAnimationElements();
    void SetIsRaining(bool raining);

    // Frame update
    void Update();
    void adjustAnimationPlayRates();
    void Reset();
    void SnapToGrid();
    void ForceLocation();

    // Animation state
    void TryChangeSuit();
    void checkParticleCleanup();
    void updateFreeMoveState();
    void updateMovementState();
    void moveAnimation();
    void awarenessMove();

    // Skill / idle animation
    void resolveSkillForPrimitive(StackElem* elem, IdleAnimateParam* param, AnimRef*& outRef);
    void resolveSkillForPrimitive(StackElem* elem, AnimateNewParam* param, AnimRef*& outRef);
    void loadSkillAnim(AnimRef* ref);
    int IsSkillIdleAnimRunning();
    void TryIdleAnimate(StackElem* elem, IdleAnimateParam* param);
    void SelectAlgorithmicIdle(AnimRef*& outRef);
    void stopCurAnim(bool resetBlend);
    void startSkill(AnimRef* ref, bool flag, u32 param);
    void TryAnimate(StackElem* elem, AnimateNewParam* param);
    void SetSkillName(AnimRef* ref);

    // Carry animation
    void lockHandsUpCarryNodes();
    void lockCarryArmNodes(float* factors, EACTrack* track);
    void lockCarryArmNodes(float* factors, int trackFlags);
    void updateCarryAnimation();
    void startCarry();
    void stopCarry();

    // Follow / routing
    void BeginFollow(float arg);
    void FollowOneStep();
    void EndFollow();
    int IsFollowing();
    int IsInterruptable();
    float getPersonX();
    float getPersonY();
    void endFollowDone();
    void followStandToTurnUpdate(float& a, float& b, float c);
    void followSidestepUpdate(float& a, float& b, float c);
    void followMiddleUpdate(float& a, float& b, float c);
    void followMoveToTurnUpdate(float& a, float& b, float c);
    void followDoneUpdate(float& a, float& b, float c);
    void endMoveAnimation();
    void setFollowMiddle();
    void setFollowEnd();
    void setFollowDone();
    void setFirstFollowMode(eFollowMode mode);
    void setMovementVelocityFromAnimation();
    void setAwarenessFollowMiddle();
    void setAwarenessFollowEnd();
    void exitAwarenessFollow();

    // Recon
    void ReconStream(ReconBuffer* buf, int dir);
    void DequeueAnimEvent(int* outEvent);

    // Censorship
    void DrawCensor(ERC* rc);
    void updateCensor();

    // Props / dress
    void getCorrectId(PropRef* ref);
    void Dress(PropRef* ref);
    void AddProp(u32 propId, bool flag);
    void RemoveProp(u32 propId);
    void PreloadDress(PropRef* ref);
    void Undress(PropRef* ref);
    int removeCostume();
    void removeAllProps();

    // Particle effects
    void convertAnimationFormatToEngineFormat(EVec3& inPos, EVec3& outPos);
    void GetBonePosAndDirForParticle(u32 boneIdx, EMat4& outMat);
    int StartParticleEffectFromEdithPrimitive(u32 effectId, u32 boneId);
    void AttachParticleEffect(u32 effectId, u32 boneId, int param);
    void DetachParticleEffect(u32 effectId, u32 boneId, int param);
    void procBoneParticleEvt(AnimParticleData* data, bool flag);
    void _handleParticleEvent(REffectsAttachment* attachment);
    void PreloadBoneParticleEvent(REffectsAttachment* attachment);
    void cleanupParticles(TRedBlackTree<u32, TRedBlackTree<u32, EBoneParticle*>*>* tree);
    void cleanupParticlesImmediate(TRedBlackTree<u32, TRedBlackTree<u32, EBoneParticle*>*>* tree);
    void cleanupParticlesDelayed(TRedBlackTree<u32, TRedBlackTree<u32, EBoneParticle*>*>* tree);
    void updateParticles();

    // Events
    void processEvents(AnimRef& ref, int a, int b, bool c, bool d);
    void eventHandler(EAnimNote& note, int param);
    void footstepEvent(char* name);
    void PreloadEvents(AnimRef* ref);
    void playRumble(RumbleDataElement* data);
    void playRumble(char* name);
    void triggerCameraBloom(char* name);
    void triggerCameraBloom(CameraBloomDataElement* data);
    void triggerCameraBlur(char* name);
    void triggerCameraBlur(CameraBlurDataElement* data);
    void playFootprint(char* name);
    void getFootSound(char* name);
    void GetFootSound(CTilePt& pt, char* name);

    // Position / direction
    void GetEngineFormatPos();
    float getDeltaDirFromDesiredDir(float dir);
    void initShuffleRotation(float dir);
    void rotateAnimation(float a, float b, float c);
    void setPersonDirection(float dir);
    float getPersonDirection();
    void setAnimationDirectionToPersonDirection();
    void GetCarryHandPosAndDir(EVec3& pos, EVec3& dir, EMat4& mat);
    void GetBonePos(int boneIdx, EVec3& outPos);
    int PropsHaveAlpha();
    void DrawProps(ERC* rc, bool flag, EShader* shader);
    void DrawPropsShadow(ERC* rc);

    // Movement
    void SetNextStateFromCompletedTurn();
    float GetTurnRate();
    void GetMovementVelocityFromStyle(eWalkRunStyle style);
    void moveTowardsDestination(float& dist, EVec2& dest);
    void getUseSpeed(float a, float b, float c, float d);
    void EnableWalkFade(u32& flags, float a, float b, float c);
    void advanceAlongNode(float& dist);
    void sidestepAlongNode(float& dist);
    void getDesiredDir();
    void CheckCollision(EVec2& a, EVec2& b);

    // Animation handlers
    void handleWalkRunAnimation();
    void handleSidestepAnimation();
    void handleSkillIdleAnimation();
    void handleIdleAnimation();
    void handleImpatientIdleAnimation();
    void handleRunStopAnimation();
    void handleTurnAnimation();
    void handleFreeMoveWalkRunAnimation();
    void handleMoodAnimations();
    void positionCharacter(EMat4* mat);

    // Render
    void updateRenderAnimation();
    void updateRenderModels();

    // Costume / model
    void wearNormal();
    void setJobModel();
    void GetCostumeName(int outfit);
    void setNewModel(char* name, bool a, bool b);
    void RestoreNonCostumeRelatedSimDescriptionItems(CasSimDescriptionS2C* a, CasSimDescriptionS2C* b, bool c);

    // State queries / setters
    void SetIdleInitialized(bool init);
    cXObject* GetAwareOfObject();
    void SetAwareOfObject(cXObject* obj);
    void SetAwareOfObjectKilled(cXObject* obj);
    void ClearAwareOfObject(cXObject* obj);
    void SetPlayerControl(bool control);
    void SetPauseMultiplier(float mult);
    EVec3* GetPos();
    float GetRealDir();
    float GetTimeMultiplier();
    cXPerson* GetPerson();
    ESim* GetSim();
    int GetAnimState();
    int GetFollowMode();
    int GetPortalMode();
    void SetDesiredAnimState(eAnimState state);
    void SetCameraZoomRatio(float ratio);
    bool GetPlayerControl();
    EHeadOrient* GetHeadOrient();
    CasSimDescriptionS2C* GetNormalSimDescription() const;
    void SetNormalSimDescription(CasSimDescriptionS2C* desc);
    bool IsStalled();
    float GetPauseMultiplier();
    void SetBoneIndex(int slot, int index);
    void SetRightHandBoneIndex(int index);
    void SetHeadBoneIndex(int index);
    void SetPelvisBoneIndex(int index);
    void SetTorsoBoneIndex(int index);
    int GetBoneIndex(int slot);
    int GetRightHandBoneIndex();
    int GetHeadBoneIndex();
    int GetPelvisBoneIndex();
    int GetTorsoBoneIndex();
    bool IsRouting();
    bool IsDirectControlEnabled();
    int GetLastCostume();
    void SetLastCostume(int costume);
    void UpdateAnimationValidity();
    void updateDiagnosticDisplay();

    // Memory management
    void* operator new(u32 size);
    void operator delete(void* ptr);

    // Idle / optional anims
    void selectIdleOverlay();
    void stopIdleOverlay();
    void selectRandomIdle();
    void LoadOptionalIdleAnim();
    void UnloadPendingLongIdleAnim();
    void UnloadOptionalIdleAnim();
    void clearImpatientIdleAnimation();
    void LoadDCOptionalMotionAnims();
    void UnloadDCOptionalMotionAnims();
    void LoadSMOptionalMotionAnims();
    void UnloadSMOptionalMotionAnims();
    void CheckOptionalMotionAnimStatusOnStateChange(eAnimState state);
    void StartDefaultIdle();
    void isAnimationDone();
    int shouldUseLowMotiveWalk();
    void shouldUseLowMotiveIdle();
    int IsSimulatorControlled();
    void setAwarenessFollowStart(float arg);

    // Movement state
    void determineFirstFollowMode(TileList* list);
    void determineWalkRunStyle(float speed);
    void updateDesiredAndDeltaDir(float& desired, float& delta);
    void defaultVelocity(int arg);
    void getAnimDuration(ERAnim* anim);
    void setSideStepSpeedFromAnimation(AnimRef* ref);
    void setRotationRateFromShuffleDir(int dir, float rate);
    void getTurnSkillID(AnimRef*& outRef, int param);
    void getShuffleDirFromDeltaDir(float delta);
    void getIsLeftFootUp();
    void setAnimationState();
    void getSidestepSkillIDs(AnimRef*& outRef1, AnimRef*& outRef2, float param);
    void UpdateNPCAutoRunState();
    void UpdateNPCAutoRun();
    void getSidestepIntensity();
    void initSidestep();
    void initWalkRun();
    void initWalkRunFadeOut();
    void skillIsIdle();
    void ShouldEndSkillTrack();
    void StartAutoRun(float speed);
    void EndAutoRun();
    void getWalkRunSkillID(AnimRef*& outRef);
    void getIndexOfPropID(u32 propId);
    void SetDesiredFacing(float facing);
    void clearSuspendedCarry();
    void SetIdleAnimPlaybackParameters(EACTrack* track);
    void DetachMonitoredTrack();
    void UpdatePortalMode();
};

// ============================================================================
// Free functions in sanimator2.obj
// ============================================================================
void SAnimatorNullFunc(...);

// GetMotiveMag is a free function
float GetMotiveMag(float motive);

#endif // SANIMATOR2_H
