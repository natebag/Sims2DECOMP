// 0x80088308 WrapperPaneBase::GetButtonPosX(ButtonType) (64B)
// FLAGS: -fno-schedule-insns
struct ButtonVT { char pad[0xD8]; short adj; short p; void* (*fn)(void*); };
struct Button { char pad[0x1C]; ButtonVT* vt; };
struct WrapperPaneBase {
    char pad[0x40];
    Button* m_buttons[4];
    void* GetButtonPosX(int btnType);
};
void* WrapperPaneBase::GetButtonPosX(int btnType) {
    Button* btn = m_buttons[btnType];
    ButtonVT* vt = btn->vt;
    short adj = vt->adj;
    void* (*fn)(void*) = vt->fn;
    return fn((char*)btn + adj);
}
