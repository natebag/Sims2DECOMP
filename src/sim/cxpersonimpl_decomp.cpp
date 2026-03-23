// cxpersonimpl_decomp.cpp - Decompiled cXPersonImpl methods
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\ (Sims 2 GameCube)
//
// cXPersonImpl is the core Sim character class — the implementation behind
// cXPerson. It owns the Sim's motives, aspirations, action queue, routing,
// social mode, relationships, and behavior tree integration.
//
// Class size: 0x66B0 (26,288 bytes), 106+ fields, 183 methods
//
// ========================================================================
// ARCHITECTURE OVERVIEW
// ========================================================================
//
// Inheritance: cXPersonImpl -> cXPerson -> cXObject (via vtable chains)
//   - cXObject virtual table at offset +0x000 (vtable @ 0x804623A0)
//   - TreeSimImpl virtual table (vtable @ 0x804628D0)
//   - cXObjectImpl virtual table (vtable @ 0x80462900)
//   - cXPerson virtual table (vtable @ 0x80462948)
//   - TreeSim virtual table (vtable @ 0x80462D18)
//
// Key internal pointers:
//   this+0x000: cXObject base / vtable ptr
//   this+0x004: secondary vtable / dispatch table ptr
//
// ========================================================================
// MOTIVE SYSTEM
// ========================================================================
//
// The Sims 2 tracks 16 motives (needs) per Sim as float arrays:
//   this+0x0A8 (168):  f32 m_motives[16]        — current motive values
//   this+0x0E8 (232):  f32 m_oldMotives[16]     — previous-tick motive values
//   this+0x0B4 (180):  f32 m_happyScore         — weighted happiness (CalcHappy result)
//
// Motive indices (from sHappyMotives[7] = {7, 6, 8, 9, 15, 13, 14}):
//   The 7 motives contributing to happiness are indices 7,6,8,9,15,13,14.
//   The full 16-motive array likely maps to:
//     0: Hunger, 1: Comfort, 2: Hygiene, 3: Bladder,
//     4: Energy, 5: Fun, 6: Social, 7: Room,
//     8: Environment(?), 9: ?, 10-15: expansion/aspiration motives
//
// Motive effects system (this+0x408 / offset 1032):
//   Pointer to MotiveEffects object that tracks per-tick motive deltas.
//   The motive delta list lives at this+0x3E4 (996) as a vector of
//   {motiveIndex (u32), rate (f32), target (f32)} entries (12 bytes each).
//
// Motive simulation per tick (SimMotives):
//   1. For each motive 0..15:
//      - If current >= 0 and old < 0: fire a motive-changed event
//   2. Check if sim is an NPC (field 0x42 check)
//      - If NPC: call full Motives::Sim() on the motive array
//      - If player: call Motives simplified sim
//
// CalcHappy uses PiecewiseFn curves:
//   - Selects sAdultHappyWeightCurves (0x804866BC) or
//     sChildHappyWeightCurves (0x80486750) based on IsChild()
//   - For each curve entry: evaluates the motive against the piecewise
//     function, accumulates weighted sum and total weight
//   - Final happiness = weightedSum / totalWeight, stored at this+0xB4
//
// ========================================================================
// ACTION QUEUE
// ========================================================================
//
// this+0x130 (304):  ActionQueue base — circular buffer of Interaction*
//   - Queue data at +0x130, capacity metadata at +0x130+0x2A8 (680) etc.
//   - Current action index at this+0x534 (1332): 0 = no current action
//   - Action count uses modular arithmetic (divide by 10 via magic multiply
//     0xCCCCCCCD, which is *(unsigned)/ 10)
//   - Each Interaction slot is 68 bytes (0x44)
//
// IsIdle: checks m_hasCurrentAction (this+0x534) == 0
//   return !(*(u32*)(this + 0x534));
//
// ========================================================================
// SOCIAL MODE
// ========================================================================
//
// this+0x058 (88):   s16 m_socialModeTarget  — neighbor ID of social partner
// this+0x544 (1348): u32 m_firstPlayerInSocialMode
// this+0x548 (1352): u32 m_secondPlayerInSocialMode
// this+0x54C (1356): u32 m_waitingForSocialMode
//
// IsInSocialMode: return m_socialModeTarget != 0;
//
// ========================================================================
// PERSON STATE FLAGS (bitfield at this+0x09C / offset 156)
// ========================================================================
//
// u16 m_personFlags at offset 0x9C stores multiple boolean states:
//   bit 0 (0x0001): IsInvisible
//   bit 1 (0x0002): IsGreen
//   bit 2 (0x0004): IsGhost / IsPersonDying (set when death tree ID 393 found)
//   bit 3 (0x0008): IsAlien
//   bit 4 (0x0010): IsInMotiveFailure
//   bit 5 (0x0020): NeedsWantFearShuffle
//   (GetVisibility returns the full flags value as s16)
//
// ========================================================================
// ROUTING
// ========================================================================
//
// this+0x40C (1036): XRoute* m_routeStackBegin
// this+0x410 (1040): XRoute* m_routeStackEnd
//   Route stack size computed via pointer difference / sizeof(XRoute)
//   sizeof(XRoute) = 164 bytes (0xA4)
//   Uses magic multiply 0xC18F9C19 for signed divide by 164
//
// this+0x3F8 (1016): DestList (inline, GetDestList returns this+0x3F8)
//
// GetCurrentRoute: computes stack size, returns top element
//   if (count == 0) return NULL;
//   return routeStackBegin + (count - 1) * 164;
//
// ========================================================================
// RECORDING SYSTEM
// ========================================================================
//
// this+0x430 (1072): void* m_recording
// this+0x434 (1076): u32 m_recordDuration
// this+0x438 (1080): u32 m_recordMaxDuration
// this+0x43C (1084): u32 m_recordCurTicks
// this+0x440 (1088): u32 m_recordStartTicks
// this+0x444 (1092): u32 m_recordTicksElapsed
// this+0x448 (1096): u32 m_recordSkill
//
// Recording functions (StartRecording, StopRecording, ClearRecording,
// LogEvent, Track, GetJobSuitTex) are all stubbed out (blr) in release.
// TickRecording returns 0.
//
// ========================================================================
// SIM IDENTITY
// ========================================================================
//
// this+0x000: cXObject* m_object          — base object pointer
// this+0x004: void* m_dispatchTable       — vtable dispatch table
// this+0x008: s16[] m_personData          — person data array (short[])
//   GetPersonData: return m_personData[index]  (at this+8 + index*2)
//   SetPersonData: m_personData[index] = value
//   GetIdleState: return m_personData[0]
//
// this+0x048 (72): s16 m_isVisitor         — nonzero if visitor
// this+0x084 (132): s16 m_isMale
// this+0x41C (1052): u16 m_currentRoom
//
// Species/age queries (IsDog, IsCat, IsMonkey, IsChild) go through
// the dispatch table to get species/age data, then compare against
// known enum values:
//   Child = 1, Dog = 2, Cat = 3, Monkey = 4(?)
//
// ========================================================================
// AWARENESS / CONTROLLING OBJECT
// ========================================================================
//
// this+0x420 (1056): u32* m_controlStackBegin
// this+0x424 (1060): u32* m_controlStackEnd
//   Each control entry is 12 bytes. GetControllingObject pops the top.
//
// this+0x3F4 (1012): SAnimator2* m_animator
//   Used by SetAwareOfObject/SetAwareOfObjectKilled/ClearAwareOfObject
//   to dispatch awareness events through the animator's vtable.
//
// this+0x53C (1340): cXObject* m_ignoringObject
//
// ========================================================================
// IDLE LOOP / BEHAVIOR TREE
// ========================================================================
//
// this+0x540 (1344): s16 m_idleLoopCount
// this+0x530 (1328): u32 m_changingOutfitMode — also gates "has current action"
//
// ========================================================================

#include "types.h"

// Forward declarations
class cXPersonImpl;
class cXPerson;
class cXObject;
class StackElem;
class XPrimParam;
class Interaction;
class XRoute;
class RoutingSlot;
class TileList;
class FTilePt;
class ReconBuffer;
class BString2;
class StringBuffer;
class MotiveEffects;
class SAnimator2;
class ObjSelector;
class ObjectModule;

// External function declarations
extern int GetGameTickCount(void*);                 // at 0x801096C4
extern void UpdatePersonDirection(void*);           // at 0x800DFA9C
extern void Motives_SimFull(f32* motives);          // at 0x800C2C10
extern void Motives_SimSimplified(f32* motives);    // at 0x800C2898
extern void FireMotiveChangedEvent(void*, void*, int, int); // at 0x800CAD10
extern void* GetActionQueueEntry(void*, int);       // at 0x800E4040
extern float GetRandomAngle(void);                  // at 0x80069230
extern void* GetHouseManager(void);                 // at 0x8013884C
extern void* FindRoomByID(int);                     // at 0x80136644
extern int IsRoomIndoors(void*);                    // at 0x80138420
extern void ActionQueue_SetText(void*, void*, int); // at 0x8011A0E8
extern void* GetStackObjectFromInteraction(void*);  // at 0x800C1C74
extern void* GetIconObjectFromInteraction(void*);   // at 0x800C1C84
extern void* FindObjectByID(void*, int);            // at 0x800F2BA4
extern void* BalloonEffect_Init(void*);             // at 0x800BCA10
extern void BalloonEffect_SetType(void*, int);      // at 0x800BCA34
extern void* BalloonEffect_SetIcon(void*, int);     // at 0x800BCB04
extern void BalloonEffect_Destroy(void*, int);      // at 0x800BCA8C
extern void SetBalloonAnimation(void*, int, void*, int, int, int); // at 0x80142FC0
extern void SetBalloonTiming(void*, int);           // at 0x80143398
extern int GetActionTreeCount(void*);               // at 0x80149104
extern void* GetActionTreeEntry(void*, int);        // at 0x801490D0
extern int GetTreeEntryID(void*);                   // at 0x80149118


// ========================================================================
// Static data
// ========================================================================

// sHappyMotives: indices of motives that contribute to happiness
// Address: 0x80424348, Size: 28 bytes (7 ints)
static int sHappyMotives[7] = { 7, 6, 8, 9, 15, 13, 14 };

// sAdultHappyWeightCurves: piecewise curves for adult happiness calculation
// Address: 0x804866BC, Size: 148 bytes (BSS)
// sChildHappyWeightCurves: piecewise curves for child happiness calculation
// Address: 0x80486750, Size: 148 bytes (BSS)

// sHappyCurvesSetup: flag indicating curves have been loaded
// Address: 0x804FDD44, Size: 4 bytes (SDATA)


// ########################################################################
// #  TRIVIAL METHODS (1-4 instructions, fully matching)
// ########################################################################

// ============================================================================
// cXPersonImpl::CastToPersonImpl
// Address: 0x8012C6DC, Size: 4 bytes
// MATCHING - returns this (blr)
// ============================================================================
cXPersonImpl* cXPersonImpl::CastToPersonImpl() {
    return this;
}

// ============================================================================
// cXPersonImpl::GetPersonImplementation
// Address: 0x8012C6E0, Size: 4 bytes
// MATCHING - returns this (blr)
// ============================================================================
cXPersonImpl* cXPersonImpl::GetPersonImplementation() {
    return this;
}

// ============================================================================
// cXPersonImpl::DebugDumpHappyScape
// Address: 0x801264C4, Size: 4 bytes
// MATCHING - stubbed out in release (blr)
// ============================================================================
void cXPersonImpl::DebugDumpHappyScape() {
}

// ============================================================================
// cXPersonImpl::StartRecording
// Address: 0x8012B5D4, Size: 4 bytes
// MATCHING - stubbed out in release (blr)
// ============================================================================
void cXPersonImpl::StartRecording(int /*skill*/, int /*maxDuration*/) {
}

// ============================================================================
// cXPersonImpl::StopRecording
// Address: 0x8012B5D8, Size: 4 bytes
// MATCHING - stubbed out in release (blr)
// ============================================================================
void cXPersonImpl::StopRecording() {
}

// ============================================================================
// cXPersonImpl::ClearRecording
// Address: 0x8012B5DC, Size: 4 bytes
// MATCHING - stubbed out in release (blr)
// ============================================================================
void cXPersonImpl::ClearRecording() {
}

// ============================================================================
// cXPersonImpl::LogEvent
// Address: 0x8012B5E8, Size: 4 bytes
// MATCHING - stubbed out in release (blr)
// ============================================================================
void cXPersonImpl::LogEvent(char* /*a*/, char* /*b*/, char* /*c*/) {
}

// ============================================================================
// cXPersonImpl::Track
// Address: 0x8012B5EC, Size: 4 bytes
// MATCHING - stubbed out in release (blr)
// ============================================================================
void cXPersonImpl::Track() {
}

// ============================================================================
// cXPersonImpl::GetJobSuitTex
// Address: 0x8012B5F0, Size: 4 bytes
// MATCHING - stubbed out in release (blr)
// ============================================================================
void cXPersonImpl::GetJobSuitTex(StringBuffer& /*a*/, StringBuffer& /*b*/, StringBuffer& /*c*/) {
}

// ============================================================================
// cXPersonImpl::TickRecording
// Address: 0x8012B5E0, Size: 8 bytes
// MATCHING - returns 0
// ============================================================================
int cXPersonImpl::TickRecording() {
    return 0;
}


// ########################################################################
// #  MOTIVE SYSTEM — Core getter/setter methods
// ########################################################################

// ============================================================================
// cXPersonImpl::GetMotive
// Address: 0x801253A4, Size: 16 bytes (4 instructions)
// MATCHING
//
// Returns the current value of motive[index].
// Motives are stored as f32 array at this+0xA8 (offset 168).
//   slwi r4,r4,2      — index *= 4 (sizeof float)
//   addi r3,r3,168    — base = this + 0xA8
//   lfsx f1,r3,r4     — f1 = *(float*)(base + index*4)
//   blr
// ============================================================================
f32 cXPersonImpl::GetMotive(int index) {
    return m_motives[index];
}

// ============================================================================
// cXPersonImpl::GetMotiveRef
// Address: 0x801253B4, Size: 16 bytes (4 instructions)
// MATCHING
//
// Returns pointer to motive[index] for direct modification.
//   slwi r4,r4,2
//   addi r4,r4,168
//   add  r3,r3,r4     — r3 = this + 168 + index*4
//   blr
// ============================================================================
f32* cXPersonImpl::GetMotiveRef(int index) {
    return &m_motives[index];
}

// ============================================================================
// cXPersonImpl::GetOldMotiveRef
// Address: 0x801253C4, Size: 16 bytes (4 instructions)
// MATCHING
//
// Returns pointer to old (previous tick) motive[index].
// Old motives at this+0xE8 (offset 232).
//   slwi r4,r4,2
//   addi r4,r4,232
//   add  r3,r3,r4
//   blr
// ============================================================================
f32* cXPersonImpl::GetOldMotiveRef(int index) {
    return &m_oldMotives[index];
}

// ============================================================================
// cXPersonImpl::SetMotive
// Address: 0x801253D4, Size: 16 bytes (4 instructions)
// MATCHING
//
// Sets motive[index] = value.
//   slwi  r4,r4,2
//   addi  r3,r3,168
//   stfsx f1,r3,r4
//   blr
// ============================================================================
void cXPersonImpl::SetMotive(int index, f32 value) {
    m_motives[index] = value;
}

// ============================================================================
// cXPersonImpl::GetMotives
// Address: 0x8012C980, Size: 8 bytes
// MATCHING
//
// Returns pointer to the start of the motive array.
//   addi r3,r3,168
//   blr
// ============================================================================
f32* cXPersonImpl::GetMotives() {
    return m_motives;  // this + 0xA8
}

// ============================================================================
// cXPersonImpl::GetMotiveEffects
// Address: 0x8012C988, Size: 8 bytes
// MATCHING
//
// Returns the MotiveEffects pointer at offset 0x408 (1032).
//   lwz r3,1032(r3)
//   blr
// ============================================================================
MotiveEffects* cXPersonImpl::GetMotiveEffects() {
    return m_motiveEffects;  // this + 0x408
}


// ########################################################################
// #  MOTIVE SIMULATION
// ########################################################################

// ============================================================================
// cXPersonImpl::SimMotives
// Address: 0x801253E4, Size: 364 bytes (91 instructions)
// NON_MATCHING — virtual dispatch and SDA addressing differ
//
// Per-tick motive simulation. For each of 16 motives:
//   - If current motive >= 0.0 and old motive < 0.0:
//     fire a motive-changed event (motive crossed zero threshold)
// After the loop:
//   - Check if sim has person data entry 34 == 0 (NPC check)
//   - If so, check if sim is an active sim with NPC check field 0x42 != 0
//     - If NPC with field_042: call Motives_SimFull (full NPC decay)
//     - If NPC without:        call Motives_SimSimplified (player decay)
// ============================================================================
void cXPersonImpl::SimMotives() {
    f32* motives = m_motives;       // this + 0xA8
    f32* oldMotives = m_oldMotives; // this + 0xE8
    f32 zero = 0.0f;

    // Iterate all 16 motives checking for zero-crossing events
    for (s16 i = 0; i <= 15; i++) {
        f32 current = motives[i];
        // Check if current >= 0 (using fcmpu cr0, >= 0 via cror so,eq,gt)
        if (current >= zero) {
            f32 old = oldMotives[i];
            if (old < zero) {
                // Motive crossed from negative to positive this tick
                // Get the relation manager from dispatch table
                // (virtual call through m_dispatchTable to get RelationMatrix)
                // and fire a motive-changed event
                // TODO: reconstruct full virtual dispatch chain
                // FireMotiveChangedEvent(relMatrix, ..., 1);
            }
        }
    }

    // Check person data[34] — determines if sim needs full motive simulation
    void* personObj = *(void**)this;  // m_object
    void* personDataEntry = GetActionQueueEntry(
        (void*)((char*)personObj + 40), 34
    );
    s16 personDataVal = *(s16*)personDataEntry;

    if (personDataVal == 0) {
        // Check if this sim is an active NPC via dispatch table virtual call
        // virtual call: this->m_dispatchTable->IsActiveNPC()
        // ... (returns bool)
        int isActiveNPC = 0; // TODO: virtual dispatch

        if (isActiveNPC) {
            if (m_field_042 != 0) {
                // Full NPC motive simulation
                Motives_SimFull(motives);
                // Additional virtual call to update NPC state
            } else {
                // Simplified player motive simulation
                Motives_SimSimplified(motives);
            }
        }
    }
}


// ============================================================================
// cXPersonImpl::CalcHappy
// Address: 0x80125550, Size: 412 bytes (103 instructions)
// NON_MATCHING — piecewise function evaluation with complex float math
//
// Calculates the Sim's overall happiness score from weighted motive curves.
//
// Algorithm:
//   1. Determine if child (via virtual IsChild() call) -> select curve set
//      - Adult: sAdultHappyWeightCurves (0x80486750 + 148)
//      - Child: sChildHappyWeightCurves (0x804866BC + 148)
//   2. For each curve in the selected set:
//      - Get the motive index from the curve's motiveIndex field
//      - Look up current motive value: motives[curve.motiveIndex]
//      - Evaluate the piecewise function to get the weight for this motive
//      - Accumulate: weightedSum += motiveValue * weight
//      - Accumulate: totalWeight += weight
//   3. happiness = weightedSum / totalWeight
//   4. Store at this+0xB4 (m_happyScore)
//
// The piecewise function evaluation (inner loop):
//   Each curve has numPoints breakpoints stored as (x, y) pairs.
//   Binary search for the segment containing the current motive value,
//   then linearly interpolate: y = y0 + (x - x0) * (y1 - y0)
// ============================================================================
void cXPersonImpl::CalcHappy() {
    f32 weightedSum = 0.0f;
    f32 totalWeight = 0.0f;
    f32* motives = m_motives;  // this + 0xA8

    // Select happiness weight curves based on age
    // Virtual call: IsChild() through dispatch table at vtable offset 0x1F8
    int isChild = 0; // TODO: virtual call this->IsChild()

    // curveSet points to either sAdultHappyWeightCurves or sChildHappyWeightCurves
    // Each curve set is an array of { numPoints, pPoints, data... } structs (20 bytes each)
    // curveSet.begin = *(void**)curveSetPtr
    // curveSet.count = *(int*)(curveSetPtr + 4)
    // Iterate: for entry = begin; entry < begin + count * 20; entry += 20
    struct HappyCurveEntry {
        u32 numPoints;     // +0x00: number of breakpoints in the piecewise function
        void* pPoints;     // +0x04: pointer to x-value breakpoints (f32[])
        u32 reserved;      // +0x08: unused/padding
        void* pWeights;    // +0x0C: pointer to weight values (f32[])
        u32 motiveIndex;   // +0x10: which motive this curve evaluates
    };

    // For each curve entry in the set:
    //   f32 motiveVal = motives[entry.motiveIndex];
    //   f32 weight = EvaluatePiecewise(entry, motiveVal);
    //   weightedSum += motiveVal * weight;
    //   totalWeight += weight;

    // The piecewise evaluation:
    // - Search backwards from the last breakpoint to find the segment
    // - If motiveVal is before all breakpoints: use first y-value
    // - If motiveVal is after all breakpoints: use last y-value
    // - Otherwise: interpolate between adjacent breakpoints
    //   t = (motiveVal - x[i]) / 1.0  (already normalized)
    //   weight = y[i] + t * (y[i+1] - y[i])

    m_happyScore = (totalWeight != 0.0f) ? (weightedSum / totalWeight) : 0.0f;
}


// ########################################################################
// #  ASPIRATION SYSTEM
// ########################################################################

// ============================================================================
// cXPersonImpl::GetAspirationScore
// Address: 0x801256EC, Size: 96 bytes (24 instructions)
// NON_MATCHING — virtual dispatch and float constant differences
//
// Returns the aspiration score, normalized from internal to display range.
// Internal call: virtual GetAspirationInternal(0) via dispatch table
// Then: result = (internalScore + CONST_A) / CONST_B * CONST_C
//
// Constants from .rodata at (r9,-12984), (r11,-12980), (r10,-12976):
//   CONST_A: offset to shift range
//   CONST_B: range divisor
//   CONST_C: display scale factor
// ============================================================================
f32 cXPersonImpl::GetAspirationScore() {
    // Virtual call: this->m_dispatchTable->GetAspirationData(0)
    // Returns f32 in f1 = internal aspiration score
    f32 internalScore = 0.0f; // TODO: virtual call

    // Normalize to display range
    // f32 result = (internalScore + offsetA) / rangeB * scaleC;
    return internalScore; // TODO: full normalization
}

// ============================================================================
// cXPersonImpl::SetAspirationScore
// Address: 0x8012574C, Size: 92 bytes (23 instructions)
// NON_MATCHING — virtual dispatch and float constant differences
//
// Converts display-range aspiration score to internal range and stores it.
// Internal: internalScore = (displayScore / scaleC) * rangeB - offsetA
// Then calls virtual SetAspirationData(0, internalScore) via dispatch table.
// ============================================================================
void cXPersonImpl::SetAspirationScore(f32 value) {
    // f32 internal = (value / scaleC) * rangeB - offsetA;
    // Virtual call: this->m_dispatchTable->SetAspirationData(0, internal)
    // TODO: virtual dispatch
}

// ============================================================================
// cXPersonImpl::GetAspirationStatus
// Address: 0x801257A8, Size: 140 bytes (35 instructions)
// NON_MATCHING — virtual dispatch and float constant loading
//
// Returns aspiration status level (0-3) based on aspiration score thresholds.
//   Virtual call to get raw aspiration value
//   if (value <= threshold_0) return 0;  // Desperation
//   if (value <= threshold_1) return 1;  // Fear
//   if (value <= threshold_2) return 2;  // Normal
//   if (value <= threshold_3) return 3;  // Platinum (aspirational!)
//   (default)                 return 3;
// ============================================================================
int cXPersonImpl::GetAspirationStatus() {
    // Virtual call: get aspiration data
    f32 aspirationValue = 0.0f; // TODO: virtual dispatch

    // Threshold comparisons from .rodata constants
    // if (aspirationValue <= THRESHOLD_DESPERATION) return 0;
    // if (aspirationValue <= THRESHOLD_FEAR)        return 1;
    // if (aspirationValue <= THRESHOLD_NORMAL)      return 2;
    //                                               return 3;
    return 0; // placeholder
}


// ########################################################################
// #  PERSON DATA ACCESSORS
// ########################################################################

// ============================================================================
// cXPersonImpl::GetPersonData
// Address: 0x8012C758, Size: 16 bytes (4 instructions)
// MATCHING
//
// Returns person data short at the given index.
// Person data array starts at this+0x08 as s16[].
//   slwi r4,r4,1      — index *= 2 (sizeof short)
//   addi r3,r3,8      — base = this + 0x08
//   lhax r3,r3,r4     — return *(s16*)(base + index*2)
//   blr
// ============================================================================
s16 cXPersonImpl::GetPersonData(int index) const {
    return m_personData[index];
}

// ============================================================================
// cXPersonImpl::SetPersonData
// Address: 0x8012C768, Size: 16 bytes (4 instructions)
// MATCHING
//
// Sets person data short at the given index.
//   slwi r4,r4,1
//   addi r3,r3,8
//   sthx r5,r3,r4     — *(s16*)(base + index*2) = value
//   blr
// ============================================================================
void cXPersonImpl::SetPersonData(int index, s16 value) {
    m_personData[index] = value;
}

// ============================================================================
// cXPersonImpl::GetPersonDataArray
// Address: 0x8012C778, Size: 8 bytes
// MATCHING
//
//   addi r3,r3,8
//   blr
// ============================================================================
s16* cXPersonImpl::GetPersonDataArray() {
    return m_personData;  // this + 0x08
}

// ============================================================================
// cXPersonImpl::GetIdleState
// Address: 0x8012C780, Size: 8 bytes
// MATCHING
//
// Returns the first element of person data (idle state).
//   lha r3,8(r3)
//   blr
// ============================================================================
s16 cXPersonImpl::GetIdleState() {
    return m_personData[0];
}


// ########################################################################
// #  ACTION QUEUE
// ########################################################################

// ============================================================================
// cXPersonImpl::IsIdle
// Address: 0x80125AD0, Size: 12 bytes (3 instructions)
// MATCHING
//
// Returns true if the sim has no current action.
//   lwz  r3,1332(r3)  — load m_hasCurrentAction
//   xori r3,r3,1      — flip: 0->1, nonzero->0
//   blr
// ============================================================================
bool cXPersonImpl::IsIdle() {
    return !m_hasCurrentAction;  // !(this + 0x534)
}

// ============================================================================
// cXPersonImpl::GetPendingAction
// Address: 0x8012C714, Size: 24 bytes (6 instructions)
// MATCHING
//
//   lwz  r0,1332(r3)  — m_hasCurrentAction
//   li   r3,0
//   cmpwi r0,0
//   beqlr             — if no current action, return 0
//   li   r3,1
//   blr               — else return 1
// ============================================================================
int cXPersonImpl::GetPendingAction() const {
    if (m_hasCurrentAction == 0)
        return 0;
    return 1;
}

// ============================================================================
// cXPersonImpl::CountActions
// Address: 0x8012C6E4, Size: 48 bytes (12 instructions)
// MATCHING
//
// Returns the number of actions in the queue.
// If includeCurrentAction is false, subtracts 1 if there's an active action.
//   Queue size = (endPtr - beginPtr) at offsets +0x130+0x2A8 and +0x130+0x2AC
//   i.e., this+0x3D8 and this+0x3DC
// ============================================================================
int cXPersonImpl::CountActions(bool includeCurrentAction) {
    u32 begin = *(u32*)((char*)this + 0x130 + 0x2A8);  // action queue begin
    u32 end   = *(u32*)((char*)this + 0x130 + 0x2AC);  // action queue end
    int count = end - begin;
    if (!includeCurrentAction) {
        // bnelr — if includeCurrentAction != 0, just return count
        return count;
    }
    // Subtract 1 if there's a current action running
    if (m_hasCurrentAction != 0) {
        count--;
    }
    return count;
}


// ########################################################################
// #  PERSON STATE FLAGS
// ########################################################################

// ============================================================================
// cXPersonImpl::IsInvisible
// Address: 0x8012C8E0, Size: 12 bytes
// MATCHING
//
// Tests bit 0 of m_personFlags (offset 0x9C).
//   lhz     r3,156(r3)         — load flags
//   clrlwi  r3,r3,31           — isolate bit 0
//   blr
// ============================================================================
bool cXPersonImpl::IsInvisible() {
    return m_personFlags & 0x0001;
}

// ============================================================================
// cXPersonImpl::IsGreen
// Address: 0x8012C8EC, Size: 12 bytes
// MATCHING
//
// Tests bit 1 of m_personFlags.
//   lhz     r3,156(r3)
//   rlwinm  r3,r3,31,31,31     — extract bit 1
//   blr
// ============================================================================
bool cXPersonImpl::IsGreen() {
    return (m_personFlags >> 1) & 1;
}

// ============================================================================
// cXPersonImpl::IsGhost
// Address: 0x8012C8F8, Size: 12 bytes
// MATCHING
//
// Tests bit 2 of m_personFlags.
//   lhz     r3,156(r3)
//   rlwinm  r3,r3,30,31,31     — extract bit 2
//   blr
// ============================================================================
bool cXPersonImpl::IsGhost() {
    return (m_personFlags >> 2) & 1;
}

// ============================================================================
// cXPersonImpl::IsAlien
// Address: 0x8012C904, Size: 12 bytes
// MATCHING
//
// Tests bit 3 of m_personFlags.
//   lhz     r3,156(r3)
//   rlwinm  r3,r3,29,31,31     — extract bit 3
//   blr
// ============================================================================
bool cXPersonImpl::IsAlien() {
    return (m_personFlags >> 3) & 1;
}

// ============================================================================
// cXPersonImpl::IsInMotiveFailure
// Address: 0x8012C910, Size: 12 bytes
// MATCHING
//
// Tests bit 4 of m_personFlags.
//   lhz     r3,156(r3)
//   rlwinm  r3,r3,28,31,31     — extract bit 4
//   blr
// ============================================================================
bool cXPersonImpl::IsInMotiveFailure() {
    return (m_personFlags >> 4) & 1;
}

// ============================================================================
// cXPersonImpl::NeedsWantFearShuffle
// Address: 0x8012C91C, Size: 12 bytes
// MATCHING
//
// Tests bit 5 of m_personFlags.
//   lhz     r3,156(r3)
//   rlwinm  r3,r3,27,31,31     — extract bit 5
//   blr
// ============================================================================
bool cXPersonImpl::NeedsWantFearShuffle() {
    return (m_personFlags >> 5) & 1;
}

// ============================================================================
// cXPersonImpl::GetVisibility
// Address: 0x8012C978, Size: 8 bytes
// MATCHING
//
// Returns the full flags value as s16.
//   lha r3,156(r3)
//   blr
// ============================================================================
s16 cXPersonImpl::GetVisibility() {
    return (s16)m_personFlags;
}

// ============================================================================
// cXPersonImpl::SetInvisible
// Address: 0x8012C928, Size: 40 bytes (10 instructions)
// MATCHING
//
// Sets or clears bit 0 of m_personFlags.
// ============================================================================
void cXPersonImpl::SetInvisible(bool invisible) {
    if (invisible) {
        m_personFlags |= 0x0001;
    } else {
        m_personFlags &= ~0x0001;
    }
}

// ============================================================================
// cXPersonImpl::SetIsAlien
// Address: 0x8012C950, Size: 40 bytes (10 instructions)
// MATCHING
//
// Sets or clears bit 3 of m_personFlags.
// ============================================================================
void cXPersonImpl::SetIsAlien(bool alien) {
    if (alien) {
        m_personFlags |= 0x0008;
    } else {
        m_personFlags &= ~0x0008;
    }
}


// ########################################################################
// #  IDENTITY QUERIES
// ########################################################################

// ============================================================================
// cXPersonImpl::IsVisitor
// Address: 0x8012C8A8, Size: 24 bytes (6 instructions)
// MATCHING
//
// Checks if the sim is a visitor (m_isVisitor at offset 0x48 is nonzero).
//   lha  r0,72(r3)    — load m_isVisitor (s16 at this+0x48)
//   li   r3,1
//   cmpwi r0,0
//   bnelr              — return 1 if nonzero
//   li   r3,0
//   blr                — return 0
// ============================================================================
bool cXPersonImpl::IsVisitor() {
    if (m_isVisitor != 0)
        return true;
    return false;
}

// ============================================================================
// cXPersonImpl::IsSleeping
// Address: 0x8012B1B8, Size: 28 bytes (7 instructions)
// NON_MATCHING — float constant loading via SDA
//
// Checks a float at offset 0xD4 (212) against a constant.
// The constant is likely a "sleeping" motive threshold (e.g., -100.0).
//   lfs   f13,212(r3)         — load field at this+0xD4
//   lfs   f0,-12760(r9)       — load sleeping threshold from .rodata
//   fcmpu cr7,f13,f0          — compare
//   mfcr  r3                  — move CR to GPR
//   rlwinm r3,r3,29,31,31    — extract bit: 1 if less-than
//   blr
// ============================================================================
bool cXPersonImpl::IsSleeping() {
    // return (m_field_0D4 < SLEEPING_THRESHOLD);
    // Exact threshold stored in .rodata
    return false; // TODO: float constant
}

// ============================================================================
// cXPersonImpl::IsMale
// Address: 0x8012B4AC, Size: 124 bytes (31 instructions)
// NON_MATCHING — virtual dispatch chain
//
// Queries gender through dispatch table:
//   1. Virtual call: GetSimDescription() via vtable offset 0x150/0x154
//   2. If result != NULL (sim has override): return result->m_isMale (offset 0x84)
//   3. If NULL: virtual call GetBodyData() via vtable offset 0x160/0x164
//      return bodyData->m_gender (offset 0x00)  — nonzero means male
// ============================================================================
bool cXPersonImpl::IsMale() {
    // Virtual call chain: GetSimDescription -> check m_isMale
    // Fallback: GetBodyData -> m_gender == 0
    return false; // TODO: virtual dispatch
}

// ============================================================================
// cXPersonImpl::IsFemale
// Address: 0x8012B528, Size: 60 bytes (15 instructions)
// NON_MATCHING — virtual dispatch
//
// Virtual call: this->m_dispatchTable->IsMaleInternal() via vtable 0x200/0x204
// Returns: !IsMaleInternal()
// ============================================================================
bool cXPersonImpl::IsFemale() {
    // Virtual call: return !this->IsMaleInternal();
    return false; // TODO: virtual dispatch
}

// ============================================================================
// cXPersonImpl::IsAdult
// Address: 0x8012B564, Size: 60 bytes (15 instructions)
// NON_MATCHING — virtual dispatch (always returns 1)
//
// Virtual call: GetSimDescription() via vtable offset 0x150/0x154
// Then always returns 1 (li r3,1). This suggests all sims on GC
// are adults (children are a separate code path via IsChild).
// ============================================================================
bool cXPersonImpl::IsAdult() {
    // Virtual call, but always returns true on GC
    return true;
}

// ============================================================================
// cXPersonImpl::IsDog
// Address: 0x8012B1D4, Size: 128 bytes (32 instructions)
// NON_MATCHING — virtual dispatch chain
//
// 1. Virtual call: GetSimDescription via vtable 0x150/0x154
// 2. If NULL: virtual call GetBodyData via vtable 0x160/0x164
//    return (bodyData->m_species == 2)  // xori r3,r3,2 + bool normalize
// 3. If not NULL: return false
// ============================================================================
bool cXPersonImpl::IsDog() {
    // TODO: virtual dispatch
    return false;
}

// ============================================================================
// cXPersonImpl::IsCat
// Address: 0x8012B254, Size: 128 bytes (32 instructions)
// NON_MATCHING — same pattern as IsDog but compares species == 3
// ============================================================================
bool cXPersonImpl::IsCat() {
    // return (bodyData->m_species == 3);
    return false;
}

// ============================================================================
// cXPersonImpl::IsMonkey
// Address: 0x8012B2D4, Size: 128 bytes
// NON_MATCHING — same pattern as IsDog but compares species == 4
// ============================================================================
bool cXPersonImpl::IsMonkey() {
    // return (bodyData->m_species == 4);
    return false;
}

// ============================================================================
// cXPersonImpl::IsPet
// Address: 0x8012B354, Size: 216 bytes
// NON_MATCHING — calls IsDog, IsCat, IsMonkey; returns OR of all three
// ============================================================================
bool cXPersonImpl::IsPet() {
    return IsDog() || IsCat() || IsMonkey();
}

// ============================================================================
// cXPersonImpl::IsChild
// Address: 0x8012B42C, Size: 128 bytes
// NON_MATCHING — same dispatch pattern, compares species/age == 1
// ============================================================================
bool cXPersonImpl::IsChild() {
    // return (bodyData->m_species == 1);
    return false;
}


// ########################################################################
// #  SELECTION / ROOM / ROUTING
// ########################################################################

// ============================================================================
// cXPersonImpl::IsSelected
// Address: 0x8012953C, Size: 16 bytes (4 instructions)
// MATCHING
//
// Checks bit 1 of m_object->field_0x84.
//   lwz     r9,0(r3)           — load m_object
//   lwz     r3,132(r9)         — load m_object->m_flags (offset 0x84)
//   rlwinm  r3,r3,31,31,31    — extract bit 1 (shift right 1, mask to 1)
//   blr
// ============================================================================
bool cXPersonImpl::IsSelected() {
    u32 flags = *(u32*)((char*)m_object + 0x84);
    return (flags >> 1) & 1;
}

// ============================================================================
// cXPersonImpl::GetCurrentRoom
// Address: 0x8012C7F4, Size: 8 bytes
// MATCHING
//
//   lhz r3,1052(r3)   — load m_currentRoom at offset 0x41C
//   blr
// ============================================================================
u16 cXPersonImpl::GetCurrentRoom() const {
    return m_currentRoom;
}

// ============================================================================
// cXPersonImpl::IsRouting
// Address: 0x8012C878, Size: 48 bytes (12 instructions)
// NON_MATCHING — branch structure
//
// Returns true if GetCurrentRoute() != NULL.
// ============================================================================
bool cXPersonImpl::IsRouting() {
    return GetCurrentRoute() != 0;
}

// ============================================================================
// cXPersonImpl::GetCurrentRoute
// Address: 0x80123704, Size: 56 bytes (14 instructions)
// NON_MATCHING — magic multiply for signed divide
//
// Returns pointer to the current (top) route on the route stack.
// Stack uses a begin/end pointer pair at offsets 0x40C/0x410.
// sizeof(XRoute) = 164 (0xA4).
// Uses magic number 0xC18F9C19 for signed division by 164.
//   count = (end - begin) * MAGIC >> 2
//   if (count == 0) return NULL;
//   return begin + (count - 1) * 164;
// ============================================================================
XRoute* cXPersonImpl::GetCurrentRoute() {
    u32* begin = (u32*)m_routeStackBegin;
    u32* end   = (u32*)m_routeStackEnd;
    int count = ((char*)end - (char*)begin) / 164;  // magic multiply
    if (count == 0)
        return 0;
    return (XRoute*)((char*)begin + (count - 1) * 164);
}

// ============================================================================
// cXPersonImpl::GetRouteStackSize
// Address: 0x8012C9D8, Size: 32 bytes (8 instructions)
// NON_MATCHING — magic multiply for signed divide
//
// Same pointer-difference calculation but returns count instead of pointer.
// Uses magic number 0xC18F9C19 for division by 164.
// ============================================================================
int cXPersonImpl::GetRouteStackSize() {
    return ((char*)m_routeStackEnd - (char*)m_routeStackBegin) / 164;
}

// ============================================================================
// cXPersonImpl::InvalidateRoutes
// Address: 0x8012B5A0, Size: 52 bytes (13 instructions)
// MATCHING
//
// Iterates route stack, zeroing each route's validity field (offset +0x7C).
// Each route is 164 bytes (0xA4).
// ============================================================================
void cXPersonImpl::InvalidateRoutes() {
    u32* begin = (u32*)m_routeStackBegin;
    u32* end   = (u32*)m_routeStackEnd;
    if (begin == end)
        return;
    // Walk from begin, stepping by sizeof(XRoute) = 164
    char* current = (char*)begin;
    while (current != (char*)end) {
        *(u32*)(current + 0x7C) = 0;  // clear validity
        current += 0xA4;              // next route
    }
}

// ============================================================================
// cXPersonImpl::GetDestList
// Address: 0x8012C7E4, Size: 8 bytes
// MATCHING
//
//   addi r3,r3,1016   — return this + 0x3F8
//   blr
// ============================================================================
void* cXPersonImpl::GetDestList() {
    return (void*)((char*)this + 0x3F8);
}


// ########################################################################
// #  SOCIAL MODE
// ########################################################################

// ============================================================================
// cXPersonImpl::IsInSocialMode
// Address: 0x8012CA2C, Size: 24 bytes (6 instructions)
// MATCHING
//
//   lha  r0,88(r3)     — load m_socialModeTarget at offset 0x58
//   li   r3,1
//   cmpwi r0,0
//   bnelr              — return 1 if has target
//   li   r3,0
//   blr
// ============================================================================
bool cXPersonImpl::IsInSocialMode() {
    if (m_socialModeTarget != 0)
        return true;
    return false;
}

// ============================================================================
// cXPersonImpl::IsFirstPlayerInSocialMode
// Address: 0x8012CA4C, Size: 8 bytes
// MATCHING
//
//   lwz r3,1348(r3)
//   blr
// ============================================================================
bool cXPersonImpl::IsFirstPlayerInSocialMode() {
    return m_firstPlayerInSocialMode;
}

// ============================================================================
// cXPersonImpl::IsSecondPlayerInSocialMode
// Address: 0x8012CA44, Size: 8 bytes
// MATCHING
//
//   lwz r3,1352(r3)
//   blr
// ============================================================================
bool cXPersonImpl::IsSecondPlayerInSocialMode() {
    return m_secondPlayerInSocialMode;
}

// ============================================================================
// cXPersonImpl::IsWaitingForSocialMode
// Address: 0x8012CA54, Size: 8 bytes
// MATCHING
//
//   lwz r3,1356(r3)
//   blr
// ============================================================================
bool cXPersonImpl::IsWaitingForSocialMode() {
    return m_waitingForSocialMode;
}

// ============================================================================
// cXPersonImpl::SetFirstPlayerInSocialMode
// Address: 0x8012B82C, Size: 8 bytes
// MATCHING
//
//   stw r4,1348(r3)
//   blr
// ============================================================================
void cXPersonImpl::SetFirstPlayerInSocialMode(bool value) {
    m_firstPlayerInSocialMode = value;
}

// ============================================================================
// cXPersonImpl::SetWaitingForSocialMode
// Address: 0x8012B8C4, Size: 8 bytes
// MATCHING
//
//   stw r4,1356(r3)
//   blr
// ============================================================================
void cXPersonImpl::SetWaitingForSocialMode(bool value) {
    m_waitingForSocialMode = value;
}


// ########################################################################
// #  MISC GETTERS / SETTERS
// ########################################################################

// ============================================================================
// cXPersonImpl::GetSAnimator
// Address: 0x8012C7EC, Size: 8 bytes
// MATCHING
//
//   lwz r3,1012(r3)    — m_animator at offset 0x3F4
//   blr
// ============================================================================
SAnimator2* cXPersonImpl::GetSAnimator() const {
    return m_animator;
}

// ============================================================================
// cXPersonImpl::GetRecording
// Address: 0x8012C990, Size: 8 bytes
// MATCHING
// ============================================================================
void* cXPersonImpl::GetRecording() {
    return m_recording;
}

// ============================================================================
// cXPersonImpl::GetRecordDuration
// Address: 0x8012C998, Size: 8 bytes
// MATCHING
// ============================================================================
u32 cXPersonImpl::GetRecordDuration() {
    return m_recordDuration;
}

// ============================================================================
// cXPersonImpl::SetRecordDuration
// Address: 0x8012C9A0, Size: 8 bytes
// MATCHING
// ============================================================================
void cXPersonImpl::SetRecordDuration(int duration) {
    m_recordDuration = duration;
}

// ============================================================================
// cXPersonImpl::GetRecordMaxDuration
// Address: 0x8012C9A8, Size: 8 bytes
// MATCHING
// ============================================================================
u32 cXPersonImpl::GetRecordMaxDuration() {
    return m_recordMaxDuration;
}

// ============================================================================
// cXPersonImpl::SetRecordMaxDuration
// Address: 0x8012C9B0, Size: 8 bytes
// MATCHING
// ============================================================================
void cXPersonImpl::SetRecordMaxDuration(int maxDuration) {
    m_recordMaxDuration = maxDuration;
}

// ============================================================================
// cXPersonImpl::GetRecordStartTicks
// Address: 0x8012C9B8, Size: 8 bytes
// MATCHING
// ============================================================================
u32 cXPersonImpl::GetRecordStartTicks() {
    return m_recordStartTicks;
}

// ============================================================================
// cXPersonImpl::GetRecordCurTicks
// Address: 0x8012C9C0, Size: 8 bytes
// MATCHING
// ============================================================================
u32 cXPersonImpl::GetRecordCurTicks() {
    return m_recordCurTicks;
}

// ============================================================================
// cXPersonImpl::GetRecordTicksElapsed
// Address: 0x8012C9C8, Size: 8 bytes
// MATCHING
// ============================================================================
u32 cXPersonImpl::GetRecordTicksElapsed() {
    return m_recordTicksElapsed;
}

// ============================================================================
// cXPersonImpl::GetRecordSkill
// Address: 0x8012C9D0, Size: 8 bytes
// MATCHING
// ============================================================================
u32 cXPersonImpl::GetRecordSkill() {
    return m_recordSkill;
}

// ============================================================================
// cXPersonImpl::SetChangingOutfitMode
// Address: 0x8012C9F8, Size: 8 bytes
// MATCHING
//
//   stw r4,1328(r3)    — m_changingOutfitMode at offset 0x530
//   blr
// ============================================================================
void cXPersonImpl::SetChangingOutfitMode(bool mode) {
    m_changingOutfitMode = mode;
}

// ============================================================================
// cXPersonImpl::GetLastMotiveUpdateTick
// Address: 0x8012CA00, Size: 8 bytes
// MATCHING
//
//   lwz r3,1336(r3)
//   blr
// ============================================================================
u32 cXPersonImpl::GetLastMotiveUpdateTick() {
    return m_lastMotiveUpdateTick;
}

// ============================================================================
// cXPersonImpl::SetLastMotiveUpdateTick
// Address: 0x8012CA08, Size: 8 bytes
// MATCHING
//
//   stw r4,1336(r3)
//   blr
// ============================================================================
void cXPersonImpl::SetLastMotiveUpdateTick(int tick) {
    m_lastMotiveUpdateTick = tick;
}

// ============================================================================
// cXPersonImpl::SetIdleLoopCount
// Address: 0x8012C7DC, Size: 8 bytes
// MATCHING
//
//   sth r4,1344(r3)
//   blr
// ============================================================================
void cXPersonImpl::SetIdleLoopCount(s16 count) {
    m_idleLoopCount = count;
}

// ============================================================================
// cXPersonImpl::IgnoringObject
// Address: 0x8012CA10, Size: 8 bytes
// MATCHING
//
//   lwz r3,1340(r3)
//   blr
// ============================================================================
cXObject* cXPersonImpl::IgnoringObject() {
    return m_ignoringObject;
}

// ============================================================================
// cXPersonImpl::SetIgnoringObject
// Address: 0x8012CA18, Size: 8 bytes
// MATCHING
//
//   stw r4,1340(r3)
//   blr
// ============================================================================
void cXPersonImpl::SetIgnoringObject(cXObject* obj) {
    m_ignoringObject = obj;
}

// ============================================================================
// cXPersonImpl::ClearIgnoringObject
// Address: 0x8012CA20, Size: 12 bytes (3 instructions)
// MATCHING
//
//   li  r0,0
//   stw r0,1340(r3)
//   blr
// ============================================================================
void cXPersonImpl::ClearIgnoringObject() {
    m_ignoringObject = 0;
}


// ########################################################################
// #  SIM DESCRIPTION / NEIGHBOR ID
// ########################################################################

// ============================================================================
// cXPersonImpl::GetSimDescription
// Address: 0x8012C8C0, Size: 16 bytes (4 instructions)
// MATCHING
//
// Traverses: m_object -> m_object->field_0x8C -> field_0x8C
//   lwz r9,0(r3)       — load m_object
//   lwz r11,140(r9)    — load m_object->m_simDescription (offset 0x8C)
//   lwz r3,140(r11)    — return simDesc->m_impl (offset 0x8C)
//   blr
// ============================================================================
void* cXPersonImpl::GetSimDescription() {
    void* obj = m_object;
    void* desc = *(void**)((char*)obj + 0x8C);
    return *(void**)((char*)desc + 0x8C);
}

// ============================================================================
// cXPersonImpl::GetServiceNPC
// Address: 0x8012C8D0, Size: 16 bytes (4 instructions)
// MATCHING
//
// Same traversal but reads offset 0x90 from the description.
//   lwz r9,0(r3)
//   lwz r11,140(r9)
//   lwz r3,144(r11)     — offset 0x90 instead of 0x8C
//   blr
// ============================================================================
void* cXPersonImpl::GetServiceNPC() {
    void* obj = m_object;
    void* desc = *(void**)((char*)obj + 0x8C);
    return *(void**)((char*)desc + 0x90);
}


// ########################################################################
// #  RECON TYPE
// ########################################################################

// ============================================================================
// cXPersonImpl::ReconType
// Address: 0x8012503C, Size: 12 bytes (3 instructions)
// MATCHING
//
// Returns FourCC 'PERS' (0x50455253) — identifies this as a Person
// in the reconstitution (save/load) system.
//   lis  r3,0x5045    — 'PE'
//   ori  r3,r3,0x5253 — 'RS'
//   blr
// ============================================================================
u32 cXPersonImpl::ReconType() {
    return 0x50455253;  // 'PERS'
}


// ########################################################################
// #  AWARENESS
// ########################################################################

// ============================================================================
// cXPersonImpl::SetAwareOfObject
// Address: 0x8012CAA8, Size: 56 bytes (14 instructions)
// NON_MATCHING — virtual dispatch through animator
//
// Delegates to m_animator->SetAwareOfObject(obj) via vtable at offset 0x120.
//   load m_animator (this+0x3F4)
//   virtual call through animator's vtable[0x120/4]
// ============================================================================
void cXPersonImpl::SetAwareOfObject(cXObject* obj) {
    // m_animator->vtable[0x120/4](m_animator + offset, obj)
    // TODO: virtual dispatch through SAnimator2
}

// ============================================================================
// cXPersonImpl::SetAwareOfObjectKilled
// Address: 0x8012CAE0, Size: 56 bytes (14 instructions)
// NON_MATCHING — same pattern, vtable offset 0x128
// ============================================================================
void cXPersonImpl::SetAwareOfObjectKilled(cXObject* obj) {
    // m_animator->vtable[0x128/4](m_animator + offset, obj)
}

// ============================================================================
// cXPersonImpl::ClearAwareOfObject
// Address: 0x8012CB18, Size: 56 bytes (14 instructions)
// NON_MATCHING — same pattern, vtable offset 0x130
// ============================================================================
void cXPersonImpl::ClearAwareOfObject(cXObject* obj) {
    // m_animator->vtable[0x130/4](m_animator + offset, obj)
}


// ########################################################################
// #  CONTROLLING OBJECT
// ########################################################################

// ============================================================================
// cXPersonImpl::GetControllingObject
// Address: 0x8012CA5C, Size: 76 bytes (19 instructions)
// NON_MATCHING — magic multiply for signed divide
//
// Returns the object currently controlling this sim (e.g., a chair the
// sim is sitting in). Uses the control stack at offsets 0x420/0x424.
// Each entry is 12 bytes. Pops from the top.
//
//   count = (end - begin) / 12  (magic multiply: 0xAAAAAAAA / 4 -> /12)
//   if (count <= 0) return this->m_dispatchTable->m_parentObject
//   entry = begin + (count - 1) * 12
//   if (entry->objectPtr == NULL) return NULL
//   return entry->objectPtr->field_0x04
// ============================================================================
cXObject* cXPersonImpl::GetControllingObject() {
    u32* begin = (u32*)m_controlStackBegin;
    u32* end   = (u32*)m_controlStackEnd;

    int count = ((char*)end - (char*)begin) / 12;
    if (count <= 0) {
        // No control stack entries — return parent from dispatch table
        void* dispatchTable = *(void**)((char*)this + 0x04);
        return *(cXObject**)((char*)dispatchTable);
    }

    // Get top entry
    void* entry = (void*)((char*)begin + (count - 1) * 12);
    void* objPtr = *(void**)entry;
    if (objPtr == 0)
        return 0;
    return *(cXObject**)((char*)objPtr + 0x04);
}


// ########################################################################
// #  RELATIONSHIP / SOCIAL MEMORY
// ########################################################################

// ============================================================================
// cXPersonImpl::GetSimMemory
// Address: 0x8013FDF0, Size: 148 bytes (37 instructions)
// NON_MATCHING — virtual dispatch chain
//
// Gets a relationship memory value between this sim and another.
//   1. Get this sim's relation ID via virtual call (vtable offset 0x1B0/0x1B4)
//   2. Get target sim's relation ID via same virtual call
//   3. Get the RelationMatrix from m_object->field_0x58
//   4. Virtual call RelationMatrix->GetMemory(thisID, targetID, memoryType)
// ============================================================================
int cXPersonImpl::GetSimMemory(cXPerson* targetSim, int memoryType) {
    // Step 1: get this sim's relation ID
    // virtual call: this->m_dispatchTable->GetRelationID()
    int thisRelID = 0; // TODO

    // Step 2: get target sim's relation ID
    // virtual call: target->GetRelationID()
    int targetRelID = 0; // TODO

    // Step 3: get relation matrix from m_object
    void* obj = *(void**)this;
    void* relMatrix = *(void**)((char*)obj + 0x58);

    // Step 4: virtual call relMatrix->GetMemory(thisRelID, targetRelID, memoryType)
    // Returns int via r3
    return 0; // TODO
}

// ============================================================================
// cXPersonImpl::SetSimMemory
// Address: 0x8013FE84, Size: 156 bytes (39 instructions)
// NON_MATCHING — virtual dispatch chain
//
// Same pattern as GetSimMemory but calls SetMemory with an additional value
// parameter. Virtual call at vtable offset 0x1B8/0x1BC.
// ============================================================================
void cXPersonImpl::SetSimMemory(cXPerson* targetSim, int memoryType, int value) {
    // Same relation ID lookup pattern as GetSimMemory
    // Then: relMatrix->SetMemory(thisRelID, targetRelID, memoryType, value)
}

// ============================================================================
// cXPersonImpl::GetDominantMemory
// Address: 0x8013FF20, Size: 148 bytes (37 instructions)
// NON_MATCHING — virtual dispatch chain
//
// Same pattern as GetSimMemory but calls GetDominantMemory at
// vtable offset 0x1C0/0x1C4.
// ============================================================================
int cXPersonImpl::GetDominantMemory(cXPerson* targetSim, int memoryType) {
    // Same relation ID lookup + relMatrix->GetDominantMemory(...)
    return 0; // TODO
}


// ########################################################################
// #  SIMULATE (main per-tick update)
// ########################################################################

// ============================================================================
// cXPersonImpl::Simulate
// Address: 0x80124D20, Size: 796 bytes (199 instructions)
// NON_MATCHING — complex function with virtual dispatch, float constants,
//                SDA addressing, and switch statement
//
// Main per-tick simulation for the Sim. Called every game tick.
//
// High-level flow:
//   1. Get current game tick count
//   2. Check m_changingOutfitMode (this+0x530):
//      - If active, check if animator has finished via virtual call
//      - If animator done, clear outfit mode
//   3. If tick count is valid (nonzero):
//      a. Check if enough time has passed since last update (>= 60 ticks)
//         - If so, store tick count at this+0x12C and call virtual update
//      b. Update current room (check m_currentRoom at 0x41C against 0xFFFB)
//         - Look up room in house manager
//         - If indoors: load indoor light value
//         - If outdoors: load outdoor light value
//         - If room not found: load default value
//         - Store result at this+0xDC (field_0DC)
//      c. Increment sim social counter (s16 at this+0x3E, saturating)
//      d. Get game speed (virtual call, returns 0-3):
//         - Speed 0: load (multiplierA, multiplierB) pair
//         - Speed 1: load different pair
//         - Speed 2: load different pair
//         - Speed 3: load different pair
//         - Default: load base pair
//      e. Process motive delta list (this+0x3E4):
//         - For each active delta entry {motiveIdx, rate, target}:
//           - If rate < 0 (decay): clamp current motive down toward target
//           - If rate > 0 (gain): clamp current motive up toward target
//           - Apply speed multiplier to rate
//      f. Check if sim is the selected player sim:
//         - If so, clamp all 16 motives to be >= 0.0
//           (selected sim can't have negative motives)
//      g. Check m_bIsCarryingDCObject (this+0x0A):
//         - If nonzero, call virtual method to broadcast "carrying" state
//           with a string constant from .rodata
//
//   4. Return the tick count from step 1
// ============================================================================
int cXPersonImpl::Simulate(int tickDelta) {
    int currentTick = GetGameTickCount(m_object);

    // Check outfit change mode
    if (m_changingOutfitMode != 0) {
        // Virtual call: check if animator finished
        // m_animator->IsFinished() -> (returnVal, paramOut)
        // If finished and paramOut == 1: clear outfit mode
        // if (animFinished && param == 1) m_changingOutfitMode = 0;
    }

    if (currentTick == 0) {
        return currentTick;
    }

    // Time-based update check
    int lastTick = m_field_12C;
    if (tickDelta >= lastTick + 60) {
        m_field_12C = tickDelta;
        // Virtual call: periodic update (e.g., motive decay per minute)
    }

    // Room lighting update
    u16 roomID = m_currentRoom;
    if (roomID != 0xFFFB) {
        void* houseMgr = GetHouseManager();
        void* room = FindRoomByID(roomID);
        if (room != 0) {
            if (IsRoomIndoors(room)) {
                // m_field_0DC = houseMgr->indoorLightValue
            } else {
                // m_field_0DC = room->outdoorLightValue
            }
        } else {
            // m_field_0DC = DEFAULT_LIGHT_VALUE (from .rodata)
        }
    }

    // Increment social interest counter (s16 at this+0x3E), saturating at 0x7FFF
    s16 socialCounter = m_field_03E;
    socialCounter++;
    if (socialCounter < 0) socialCounter = 0;  // overflow protection
    m_field_03E = socialCounter;

    // Get game speed for motive delta multipliers
    // Virtual call returns speed 0-3
    // Each speed has a pair of float multipliers (gain rate, decay rate)
    f32 gainMult = 1.0f;
    f32 decayMult = 1.0f;
    // TODO: speed-based multiplier selection from SDA constants

    // Process motive delta list at this+0x3E4
    // List is { u32 begin, u32 end } vector, each entry is 12 bytes:
    //   { u32 motiveIndex, f32 rate, f32 target }
    u32 deltaBegin = *(u32*)((char*)this + 0x3E4);
    u32 deltaEnd   = *(u32*)((char*)this + 0x3E4 + 4);

    // For each delta entry...
    // if (rate < 0): current = max(current + rate * decayMult, target)
    // if (rate > 0): current = min(current + rate * gainMult, target)
    // Store clamped result back to m_motives[motiveIndex]

    // Check if this is the selected player sim
    // If so: clamp all 16 motives to >= 0.0
    // (Player sims on GC can't have negative motives in the active lot)

    // Check carrying DC object flag
    if (m_bIsCarryingDCObject != 0) {
        // Virtual call: broadcast carrying state with string constant
        // m_object->m_dispatchTable->BroadcastState(string)
        m_bIsCarryingDCObject = 0;
    }

    return currentTick;
}


// ########################################################################
// #  MODEL / DYING / TEXT
// ########################################################################

// ============================================================================
// cXPersonImpl::IsModelLoaded
// Address: 0x8012B754, Size: 48 bytes (12 instructions)
// MATCHING
//
// Checks if the 3D model for this sim is loaded.
// Traverses: m_dispatchTable->m_parentObj->m_vtable->m_modelRef->field_0x638
//   If field_0x638 is nonzero, model is loaded.
// ============================================================================
bool cXPersonImpl::IsModelLoaded() {
    void* dispatch = *(void**)((char*)this + 0x04);
    void* parentObj = *(void**)dispatch;
    void* vtable = *(void**)parentObj;
    void* modelRef = *(void**)((char*)vtable + 0x14);
    if (modelRef == 0)
        return false;
    u32 loaded = *(u32*)((char*)modelRef + 0x638);
    return loaded != 0;
}

// ============================================================================
// cXPersonImpl::IsPersonDying
// Address: 0x8012B784, Size: 128 bytes (32 instructions)
// NON_MATCHING — loop over action tree searching for death tree ID
//
// Searches the sim's action tree for a tree entry with ID 393 (death).
// If found, sets the ghost bit (bit 2) in m_personFlags and returns true.
//
// Algorithm:
//   count = GetActionTreeCount(m_object->field_0x00 + 0x0C)
//   for (i = count - 1; i >= 0; i--):
//     entry = GetActionTreeEntry(base, i)
//     treeID = GetTreeEntryID(entry)
//     if (treeID == 393):
//       m_personFlags |= 0x0004  // set ghost/dying bit
//       return true
//   return false
// ============================================================================
bool cXPersonImpl::IsPersonDying() {
    void* obj = *(void**)this;
    void* base = (void*)((char*)(*(void**)obj) + 0x0C);
    int count = GetActionTreeCount(base);

    for (int i = count - 1; i >= 0; i--) {
        GetActionTreeEntry(base, i);
        int treeID = GetTreeEntryID(0 /* entry from previous call */);
        if (treeID == 393) {
            m_personFlags |= 0x0004;  // mark as dying/ghost
            return true;
        }
    }
    return false;
}

// ============================================================================
// cXPersonImpl::SetCurrentActionText
// Address: 0x8012B804, Size: 40 bytes (10 instructions)
// NON_MATCHING — call to ActionQueue helper
//
// Sets the text string displayed for the current action in the UI.
//   Passes this+0x130 (action queue base), the BString2 ref, and 0.
// ============================================================================
void cXPersonImpl::SetCurrentActionText(BString2& text) {
    ActionQueue_SetText((void*)((char*)this + 0x130), &text, 0);
}


// ########################################################################
// #  INTERACTION OBJECT GETTERS
// ########################################################################

// ============================================================================
// cXPersonImpl::GetCurrentAction
// Address: 0x801263C8, Size: 68 bytes (17 instructions)
// NON_MATCHING — modular arithmetic via magic multiply
//
// Returns the current Interaction* from the action queue.
// If m_hasCurrentAction == 0, returns a static "null interaction" sentinel.
//
// Queue indexing uses modular arithmetic:
//   queueBase = this + 0x130 (304)
//   rawIndex = *(u32*)(queueBase + 0x2A8)  // 680 from queue base
//   index = rawIndex % 10  (magic multiply 0xCCCCCCCD -> /10)
//   return queueBase + index * 68
// ============================================================================
Interaction* cXPersonImpl::GetCurrentAction() {
    if (m_hasCurrentAction == 0) {
        // Return static null interaction sentinel (at 0x804867E4)
        return (Interaction*)0; // TODO: static sentinel address
    }

    void* queueBase = (void*)((char*)this + 0x130);
    u32 rawIndex = *(u32*)((char*)queueBase + 0x2A8);

    // index = rawIndex % 10
    u32 index = rawIndex - (rawIndex / 10) * 10;

    return (Interaction*)((char*)queueBase + index * 68);
}

// ============================================================================
// cXPersonImpl::GetCurrentInteractionNC
// Address: 0x8012C72C, Size: 44 bytes (11 instructions)
// NON_MATCHING — same modular arithmetic
//
// Same as GetCurrentAction but without the null check. Returns
// the current interaction slot directly from the queue.
// ============================================================================
Interaction* cXPersonImpl::GetCurrentInteractionNC() {
    void* queueBase = (void*)((char*)this + 0x130);
    u32 rawIndex = *(u32*)((char*)queueBase + 0x2A8);
    u32 index = rawIndex - (rawIndex / 10) * 10;
    return (Interaction*)((char*)queueBase + index * 68);
}

// ============================================================================
// cXPersonImpl::GetCurrentInteractionStackObject
// Address: 0x8012640C, Size: 92 bytes (23 instructions)
// NON_MATCHING — virtual dispatch + modular arithmetic
//
// Gets the stack object from the current interaction.
// Returns NULL if no current action.
// Otherwise calls GetStackObjectFromInteraction on the current queue entry.
// ============================================================================
cXObject* cXPersonImpl::GetCurrentInteractionStackObject() {
    if (m_hasCurrentAction == 0)
        return 0;

    Interaction* current = GetCurrentInteractionNC();
    return (cXObject*)GetStackObjectFromInteraction(current);
}

// ============================================================================
// cXPersonImpl::GetCurrentInteractionIconObject
// Address: 0x80126468, Size: 92 bytes (23 instructions)
// NON_MATCHING — same pattern but calls GetIconObjectFromInteraction
// ============================================================================
cXObject* cXPersonImpl::GetCurrentInteractionIconObject() {
    if (m_hasCurrentAction == 0)
        return 0;

    Interaction* current = GetCurrentInteractionNC();
    return (cXObject*)GetIconObjectFromInteraction(current);
}


// ########################################################################
// #  SOCIAL MODE TARGET
// ########################################################################

// ============================================================================
// cXPersonImpl::GetSocialModeTarget
// Address: 0x8012BB20, Size: 108 bytes (27 instructions)
// NON_MATCHING — virtual dispatch chain
//
// Returns the cXPerson* that this sim is currently in social mode with.
//   1. Check m_socialModeTarget (s16 at this+0x58)
//      - If 0: return NULL
//   2. Get the object list from m_object via dispatch table (vtable 0x488/0x48C)
//   3. FindObjectByID(objectList, 2) -> resolve to cXPerson*
//   4. Return the person pointer
// ============================================================================
cXPerson* cXPersonImpl::GetSocialModeTarget() {
    if (m_socialModeTarget == 0)
        return 0;

    // Virtual call through dispatch table to get object context
    // Then FindObjectByID to resolve the target sim
    return 0; // TODO: virtual dispatch
}


// ########################################################################
// #  NEIGHBOR ID
// ########################################################################

// ============================================================================
// cXPersonImpl::GetNeighborID
// Address: 0x8012C7FC, Size: 60 bytes (15 instructions)
// NON_MATCHING — virtual dispatch
//
// Gets the neighbor ID (short) through dispatch table virtual call
// at vtable offset 0x138/0x13C with parameter 31.
// ============================================================================
s16 cXPersonImpl::GetNeighborID() const {
    // Virtual call: m_dispatchTable->GetData(31)
    return 0; // TODO
}

// ============================================================================
// cXPersonImpl::SetNeighborID
// Address: 0x8012C838, Size: 64 bytes (16 instructions)
// NON_MATCHING — virtual dispatch
//
// Sets the neighbor ID through dispatch table virtual call
// at vtable offset 0x140/0x144 with parameter 31 and the new ID.
// ============================================================================
void cXPersonImpl::SetNeighborID(s16 id) {
    // Virtual call: m_dispatchTable->SetData(31, id)
}


// ########################################################################
// #  CARRYING / USER PICKUP
// ########################################################################

// ============================================================================
// cXPersonImpl::IsCarrying
// Address: 0x8012C788, Size: 84 bytes (21 instructions)
// NON_MATCHING — virtual dispatch through base object
//
// Checks if the sim is currently carrying an object.
// Goes through: m_object->vtable->GetHeldObject(0) -> check if != NULL
// ============================================================================
bool cXPersonImpl::IsCarrying() {
    // Virtual call: m_object->vtable[0x2B8/4]->GetHeldObject(0)
    // return (heldObject != NULL)
    return false; // TODO
}


// ########################################################################
// #  TURNING
// ########################################################################

// ============================================================================
// cXPersonImpl::Turn
// Address: 0x8012B6D8, Size: 124 bytes (31 instructions)
// NON_MATCHING — virtual dispatch + float
//
// Turns the sim to face a random direction.
//   1. Call UpdatePersonDirection(m_object)
//   2. Virtual call: GetCharacterModel() via vtable 0x188/0x18C
//   3. If model exists:
//      a. Call GetCharacterModel() again
//      b. Get random angle via GetRandomAngle()
//      c. Store angle at model+0x30
// ============================================================================
void cXPersonImpl::Turn(int /*direction*/) {
    UpdatePersonDirection(m_object);
    // Virtual call: get character model
    // If model: model->m_rotation = GetRandomAngle()
}


// ########################################################################
// #  ACTION QUEUE OPERATIONS (medium complexity)
// ########################################################################

// ============================================================================
// cXPersonImpl::IsCarryingDCObject
// Address: 0x8012C1F4, Size: 196 bytes
// NON_MATCHING — complex virtual dispatch
//
// Checks if the sim is carrying a "DC" (DirectConnect?) object.
// Queries through dispatch table and object hierarchy.
// ============================================================================
bool cXPersonImpl::IsCarryingDCObject() {
    // Complex virtual dispatch chain
    return false; // TODO
}


// ########################################################################
// #  NOTES FOR FUTURE DECOMPILATION
// ########################################################################
//
// The following large functions remain as stubs and need full decompilation:
//
// cXPersonImpl::cXPersonImpl (6232 bytes) — Constructor, initializes all 106+ fields
// cXPersonImpl::~cXPersonImpl (6528 bytes) — Destructor
// cXPersonImpl::Initialize (2684 bytes) — Post-construction initialization
// cXPersonImpl::Reset (260 bytes) — Reset to default state
// cXPersonImpl::PostLoad (708 bytes) — Post-load fixups
// cXPersonImpl::LoadMotiveEffects (300 bytes) — Load motive effect curves
// cXPersonImpl::PreSave (80 bytes) — Pre-save preparation
//
// cXPersonImpl::TrySetMotiveDelta (932 bytes) — Set motive decay/gain rate
// cXPersonImpl::TryGosubFoundAction (500 bytes) — Push found action onto stack
// cXPersonImpl::TryLookTowards (3412 bytes) — Look-at animation
// cXPersonImpl::TryGotoRoutingSlot (6800 bytes) — Pathfind to routing slot
// cXPersonImpl::AskOthersToMove (2168 bytes) — Request other sims clear path
// cXPersonImpl::MoveOutOfWay (852/2308 bytes) — Move self out of route
// cXPersonImpl::InitRoute (3124 bytes) — Initialize a routing request
// cXPersonImpl::TryGotoRelative (808 bytes) — Relative movement
// cXPersonImpl::TryRoomRouting (260 bytes) — Room-to-room pathfinding
// cXPersonImpl::TryGetReachInfo (600 bytes) — Check reachability
// cXPersonImpl::TryReach (88 bytes) — Attempt reach animation
// cXPersonImpl::TryElement (580 bytes) — Execute behavior tree element
// cXPersonImpl::TryChangeSuit (796 bytes) — Outfit change
// cXPersonImpl::TryFindBestAction (4104 bytes) — AI: evaluate all possible actions
// cXPersonImpl::TryIdleForInput (324 bytes) — Wait for player input
// cXPersonImpl::TryIdleAnimate (648 bytes) — Play idle animation
// cXPersonImpl::TryTestInteractingWith (140 bytes) — Test interaction target
// cXPersonImpl::TrySocialMode (4584 bytes) — Full social mode logic
//
// cXPersonImpl::AddAction (904 bytes) — Add interaction to queue
// cXPersonImpl::RemoveAction (388 bytes) — Remove from queue
// cXPersonImpl::CancelLastAction (296 bytes) — Cancel most recent
// cXPersonImpl::CancelAllActions (284 bytes) — Clear queue
// cXPersonImpl::CancelAllButLastActions (176 bytes) — Clear all but last
// cXPersonImpl::ShouldInterrupt (376 bytes) — Check if current should interrupt
// cXPersonImpl::executeInterruptOnIdlePrimitve (852 bytes) — Handle interrupt
// cXPersonImpl::RunImmediateAction (336 bytes) — Execute immediate
//
// cXPersonImpl::Cleanup (3120 bytes) — Full cleanup on deletion
// cXPersonImpl::ReconStream (860 bytes) — Save/load serialization
// cXPersonImpl::GosubObjectTree (780 bytes) — Push object's behavior tree
// cXPersonImpl::StackJustPopped (652 bytes) — Stack pop handler
// cXPersonImpl::UpdateCurrentAction (316 bytes) — Per-tick action update
// cXPersonImpl::CompleteCurrentAction (172 bytes) — Action completion
// cXPersonImpl::DeleteTopAction (112 bytes) — Remove top of stack
// cXPersonImpl::ActionSkipped (240 bytes) — Handle skipped action
//
// cXPersonImpl::SetSecondPlayerInSocialMode (144 bytes) — Set with side effects
// cXPersonImpl::CheckFirstPlayerForFailedSocialModeEntry (172 bytes)
// cXPersonImpl::CheckSecondPlayerForFailedSocialModeEntry (424 bytes)
// cXPersonImpl::IncrementSimSocialInterest (588 bytes)
// cXPersonImpl::GetSimSocialInterestAsMotiveValue (368 bytes)
// cXPersonImpl::SetSimSocialIntrestFromMotiveValue (324 bytes)
//
// cXPersonImpl::SetHilite (116 bytes) — Selection highlight
// cXPersonImpl::IsSelectableByPlayer (464 bytes)
// cXPersonImpl::IsPrimarySim (232 bytes)
// cXPersonImpl::AttachToHUD (116 bytes)
// cXPersonImpl::IsPersonInFamily (112 bytes)
// cXPersonImpl::ForceLocation (76 bytes)
//
// cXPersonImpl::InitWantFearIcons (108 bytes)
// cXPersonImpl::SpawnWantFearDialog (116 bytes)
// cXPersonImpl::SetIdlePlayerSimAutonomous (136 bytes)
// cXPersonImpl::GetNormalSimDescription (180 bytes)
//
// cXPersonImpl::Skipping3D (128 bytes)
// cXPersonImpl::UpdateCurrentRoom (224 bytes)
// cXPersonImpl::Place (76 bytes)
// cXPersonImpl::DumpDestList (816 bytes)
// cXPersonImpl::UserCanPickup (228 bytes)
//
// cXPersonImpl::InitializeStaticMemory (232 bytes)
// cXPersonImpl::CleanupStaticMemory (120 bytes)
// cXPersonImpl::EORDrawStickFigure (56 bytes)
// cXPersonImpl::GetNextQueueStr (104 bytes)
