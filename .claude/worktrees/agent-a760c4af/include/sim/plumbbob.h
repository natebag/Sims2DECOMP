#ifndef PLUMBBOB_H
#define PLUMBBOB_H

#include "types.h"

// Forward declarations
class ERC;
class EVec3;
struct EVec2;
class ELevelDrawData;
class EOrderTableData;
struct PlumbBobParms;
class PlumbBob;

// ============================================================================
// PlumbBobStack - Stack of PlumbBob pointers
// From: plumbbob.obj
// Layout: { u32 m_count(0x00); ... }
// ============================================================================
class PlumbBobStack {
public:
    void Push(PlumbBob* bob);
    void Pop(PlumbBob* bob);
    void Reset(void);

private:
    u32 m_count;  // 0x00
    // followed by array of PlumbBob pointers
};

// ============================================================================
// PlumbBob - The diamond indicator above a Sim's head
// From: plumbbob.obj
// Large class (~0x168 bytes)
//   +0x150: m_morphTimer (float)
//   +0x160: m_motionState (u32)
//   +0x164: m_model (PlumbBobModel*)
// ============================================================================
class PlumbBob {
public:
    enum PlumbBob_MotionState {
        STATE_NORMAL = 0,
        STATE_TRANSITION = 1,
        STATE_POSITIVE_REP = 2,
        STATE_NEGATIVE_REP = 3,
    };

    PlumbBob(void);
    ~PlumbBob(void);

    static void StartupAll(void);
    static void ShutdownAll(void);
    void Startup(void);
    void Shutdown(void);

    void EnableDraw(bool enable);
    void SetModel(unsigned int modelId);
    void SetShadow(unsigned int shadowId);
    void SetColor(EVec3* color);
    void SetPlayerColor(int playerIndex);
    void SetState(PlumbBob_MotionState state);
    void SetScaleFromTween(int param, float scale);
    void SetParticleDrawState(bool state);
    void SetParticleVisibility(bool visible);

    void BecomeTransitionIndicator(void);
    void ForceMorphToPlumbbob(void);
    void StartPositiveRepMomentEffect(void);
    void StartNegativeRepMomentEffect(void);

    void Update(int dt);
    void Draw(ERC* rc);
    void DrawShadow(ERC* rc);
    void ResetMomentum(bool flag);

    void AddParticleSystem(int type);
    void DestroyParticleSystems(void);
    void UpdateParticleSystem(int dt);

    static void PlumbBobOrderTableCallback(ELevelDrawData& data, EOrderTableData* otData);

private:
    u8 m_data[0x150];         // 0x00 - various fields
    float m_morphTimer;        // 0x150
    u8 m_pad154[0x0C];        // 0x154
    u32 m_motionState;         // 0x160
    void* m_model;             // 0x164 - PlumbBobModel*
};

// ============================================================================
// PlumbBobParms - Parameters/tweakables for plumbbob display
// From: plumbbob.obj
// Layout: ~0x64 bytes
//   +0x28: m_pulsePeriod (float)
//   +0x5C: m_calculatedRate (float)
//   +0x60: vtable (PlumbBobParms virtual table)
// ============================================================================
class PlumbBobParms {
public:
    PlumbBobParms(void);
    virtual ~PlumbBobParms(void);

    void Validate(void);
    void Calculate(void);

private:
    u8 m_data[0x28];          // 0x00
    float m_pulsePeriod;       // 0x28 - period for pulse calculation
    u8 m_pad2C[0x30];         // 0x2C
    float m_calculatedRate;    // 0x5C - calculated from pulsePeriod
    // vtable at 0x60
};

// ============================================================================
// PlumbBobModel - Visual model for the plumbbob
// From: plumbbobmodel.obj (no small functions)
// ============================================================================
class PlumbBobModel {
public:
    PlumbBobModel(void);
    ~PlumbBobModel(void);

    void SetModel(unsigned int modelId);
    void SetShadow(unsigned int shadowId);
    void DrawShadow(ERC* rc);
    void Draw(ERC* rc);
    void GetExtents(EVec2& extents) const;
};

// ============================================================================
// PlumbBobOwner - Entity that owns/manages a plumbbob
// From: plumbbobowner.obj (no small functions)
// ============================================================================
class PlumbBobOwner {
public:
    PlumbBob* GetPlumbBob(int index);
    void GrabPlumbBob(int index, PlumbBobOwner* owner);
    void PushAndGrabPlumbBobOwner(int index, PlumbBobOwner* owner);
    void PopPlumbBobOwner(int index, PlumbBobOwner* owner);
};

#endif // PLUMBBOB_H
