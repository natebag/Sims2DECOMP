// 0x801B8F04 H2DTarget::RemoveAllActions(int) (60B)
// Index-bounded forward to ACTTarget::RemoveAllActions

struct ACTTarget;

struct H2DTarget {
    char pad[180];
    ACTTarget* m_acts[2];
    void RemoveAllActions(int idx);
};

extern void ACTTarget_RemoveAllActions(ACTTarget* a, int idx);

void H2DTarget::RemoveAllActions(int idx) {
    if ((unsigned int)idx > 1) return;
    ACTTarget* a = m_acts[idx];
    if (a == 0) return;
    ACTTarget_RemoveAllActions(a, idx);
}
