// 0x802F0A8C EAnimController::SetNodeVisible(int, bool) (92B)
//
// PHASE 2 WALL — OpusReviewGuy park 2026-05-11. Twin pair with
// SetNodeIgnoreAnimatedVisibility @ 0x802F0A30 — same shape, bits flipped.
//
// Algorithm:
//   if (nodeIdx < 0) return
//   int nodeCount = m_state ? m_state->count : 0
//   if (nodeIdx >= nodeCount) return
//   int* slot = m_nodeStates + nodeIdx * 68
//   if (!visible) *slot |= 0x08   else *slot &= ~0x10
//
// Mismatch: GCC's lwzx/stwx emit (rA=slot, rB=base) where DOL has (rA=base, rB=slot)
// — swap_operands lwzx canonicalization defeat. Plus cmpwi/li order at offset 0x00C.
//
// FLAGS: -fno-schedule-insns -fno-schedule-insns2
// ASMPROC_swap_adj: a=li b=lwz which=first
// ASMPROC_swap_adj: a=li b=cmpwi which=first
// ASMPROC_swap_operands: match="lwzx 0,9,11" pos=1,2
// ASMPROC_swap_operands: match="stwx 0,9,11" pos=1,2
// ASMPROC_swap_operands: match="lwzx 0,9,11" pos=1,2
// ASMPROC_swap_operands: match="stwx 0,9,11" pos=1,2

struct EAnimNodeState {
    char pad[24];
    int  count;          // 0x18 (24)
};

class EAnimController {
public:
    char  pad0[12];
    char* m_nodeStates;  // 0x0C (12)
    char  pad1[20];      // 0x10..0x23 (gap)
    EAnimNodeState* m_state;  // 0x24 (36)

    void SetNodeVisible(int nodeIdx, bool visible);
};

void EAnimController::SetNodeVisible(int nodeIdx, bool visible)
{
    if (nodeIdx < 0) return;
    int nodeCount = 0;
    if (m_state != 0) nodeCount = m_state->count;
    if (nodeIdx >= nodeCount) return;
    if (!visible) {
        int* slot = (int*)(m_nodeStates + nodeIdx * 68);
        *slot = *slot | 0x08;
        return;
    }
    int* slot = (int*)(m_nodeStates + nodeIdx * 68);
    *slot = *slot & ~0x08;
}
