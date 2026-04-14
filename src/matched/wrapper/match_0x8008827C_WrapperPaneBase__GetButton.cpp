// 0x8008827C WrapperPaneBase::GetButton(ButtonType) (16B)
struct Button;
struct WrapperPaneBase {
    char pad[0x40];
    Button* m_buttons[4];
    Button* GetButton(int btnType);
};
Button* WrapperPaneBase::GetButton(int btnType) {
    return m_buttons[btnType];
}
