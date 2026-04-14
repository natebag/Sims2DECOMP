// 0x80087D64 WrapperPaneBase::SetTextItemText(int, unsigned wchar_t*) (44B)
struct WrapperPaneBase {
    void SetItemText(int type, int idx, unsigned short* text);
    void SetTextItemText(int idx, unsigned short* text);
};
void WrapperPaneBase::SetTextItemText(int idx, unsigned short* text) {
    SetItemText(0, idx, text);
}
