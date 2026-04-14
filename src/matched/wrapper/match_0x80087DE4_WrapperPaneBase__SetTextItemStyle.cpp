// 0x80087DE4 WrapperPaneBase::SetTextItemStyle(int, ItemStyle) (44B)
struct WrapperPaneBase {
    void SetItemStyle(int type, int idx, int s);
    void SetTextItemStyle(int idx, int s);
};
void WrapperPaneBase::SetTextItemStyle(int idx, int s) {
    SetItemStyle(0, idx, s);
}
