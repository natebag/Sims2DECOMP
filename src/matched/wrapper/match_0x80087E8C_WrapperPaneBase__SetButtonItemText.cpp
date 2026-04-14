// 0x80087E8C WrapperPaneBase::SetButtonItemText(int, unsigned wchar_t*) (44B)
struct WrapperPaneBase {
    void SetItemText(int type, int idx, unsigned short* text);
    void SetButtonItemText(int idx, unsigned short* text);
};
void WrapperPaneBase::SetButtonItemText(int idx, unsigned short* text) {
    SetItemText(2, idx, text);
}
