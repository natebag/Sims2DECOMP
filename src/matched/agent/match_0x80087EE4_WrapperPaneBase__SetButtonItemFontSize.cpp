// 0x80087EE4 WrapperPaneBase::SetButtonItemFontSize(int, float) (40B)
struct WrapperPaneBase {
    void SetItemFontSize(int type, int idx, float s);
    void SetButtonItemFontSize(int idx, float s);
};
void WrapperPaneBase::SetButtonItemFontSize(int idx, float s) {
    SetItemFontSize(2, idx, s);
}
