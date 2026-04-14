// 0x8008633C WrapperPaneBase::UpdateAptButtonPosX (48B)
struct AptButton {
    char pad[4];
    unsigned int m_flags;
};

struct WrapperPaneBase {
    char pad[4];
    unsigned int m_buttonFlags;
    char pad2[0x40 - 8];
    AptButton* m_buttons[4];
    void UpdateAptButtonPosX(int btn);
};

void WrapperPaneBase::UpdateAptButtonPosX(int btn) {
    if ((m_buttonFlags & (0x100 << btn)) == 0) return;
    m_buttons[btn]->m_flags |= 0x10800000;
}
