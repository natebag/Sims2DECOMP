// 0x800882A0 WrapperPaneBase::GetButtonFont(ButtonType) (20B)
// FLAGS: -fno-schedule-insns
struct Button { char pad[0x50]; void* m_font; };
struct WrapperPaneBase {
    char pad[0x40];
    Button* m_buttons[4];
    void* GetButtonFont(int btnType);
};
void* WrapperPaneBase::GetButtonFont(int btnType) {
    return m_buttons[btnType]->m_font;
}
