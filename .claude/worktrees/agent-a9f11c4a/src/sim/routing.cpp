// routing.cpp - Pathfinding and routing system
// Object file: routing.obj (and partially xrouting.obj)
// Source: c:\BuildAgent\cm3-build22-NGC\CMBuild\
//
// Compile flags: -mcpu=750 -meabi -mhard-float -O2 -fno-exceptions -fno-rtti
//                -fno-builtin -fno-optimize-sibling-calls
//                -fno-schedule-insns -fno-schedule-insns2

#include "sim/routing.h"

// Static space partition instance at 0x804868A8
SpacePartition Path::fSpacePartition;

// ============================================================================
// PenaltyRect::PenaltyRect(IRect*, int)
// Address: 0x8013896C
// Size: 44 bytes (0x02C)
// NON_MATCHING - SN saves this to r9, loads all rect fields in a different
// order (bottom first), then stores. GCC loads/stores in a different order
// and doesn't save this to r9.
//
// Copies IRect fields and stores penalty.
// ============================================================================
PenaltyRect::PenaltyRect(IRect* rect, int penalty) {
    this->left = rect->left;
    this->top = rect->top;
    this->right = rect->right;
    this->bottom = rect->bottom;
    this->penalty = penalty;
}

// ============================================================================
// PenaltyRect::PenaltyRect(int, int, int, int, int)
// Address: 0x80138998
// Size: 28 bytes (0x01C)
// NON_MATCHING - SN saves this to r9 (mr r9,r3) while GCC uses r3 directly.
// Store ordering also differs slightly.
//
// Direct initialization. Parameters mapped from registers:
// r4->+0x04(top), r5->+0x00(left), r6->+0x0C(bottom),
// r7->+0x08(right), r8->+0x10(penalty)
// ============================================================================
PenaltyRect::PenaltyRect(int top, int left, int bottom, int right, int penalty) {
    this->top = top;
    this->left = left;
    this->bottom = bottom;
    this->right = right;
    this->penalty = penalty;
}

// ============================================================================
// SpacePartition::GetNode
// Address: 0x80138E30
// Size: 64 bytes (0x040)
// NON_MATCHING - SN uses mullw+srawi for division by 44, GCC uses
// mulhwu+srwi (unsigned high multiply). Both compute (end-begin)/44
// correctly but via different division-by-constant strategies.
// Also SN uses mr.+blt for initial check, GCC uses cmpwi+blt.
//
// Returns pointer to node at index, or NULL if out of bounds.
// ============================================================================
ASTNode* SpacePartition::GetNode(int index) {
    if (index < 0) {
        return 0;
    }
    int count = (int)(((char*)m_nodesEnd - (char*)m_nodes) / sizeof(ASTNode));
    if ((unsigned int)index >= (unsigned int)count) {
        return 0;
    }
    return &m_nodes[index];
}

// ============================================================================
// SpacePartition::IsSpatialNode
// Address: 0x80138F1C
// Size: 20 bytes (0x014)
// NON_MATCHING - SN uses addi+subfic+subfe+neg idiom, GCC uses
// addi+nor+srwi idiom. Both compute (node >= 1) as a boolean.
//
// Returns 1 if node index >= 1, 0 otherwise.
// ============================================================================
int SpacePartition::IsSpatialNode(int node) {
    return (node + 1) >= 2;
}

// ============================================================================
// SpacePartition::GetTerminals
// Address: 0x80139250
// Size: 20 bytes (0x014)
// NON_MATCHING - Register choice: SN uses r0 for 0, GCC uses r10.
// Otherwise identical structure.
//
// Sets terminal indices: *start = 0, *end = 1.
// ============================================================================
void SpacePartition::GetTerminals(int* start, int* end) {
    *start = 0;
    *end = 1;
}

// ============================================================================
// Path::DeallocateAllPathData
// Address: 0x8013D7FC
// Size: 40 bytes (0x028)
// NON_MATCHING - GCC uses lis/addi for static address, SN uses same but
// with SDA-relative or different relocation. Function structure matches
// (prolog, load address, call Deallocate, epilog) but instruction
// interleaving may differ.
//
// Calls SpacePartition::Deallocate on the static fSpacePartition.
// ============================================================================
void Path::DeallocateAllPathData(void) {
    fSpacePartition.Deallocate();
}

// ============================================================================
// XRoute::GetRoutingSlot
// Address: 0x8015303C
// Size: 8 bytes (0x008)
// MATCHING
//
// Returns pointer to embedded routing slot at offset +0x10.
// ============================================================================
RoutingSlot* XRoute::GetRoutingSlot(void) {
    return &m_routingSlot;
}

// ============================================================================
// XRoute::HasCurrentGoal
// Address: 0x80152F5C
// Size: 24 bytes (0x018)
// NON_MATCHING - SN uses cmpwi+bnelr branch pattern for bool conversion,
// GCC uses addi+addic+subfe arithmetic pattern. Semantically equivalent.
//
// Returns true if m_currentGoal != -1.
// ============================================================================
bool XRoute::HasCurrentGoal(void) {
    return m_currentGoal != -1;
}

// ============================================================================
// XRoute::CountGoals
// Address: 0x80152F74
// Size: 20 bytes (0x014)
// NON_MATCHING - SN loads begin into r0 first, GCC loads end into r9 first.
// Different register allocation but identical logic.
//
// Returns number of goals (end - begin) / sizeof(RouteGoal).
// ============================================================================
int XRoute::CountGoals(void) {
    return (int)(m_goalsEnd - m_goalsBegin);
}

// ============================================================================
// XRoute::GetNthGoal
// Address: 0x80152F88
// Size: 16 bytes (0x010)
// NON_MATCHING - GCC emits slwi before lwz (computes index shift before
// loading base pointer), SN emits lwz then slwi.
//
// Returns pointer to goal at index n.
// ============================================================================
RouteGoal* XRoute::GetNthGoal(int n) {
    return &m_goalsBegin[n];
}

// ============================================================================
// XRoute::SetCurrentGoal
// Address: 0x80152FE8
// Size: 8 bytes (0x008)
// MATCHING
//
// Sets m_currentGoal to given index.
// ============================================================================
void XRoute::SetCurrentGoal(int index) {
    m_currentGoal = index;
}

// ============================================================================
// XRoute::GetCurrentGoal
// Address: 0x80153248
// Size: 20 bytes (0x014)
// NON_MATCHING - SN uses r0 for temporaries, GCC uses r9. Also different
// instruction ordering (SN loads both fields then shifts, GCC loads one,
// shifts, then loads the other).
//
// Returns pointer to current goal.
// ============================================================================
RouteGoal* XRoute::GetCurrentGoal(void) {
    return &m_goalsBegin[m_currentGoal];
}

// ============================================================================
// XRoute::DoStream
// Address: 0x801534C8
// Size: 4 bytes (0x004)
// MATCHING
//
// Empty function - just blr.
// ============================================================================
void XRoute::DoStream(ReconBuffer* buffer, int direction) {
}

// ============================================================================
// XRoute::ResetGoals
// Address: 0x801534CC
// Size: 52 bytes (0x034)
// NON_MATCHING - SN preserves the destructor iteration loop (even though
// it's a no-op). GCC optimizes out the empty loop entirely. Also different
// store ordering: SN stores goalsEnd, bestGoal, currentGoal in that order;
// GCC stores bestGoal, goalsEnd, currentGoal.
//
// Resets goal vector and clears goal indices to -1.
// ============================================================================
void XRoute::ResetGoals(void) {
    // Iterate through goals (destructor calls, no-op here)
    RouteGoal* it = m_goalsBegin;
    while (it != m_goalsEnd) {
        it++;
    }
    // Reset vector size to 0 (keep allocation)
    m_goalsEnd = m_goalsBegin;
    m_bestGoal = -1;
    m_currentGoal = -1;
}

// ============================================================================
// BuildRoomPartition(unsigned short, vector<PenaltyRect>*)
// Address: 0x801558D0
// Size: 36 bytes (0x024)
// MATCHING (modulo relocation; requires -fno-optimize-sibling-calls
//           -fno-schedule-insns -fno-schedule-insns2)
//
// Wrapper that calls the 3-arg version with flag=true.
// ============================================================================
void BuildRoomPartition(unsigned short roomId, void* penaltyRects) {
    BuildRoomPartition(roomId, penaltyRects, true);
}

// ============================================================================
// global constructors keyed to PenaltyRect::PenaltyRect(IRect *, int)
// Address: 0x8013D878
// Size: 44 bytes (0x02C)
// NON_MATCHING - Different static init patterns between SN and GCC.
// ============================================================================

// ============================================================================
// global destructors keyed to PenaltyRect::PenaltyRect(IRect *, int)
// Address: 0x8013D8A4
// Size: 44 bytes (0x02C)
// NON_MATCHING - Different static fini patterns between SN and GCC.
// ============================================================================
