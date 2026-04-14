// 0x80087DBC WrapperPaneBase::SetTextItemFontSize(int, float) (40B)
struct WrapperPaneBase {
    void SetItemFontSize(int type, int idx, float s);
    void SetTextItemFontSize(int idx, float s);
};
void WrapperPaneBase::SetTextItemFontSize(int idx, float s) {
    SetItemFontSize(0, idx, s);
}
