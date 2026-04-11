// EAnimController.h - Reverse-engineered struct layout
// Based on analysis of matched functions and asm_decomp

#pragma once

#include "types.h"

// Forward declarations
class EACTrack;
class EACNodeState;
class EACTrackStreams;
class EACEventRange;
class EAnimNodeDataPos;
class ERAnim;
class ERCharacter;
class ERC;
class ERModel;
class ECharacterNode;
class EMat4;
class EVec3;
class EBound3;

// Animation track flags
enum eTrackFlags {
    // Track flag values used in EAnimController
};

// Animated object types
enum eAnimatedObjectType {
    // Object type values
};

// EAnimController - Animation controller for characters
// Total size: approximately 0x400+ bytes (based on field offsets in asm)
class EAnimController {
public:
    /* 0x000 */ void* m_vtable;           // Vtable pointer
    /* 0x004 */ void* m_field_004;
    /* 0x008 */ EACTrack* m_tracks;       // Array of animation tracks
    /* 0x00C */ int m_numTracks;
    /* 0x010 */ int m_maxTracks;
    /* 0x014 */ void* m_field_014;
    /* 0x018 */ eAnimatedObjectType m_objectType;
    /* 0x01C */ unsigned int m_field_01C;
    
    // Node state data
    /* 0x020 */ EACNodeState* m_nodeStates;
    /* 0x024 */ int m_numNodes;
    /* 0x028 */ int m_maxNodes;
    
    // Matrix data
    /* 0x02C */ EMat4* m_matrices;
    /* 0x030 */ int m_numMatrices;
    /* 0x034 */ void* m_field_034;
    
    // Animation state
    /* 0x038 */ float m_animTime;
    /* 0x03C */ float m_animSpeed;
    /* 0x040 */ float m_blendFactor;
    /* 0x044 */ int m_field_044;
    
    // Track intensity/blend data
    /* 0x048 */ float m_trackIntensity;
    /* 0x04C */ float m_trackBlend;
    /* 0x050 */ float m_blendTarget;
    
    // Flags
    /* 0x054 */ unsigned int m_flags;
    /* 0x058 */ int m_isSuspended;
    /* 0x05C */ int m_isActive;
    
    // Event ranges
    /* 0x060 */ void* m_eventRanges;
    /* 0x064 */ int m_numEventRanges;
    
    // ... more fields up to 0x400+

public:
    // Constructors/Destructor
    EAnimController(void);                // 0x802E7A10
    ~EAnimController(void);               // 0x802E7AA0
    
    // Initialization
    void Init(unsigned int, eAnimatedObjectType, unsigned int);
    void Init(char *, eAnimatedObjectType, unsigned int);
    
    // Allocation/Deallocation
    void Deallocate(void);
    void DeallocateNodes(void);
    void AllocMatrices(void);
    void Shutdown(void);                  // 0x802E7F40
    
    // Track management
    int IsTrackValid(eTrackFlags);
    void SuspendTrack(eTrackFlags);
    void ResumeTrack(eTrackFlags);
    void StopTrack(eTrackFlags);
    void StopAllTracks(void);
    void DeactivateTrack(EACTrack *);
    void CreateStreams(EACTrack *);
    void DestroyStreams(EACTrack *);
    void TransferTrack(eTrackFlags, eTrackFlags);
    
    EACTrack* GetFirstRelevantTrack(void);
    
    // Animation playback
    void SetTrackAnim(eTrackFlags, unsigned int, int, float, EACTrack **);
    void SetTrackAnim(eTrackFlags, char *);
    void SetTrackAnimId(eTrackFlags, unsigned int);
    void GetTrackAnimId(eTrackFlags);
    void GetTrackAnimName(eTrackFlags);
    
    // Track control
    void SetTrackIntensity(eTrackFlags, float);
    void SetTrackIntensity(EACTrack *, float, bool);
    void SetAllTrackIntensities(float);
    void GetTrackIntensity(eTrackFlags);
    void BlendTrackIntensity(EACTrack *);
    
    // Blending
    void SetTrackBlend(eTrackFlags, float);
    void SetTrackBlend(EACTrack *, float);
    void GetTrackBlendTarget(eTrackFlags);
    void SetTrackBlendSmooth(eTrackFlags, float, float, float);
    void SetTrackBlendSmooth(EACTrack *, float, float, float);
    void SetTrackBlendHermiteSafe(eTrackFlags, float, float, float, float);  // 0x802EE4D8
    void SetTrackBlendHermite(EACTrack *, float, float, float, float);
    void SetTrackBlendHermite(eTrackFlags, float, float, float, float);
    void BlendAllOutgoingTracks(float, float, bool);
    
    // Phase/position
    void SetTrackPhase(eTrackFlags, float);
    void SetTrackPhaseLock(EACTrack *, EACTrack *, float);
    void SetTrackFrame(eTrackFlags, float, bool);
    void SetTrackPos(EACTrack *, float, bool);
    void GetTrackFrame(eTrackFlags);
    void GetTrackFrameCount(eTrackFlags);
    void GetTrackPos(eTrackFlags);
    void GetTrackSpeed(eTrackFlags);
    void SetTrackBlendFactors(eTrackFlags, float *);
    void RestartTrack(eTrackFlags);
    
    // Animation queries
    void GetAnimTrans(eTrackFlags, EVec3 &);
    void GetAnimTranslate(eTrackFlags, EVec3 &, EVec3 &);
    void GetAnimTime(eTrackFlags);
    void GetAnimVelocity(eTrackFlags, EVec3 &);
    void GetSlavePos(EACTrack *, EACTrack *);
    
    // Procedural tracks
    void SetProceduralTrack(eTrackFlags, 
        void (*)(unsigned int, EACTrack *, ERCharacter *, EVec3 &, EVec3 &), 
        void (*)(unsigned int, EACTrack *, EMat4 &, ERCharacter *, EACNodeState *), 
        unsigned int);
    
    // Update/Processing
    void Update(EVec3 *, EVec3 *, EVec3);
    void UpdateTrack(EACTrack *, EVec3 &, EVec3 &, TNodeList<EACEventRange *> &);
    void ProcessEvents(TNodeList<EACEventRange *> &, bool);
    void AddEventRange(TNodeList<EACEventRange *> &, EACTrack *, float, float);
    
    // Animation computation
    void AnimateTrack(EACTrack *, EACNodeState *, EMat4 *);
    void Animate(EACTrack *, EACNodeState *);
    void AnimateSpecial(ERAnim *, float, EACTrackStreams *, EACNodeState *, EAnimNodeDataPos *, EACNodeState &);
    void Compute(EMat4 &, int);
    void ComputeInverse(EMat4 &, int);
    void ComputeMatrices(EMat4 &);
    void CalcMatrix(EMat4 &, ECharacterNode &, EACNodeState &, EMat4 &);
    void PostMultNodeAndDescendents(int, EMat4 &);
    void PreMultNodeAndDescendents(int, EMat4 &);
    
    // Blending
    void Blend(float, EACNodeState &, EACNodeState &);
    void Layer(float, EACNodeState &, EACNodeState &);
    void BlendNodeArrays(EACTrack *, EACNodeState *, EACNodeState *);
    void FixAccumulationForRootNode(EACTrack *, EACNodeState &);
    
    // Bounds/Orientation
    void CalcOrientMatrix(EVec3 &, EVec3 &, EVec3 &, EMat4 &);
    void CalcTightBoundBox(EMat4 &, EBound3 &, bool *);
    
    // Static blend tracks
    void SetStaticBlendTrackAnim(eTrackFlags, unsigned int, float, int, float, EACTrack *);
};

// EACTrack - Animation track structure
struct EACTrack {
    /* 0x000 */ void* m_vtable;
    /* 0x004 */ unsigned int m_trackId;
    /* 0x008 */ float m_intensity;
    /* 0x00C */ float m_blend;
    /* 0x010 */ float m_targetBlend;
    /* 0x014 */ float m_phase;
    /* 0x018 */ float m_speed;
    /* 0x01C */ float m_frame;
    /* 0x020 */ float m_frameCount;
    /* 0x024 */ ERAnim* m_anim;
    /* 0x028 */ EACTrackStreams* m_streams;
    /* 0x02C */ eTrackFlags m_flags;
    /* 0x030 */ int m_isActive;
    /* 0x034 */ int m_isSuspended;
    /* 0x038 */ void* m_proceduralCallback1;
    /* 0x03C */ void* m_proceduralCallback2;
    /* 0x040 */ unsigned int m_proceduralUserData;
    // ... more fields
};

// EACNodeState - Per-node animation state
struct EACNodeState {
    EMat4 m_matrix;
    EVec3 m_translation;
    EVec3 m_scale;
    float m_rotation[4];  // Quaternion
    int m_flags;
    // ... more fields
};

// EACTrackStreams - Stream data for animation blending
struct EACTrackStreams {
    void* m_data;
    int m_numStreams;
    // ...
};

// EACEventRange - Animation event range
struct EACEventRange {
    float m_startTime;
    float m_endTime;
    int m_eventId;
    EACTrack* m_track;
    // ...
};

// EAnimNodeDataPos - Node data position
struct EAnimNodeDataPos {
    int m_nodeIndex;
    int m_dataOffset;
    // ...
};
