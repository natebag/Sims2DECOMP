// 0x801B8DDC H2DTarget::CleanupModelessDialogs (44B) — forward to MDITarget

struct MDITarget;

struct H2DTarget {
    char pad[200];
    MDITarget* m_mdi;
    void CleanupModelessDialogs();
};

extern void MDITarget_CleanupModelessDialogs(MDITarget* m);

void H2DTarget::CleanupModelessDialogs() {
    MDITarget* m = m_mdi;
    if (m == 0) return;
    MDITarget_CleanupModelessDialogs(m);
}
