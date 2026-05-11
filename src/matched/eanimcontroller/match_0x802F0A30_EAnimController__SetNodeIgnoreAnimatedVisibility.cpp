// 0x802F0A30 EAnimController::SetNodeIgnoreAnimatedVisibility(int, bool) (92B)
//
// PHASE 2 WALL — twin of SetNodeVisible @ 0x802F0A8C. Same shape, bits flipped:
//   - operates on 0x10 (vs 0x08)
//   - branch direction inverted (beq vs bne) — true-path sets, false-path clears
//
// Sibling-port recipe transfer: same 6-directive composition as the twin.
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
    int  count;
};

class EAnimController {
public:
    char  pad0[12];
    char* m_nodeStates;
    char  pad1[20];
    EAnimNodeState* m_state;

    void SetNodeIgnoreAnimatedVisibility(int nodeIdx, bool ignore);
};

void EAnimController::SetNodeIgnoreAnimatedVisibility(int nodeIdx, bool ignore)
{
    if (nodeIdx < 0) return;
    int nodeCount = 0;
    if (m_state != 0) nodeCount = m_state->count;
    if (nodeIdx >= nodeCount) return;
    if (ignore) {
        int* slot = (int*)(m_nodeStates + nodeIdx * 68);
        *slot = *slot | 0x10;
        return;
    }
    int* slot = (int*)(m_nodeStates + nodeIdx * 68);
    *slot = *slot & ~0x10;
}
