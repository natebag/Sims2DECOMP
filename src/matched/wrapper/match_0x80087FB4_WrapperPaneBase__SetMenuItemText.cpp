// 0x80087FB4 WrapperPaneBase::SetMenuItemText(int, unsigned wchar_t*) (44B)
struct WrapperPaneBase {
    void SetItemText(int type, int idx, unsigned short* text);
    void SetMenuItemText(int idx, unsigned short* text);
};
void WrapperPaneBase::SetMenuItemText(int idx, unsigned short* text) {
    SetItemText(1, idx, text);
}
