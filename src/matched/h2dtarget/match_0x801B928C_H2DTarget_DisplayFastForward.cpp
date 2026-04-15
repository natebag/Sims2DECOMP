// 0x801B928C H2DTarget::DisplayFastForward (44B) — forward to MODTarget

struct MODTarget;

struct H2DTarget {
    char pad[136];
    MODTarget* m_mod;
    void DisplayFastForward();
};

extern void MODTarget_DisplayFastForward(MODTarget* m);

void H2DTarget::DisplayFastForward() {
    MODTarget* m = m_mod;
    if (m == 0) return;
    MODTarget_DisplayFastForward(m);
}
