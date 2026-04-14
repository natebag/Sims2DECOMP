// 0x8008636C WrapperPaneBase::UpdateAptButtonPosY (48B)
struct AptButton {
    char pad[4];
    unsigned int m_flags;
};

struct WrapperPaneBase {
    char pad[4];
    unsigned int m_buttonFlags;
    char pad2[0x40 - 8];
    AptButton* m_buttons[4];
    void UpdateAptButtonPosY(int btn);
};

void WrapperPaneBase::UpdateAptButtonPosY(int btn) {
    if ((m_buttonFlags & (0x100 << btn)) == 0) return;
    m_buttons[btn]->m_flags |= 0x20800000;
}
