// SAnimator2.h - Reverse-engineered struct layout
// Based on analysis of matched functions in src/matched/agent/

#pragma once

#include "types.h"

// Forward declarations
class cXPerson;
class ESim;
class AnimRef;
class IdleAnimateParam;
class AnimateNewParam;
class PropRef;
class StackElem;
class ReconBuffer;
class EVec2;
class EVec3;
class EMat4;
class ERC;
class EShader;
class EACTrack;
class AnimParticleData;
class CasSimDescriptionS2C;

// SAnimator2 - Animation controller for Sims
// Total size: approximately 0x700+ bytes based on field offsets
class SAnimator2 {
public:
    /* 0x000 */ void* m_vtable;           // Vtable pointer (standard SN ABI)
    /* 0x004 */ void* m_field_004;
    /* 0x008 */ void* m_animData;         // Pointer to animation data (offset 0x08, used extensively)
    /* 0x00C */ void* m_field_00C;
    /* 0x010 */ int m_field_010;          // Used in IsRouting() - checked against 1
    /* 0x014 */ void* m_field_014;
    /* 0x018 */ int m_field_018;          // Used in updateMovementState - compared to 5
    /* 0x01C */ void* m_field_01C;
    
    // Fields 0x020-0x02B unknown
    /* 0x02C */ int m_field_02C;          // Used in IsDirectControlEnabled - range check (value-9) <= 5
    
    // More fields...
    /* 0x5D0 */ void* m_field_5D0;        // Used in checkParticleCleanup - particle data pointer
    /* 0x5DC */ void* m_field_5DC;        // Used in checkParticleCleanup - particle data pointer 2
    
    // Bone index array
    /* 0x60C */ int m_boneIndex[1];       // Variable array - accessed via index
    
    // State flags at 0x61C
    /* 0x61C */ int m_stateFlags;         // Bit flags: 0x1, 0x40, 0x10000, 0x20000 used
    
    // Awareness/control data at 0x620
    /* 0x620 */ char m_awarenessData[16]; // Used for awarenessSetPlayerControl
    
    // ... more fields

public:
    // Constructors/Destructor
    SAnimator2(void);
    ~SAnimator2(void);
    
    // Initialization
    void Initialize(cXPerson *);
    void InitStaticAnimationElements(void);
    void Reset(void);
    
    // State checks
    int IsRouting(void);                  // 0x800691F4
    int IsDirectControlEnabled(void);     // 0x80069208
    int GetPortalMode(void);              // 0x800690F8
    int GetAwareOfObject(void);           // 0x80068A40
    
    // Bone index accessors
    int GetBoneIndex(int idx);            // 0x800691C4
    void SetBoneIndex(int idx, int val);  // 0x80069194
    
    // Animation control
    void UpdateAnimationValidity(void);   // 0x800689FC
    void SetPlayerControl(int ctrl);      // 0x80068FBC
    void checkParticleCleanup(void);      // 0x8005C87C
    void updateMovementState(void);       // 0x8005CC2C
    void followMoveToTurnUpdate(float &turnAngle, float &desiredDir, float speed);  // 0x8005FEB8
    void followDoneUpdate(float &, float &, float);  // 0x8005FF1C
    
    // Getters
    cXPerson* GetPerson(void);
    ESim* GetSim(void);
    int GetAnimState(void);
    int GetFollowMode(void);
    float GetRealDir(void);
    float GetTimeMultiplier(void);
    
    // Setters
    void SetDesiredAnimState(int);
    void SetIdleInitialized(int);
    
    // Animation methods
    void TryChangeSuit(void);
    void TryIdleAnimate(StackElem *, IdleAnimateParam *);
    void TryAnimate(StackElem *, AnimateNewParam *);
    void SelectAlgorithmicIdle(AnimRef *&);
    void loadSkillAnim(AnimRef *);
    
    // Follow/movement
    void BeginFollow(float);
    void FollowOneStep(void);
    void EndFollow(void);
    void updateFreeMoveState(void);
    void awarenessMove(void);
    void moveAnimation(void);
    void rotateAnimation(float, float, float);
    
    // Prop/costume
    void AddProp(unsigned int, bool);
    void RemoveProp(unsigned int);
    void Dress(PropRef *);
    void Undress(PropRef *);
    void PreloadDress(PropRef *);
    void removeCostume(void);
    int GetLastCostume(void);
    void SetLastCostume(int);
    
    // Idle animations
    void selectRandomIdle(void);
    void handleIdleAnimation(void);
    void handleImpatientIdleAnimation(void);
    void clearImpatientIdleAnimation(void);
    void handleSkillIdleAnimation(void);
    void LoadOptionalIdleAnim(void);
    void UnloadOptionalIdleAnim(void);
    void UnloadPendingLongIdleAnim(void);
    void LoadSMOptionalMotionAnims(void);
    void LoadDCOptionalMotionAnims(void);
    void CheckOptionalMotionAnimStatusOnStateChange(void);  // 0x80064C18
    
    // Rendering
    void updateRenderAnimation(void);
    void updateParticles(void);
    void handleMoodAnimations(void);
    void UpdatePortalMode(void);
    
    // Collision/movement helpers
    void CheckCollision(EVec2 &, EVec2 &);
    void moveTowardsDestination(float &, EVec2 &);
    void getUseSpeed(float, float, float, float);
    void EnableWalkFade(unsigned int &, float, float, float);
    void GetTurnRate(void);
    
    // Recon/streaming
    void ReconStream(ReconBuffer *, int);
    
    // Static helpers
    static void* operator new(size_t);
    static void operator delete(void*);
    
    // Bone/position getters
    void GetBonePosAndDirForParticle(void);
    void AlignCensorToCamera(void);
    void StartParticleEffectFromEdithPrimitive(void);
    void footstepEvent(void);
    
    // Direction/angle
    void setAnimationDirectionToPersonDirection(void);
    void updateDesiredAndDeltaDir(void);
    
    // Sim description
    CasSimDescriptionS2C* GetNormalSimDescription(void);
    void SetNormalSimDescription(CasSimDescriptionS2C*);
    
    // Various bone indices
    int GetRightHandBoneIndex(void);
    int GetHeadBoneIndex(void);
    int GetPelvisBoneIndex(void);
    int GetTorsoBoneIndex(void);
    void SetRightHandBoneIndex(int);
    void SetHeadBoneIndex(int);
    void SetPelvisBoneIndex(int);
    void SetTorsoBoneIndex(int);
    
    // Pause/multiplier
    int GetPauseMultiplier(void);
    void SetIdleAnimPlaybackParameters(void);
};

// Animation data structure (pointed to by m_animData at offset 0x08)
struct SAnimator2_AnimData {
    /* 0x000 */ void* m_field_000;
    /* 0x004 */ void* m_field_004;
    /* 0x008 */ int m_trackIndex;         // Used in UpdateAnimationValidity
    // ...
    /* 0x044 */ int m_field_044;          // Used with trackIndex
    // ...
    /* 0x334 */ int m_flags;              // Bit flags accessed in SetPlayerControl
    // ...
    /* 0x394 */ int m_animationValid;     // Set in UpdateAnimationValidity
};
