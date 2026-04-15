// 0x801B8EC8 H2DTarget::RemoveAction(int, Interaction*) (60B)
// Index-bounded forward to ACTTarget::RemoveAction

struct Interaction;
struct ACTTarget;

struct H2DTarget {
    char pad[180];
    ACTTarget* m_acts[2];  // +180, +184
    void RemoveAction(int idx, Interaction* in);
};

extern void ACTTarget_RemoveAction(ACTTarget* a, int idx, Interaction* in);

void H2DTarget::RemoveAction(int idx, Interaction* in) {
    if ((unsigned int)idx > 1) return;
    ACTTarget* a = m_acts[idx];
    if (a == 0) return;
    ACTTarget_RemoveAction(a, idx, in);
}
