// 0x8008800C WrapperPaneBase::SetMenuItemFontSize(int, float) (40B)
struct WrapperPaneBase {
    void SetItemFontSize(int type, int idx, float s);
    void SetMenuItemFontSize(int idx, float s);
};
void WrapperPaneBase::SetMenuItemFontSize(int idx, float s) {
    SetItemFontSize(1, idx, s);
}
