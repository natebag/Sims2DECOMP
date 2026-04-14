// 0x80088348 WrapperPaneBase::GetButtonPosY(ButtonType) (64B)
// FLAGS: -fno-schedule-insns
struct ButtonVT { char pad[0xE0]; short adj; short p; void* (*fn)(void*); };
struct Button { char pad[0x1C]; ButtonVT* vt; };
struct WrapperPaneBase {
    char pad[0x40];
    Button* m_buttons[4];
    void* GetButtonPosY(int btnType);
};
void* WrapperPaneBase::GetButtonPosY(int btnType) {
    Button* btn = m_buttons[btnType];
    ButtonVT* vt = btn->vt;
    short adj = vt->adj;
    void* (*fn)(void*) = vt->fn;
    return fn((char*)btn + adj);
}
