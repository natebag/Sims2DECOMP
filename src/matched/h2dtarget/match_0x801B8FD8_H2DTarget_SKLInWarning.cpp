// 0x801B8FD8 H2DTarget::SKLInWarning(int, bool) (60B)
// Index into [136 + idx*4], null check, forward to MOTTarget::SetWarning with args (2, ?, 1)

struct MOTTarget;

struct H2DTarget {
    char pad[136];
    MOTTarget* m_mots[1];
    void SKLInWarning(int idx, bool b);
};

extern void MOTTarget_SetWarning(MOTTarget* m, int a, bool b, int c);

void H2DTarget::SKLInWarning(int idx, bool b) {
    MOTTarget* m = m_mots[idx];
    if (m == 0) return;
    MOTTarget_SetWarning(m, 2, b, 1);
}
