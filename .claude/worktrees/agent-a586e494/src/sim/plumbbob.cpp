// plumbbob.cpp - PlumbBob (diamond above Sim's head) small functions
// From: plumbbob.obj
// Small functions (<=64 bytes) decompiled from this object

#include "sim/plumbbob.h"
#include "core/e_vec3.h"

// ============================================================================
// External references
// ============================================================================

// __builtin_delete (0x802d1220)
extern "C" void __builtin_delete(void* ptr);

// PlumbBobModel::SetModel (0x8005b360)
// PlumbBobModel::SetShadow (0x8005b3e0)
// PlumbBob::SetColor (0x8005a348)
// __static_initialization_and_destruction_0 (0x8005b1e4)

// Player color table at 0x804855a0 - array of EVec3[4], stride 12
// kPositiveRepTimer at 0x803d4218 (.sdata2)
// kNegativeRepTimer at 0x803d421c (.sdata2)
// kPulseRate divisor at 0x803d4294 (.sdata2)

// ============================================================================
// PlumbBobStack::Reset(void)
// 0x800597E0 - 12 bytes
// Clears the stack count to 0
// ============================================================================
// li r0,0; stw r0,0(r3); blr
// NON_MATCHING - GCC uses r9 for zero; original uses r0
void PlumbBobStack::Reset(void) {
    m_count = 0;
}

// ============================================================================
// PlumbBob::SetModel(unsigned int)
// 0x8005A2E0 - 52 bytes
// Sets model on the internal PlumbBobModel if it exists
// ============================================================================
// lwz r0,0x164(r3); li r3,0; cmpwi r0,0; beq- skip
// mr r3,r0; bl PlumbBobModel::SetModel
// NON_MATCHING - GCC tail-calls via b instead of bl+ret; different register usage
void PlumbBob::SetModel(unsigned int modelId) {
    if (m_model != 0) {
        ((PlumbBobModel*)m_model)->SetModel(modelId);
    }
}

// ============================================================================
// PlumbBob::SetShadow(unsigned int)
// 0x8005A314 - 52 bytes
// Sets shadow on the internal PlumbBobModel if it exists
// ============================================================================
// lwz r0,0x164(r3); li r3,0; cmpwi r0,0; beq- skip
// mr r3,r0; bl PlumbBobModel::SetShadow
// NON_MATCHING - GCC tail-calls via b instead of bl+ret; different register usage
void PlumbBob::SetShadow(unsigned int shadowId) {
    if (m_model != 0) {
        ((PlumbBobModel*)m_model)->SetShadow(shadowId);
    }
}

// ============================================================================
// PlumbBob::SetPlayerColor(int)
// 0x8005A3BC - 48 bytes
// Sets plumbbob color from a player color lookup table
// ============================================================================
// mulli r0,r4,12; lis r4,0x8048; addi r4,r4,0x55a0
// add r4,r0,r4; bl PlumbBob::SetColor
// NON_MATCHING - requires link-time address of player color table
void PlumbBob::SetPlayerColor(int playerIndex) {
    // Original: SetColor(&playerColorTable[playerIndex])
    // where playerColorTable is at 0x804855a0 with stride 12 (sizeof EVec3)
    // SetColor(this, (EVec3*)(0x804855a0 + playerIndex * 12));
}

// ============================================================================
// PlumbBob::BecomeTransitionIndicator(void)
// 0x8005A45C - 12 bytes
// Sets motion state to 1 (transition indicator mode)
// ============================================================================
// li r0,1; stw r0,0x160(r3); blr
// NON_MATCHING - GCC uses r9; original uses r0
void PlumbBob::BecomeTransitionIndicator(void) {
    m_motionState = STATE_TRANSITION;
}

// ============================================================================
// PlumbBob::ForceMorphToPlumbbob(void)
// 0x8005A468 - 24 bytes
// If not in normal state, forces back to normal state
// ============================================================================
// lwz r0,0x160(r3); cmpwi r0,0; beqlr-
// li r0,0; stw r0,0x160(r3); blr
// NON_MATCHING - GCC uses r9; original uses r0
void PlumbBob::ForceMorphToPlumbbob(void) {
    if (m_motionState == STATE_NORMAL) {
        return;
    }
    m_motionState = STATE_NORMAL;
}

// ============================================================================
// PlumbBob::StartPositiveRepMomentEffect(void)
// 0x8005A480 - 36 bytes
// If in normal state, starts positive reputation effect
// ============================================================================
// lwz r0,0x160(r3); cmpwi r0,0; bnelr-
// lis r9,0x803d; li r0,2; lfs f0,0x4218(r9)
// stw r0,0x160(r3); stfs f0,0x150(r3); blr
// NON_MATCHING - requires .sdata2 constant for timer value
void PlumbBob::StartPositiveRepMomentEffect(void) {
    if (m_motionState != STATE_NORMAL) {
        return;
    }
    m_motionState = STATE_POSITIVE_REP;
    // m_morphTimer = kPositiveRepTimer; // float from .sdata2 at 0x803d4218
}

// ============================================================================
// PlumbBob::StartNegativeRepMomentEffect(void)
// 0x8005A4A4 - 36 bytes
// If in normal state, starts negative reputation effect
// ============================================================================
// lwz r0,0x160(r3); cmpwi r0,0; bnelr-
// lis r9,0x803d; li r0,3; lfs f0,0x421c(r9)
// stw r0,0x160(r3); stfs f0,0x150(r3); blr
// NON_MATCHING - requires .sdata2 constant for timer value
void PlumbBob::StartNegativeRepMomentEffect(void) {
    if (m_motionState != STATE_NORMAL) {
        return;
    }
    m_motionState = STATE_NEGATIVE_REP;
    // m_morphTimer = kNegativeRepTimer; // float from .sdata2 at 0x803d421c
}

// ============================================================================
// PlumbBobParms::Validate(void)
// 0x8005B1AC - 32 bytes
// Calls Calculate to update derived values
// ============================================================================
// stwu r1,-8(r1); mflr r0; stw r0,12(r1)
// bl PlumbBobParms::Calculate
// lwz r0,12(r1); mtlr r0; addi r1,r1,8; blr
void PlumbBobParms::Validate(void) {
    Calculate();
}

// ============================================================================
// PlumbBobParms::Calculate(void)
// 0x8005B1CC - 24 bytes
// Calculates derived rate from pulse period
// ============================================================================
// lis r9,0x803d; lfs f13,0x28(r3); lfs f0,0x4294(r9)
// fdivs f0,f0,f13; stfs f0,0x5c(r3); blr
// NON_MATCHING - requires .sdata2 constant (pulse rate numerator)
void PlumbBobParms::Calculate(void) {
    // m_calculatedRate = kPulseRateNumerator / m_pulsePeriod;
    // where kPulseRateNumerator is from .sdata2 at 0x803d4294
}

// ============================================================================
// PlumbBobParms::~PlumbBobParms(void)
// 0x803A0570 - 52 bytes
// Virtual destructor: sets vtable at +0x60, conditionally deletes
// ============================================================================
// lis r9,0x8046; andi. r0,r4,1; addi r9,r9,-13768
// stw r9,0x60(r3); beq- skip; bl __builtin_delete
// NON_MATCHING - vtable address is a link-time constant
PlumbBobParms::~PlumbBobParms(void) {
    // compiler generates: *(this+0x60) = &PlumbBobParms_vtable;
    // if (__in_charge & 1) __builtin_delete(this);
}

// ============================================================================
// global constructors keyed to PlumbBobStack::Push(PlumbBob *)
// 0x8005B238 - 44 bytes
// Calls __static_initialization_and_destruction_0(1, 0xFFFF)
// ============================================================================
// li r4,0; li r3,1; ori r4,r4,0xFFFF
// bl __static_initialization_and_destruction_0
// NON_MATCHING - compiler-generated static init wrapper
// This is auto-generated by the compiler for global objects in this TU.

// ============================================================================
// global destructors keyed to PlumbBobStack::Push(PlumbBob *)
// 0x8005B264 - 44 bytes
// Calls __static_initialization_and_destruction_0(0, 0xFFFF)
// ============================================================================
// li r4,0; li r3,0; ori r4,r4,0xFFFF
// bl __static_initialization_and_destruction_0
// NON_MATCHING - compiler-generated static destruction wrapper
