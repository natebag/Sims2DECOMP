// 0x8008828C WrapperPaneBase::GetButtonText(ButtonType) (20B)
// FLAGS: -fno-schedule-insns
struct Button { char pad[0x20]; void* m_text; };
struct WrapperPaneBase {
    char pad[0x40];
    Button* m_buttons[4];
    void* GetButtonText(int btnType);
};
void* WrapperPaneBase::GetButtonText(int btnType) {
    return m_buttons[btnType]->m_text;
}
