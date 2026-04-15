// 0x801B9260 H2DTarget::DisplayPaused (44B) — forward to MODTarget

struct MODTarget;

struct H2DTarget {
    char pad[136];
    MODTarget* m_mod;
    void DisplayPaused();
};

extern void MODTarget_DisplayPaused(MODTarget* m);

void H2DTarget::DisplayPaused() {
    MODTarget* m = m_mod;
    if (m == 0) return;
    MODTarget_DisplayPaused(m);
}
