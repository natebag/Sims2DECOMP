// 0x80087F0C WrapperPaneBase::SetButtonItemStyle(int, ItemStyle) (44B)
struct WrapperPaneBase {
    void SetItemStyle(int type, int idx, int s);
    void SetButtonItemStyle(int idx, int s);
};
void WrapperPaneBase::SetButtonItemStyle(int idx, int s) {
    SetItemStyle(2, idx, s);
}
