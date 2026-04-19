// 0x80188464 (80B) HUDTarget::UpdateTutorialLocks(void)
// Guarded ShowHUD: compare SDA global vs m_EC, store both fields, call ShowHUD if changed && g==1.

extern int g_tutorialLock;

class HUDTarget {
public:
    char pad_000[0xEC];
    int m_field_0EC;
    int m_field_0F0;

    void ShowHUD(void);
    void UpdateTutorialLocks(void);
};

void HUDTarget::UpdateTutorialLocks(void) {
    int gVal = g_tutorialLock;
    bool changed = (gVal != m_field_0EC);
    m_field_0EC = gVal;
    m_field_0F0 = gVal;
    if (!changed) return;
    if (gVal != 1) return;
    this->ShowHUD();
}
