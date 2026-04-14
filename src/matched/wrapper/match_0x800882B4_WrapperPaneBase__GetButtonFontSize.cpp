// 0x800882B4 WrapperPaneBase::GetButtonFontSize(ButtonType) (20B)
struct Button { char pad[0x54]; float m_fontSize; };
struct WrapperPaneBase {
    char pad[0x40];
    Button* m_buttons[4];
    float GetButtonFontSize(int btnType);
};
float WrapperPaneBase::GetButtonFontSize(int btnType) {
    return m_buttons[btnType]->m_fontSize;
}
