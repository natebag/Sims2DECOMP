// 0x801B8DB0 H2DTarget::SpawnModelessDialog(UIDialog*) (44B)
// Load mdi @ +200, null check, forward to MDITarget::Spawn if non-null

struct UIDialog;
struct MDITarget;

struct H2DTarget {
    char pad[200];
    MDITarget* m_mdi;
    void SpawnModelessDialog(UIDialog* d);
};

extern void MDITarget_Spawn(MDITarget* m, UIDialog* d);

void H2DTarget::SpawnModelessDialog(UIDialog* d) {
    MDITarget* m = m_mdi;
    if (m == 0) return;
    MDITarget_Spawn(m, d);
}
