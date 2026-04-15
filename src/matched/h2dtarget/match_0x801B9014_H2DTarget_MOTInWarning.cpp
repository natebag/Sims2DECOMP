// 0x801B9014 H2DTarget::MOTInWarning(int, bool) (60B)
// Same template as SKLInWarning but with constants 3 and 0

struct MOTTarget;

struct H2DTarget {
    char pad[136];
    MOTTarget* m_mots[1];
    void MOTInWarning(int idx, bool b);
};

extern void MOTTarget_SetWarning(MOTTarget* m, int a, bool b, int c);

void H2DTarget::MOTInWarning(int idx, bool b) {
    MOTTarget* m = m_mots[idx];
    if (m == 0) return;
    MOTTarget_SetWarning(m, 3, b, 0);
}
