// 0x80087E10 WrapperPaneBase::SetTextItemPos(int, EVec2&) (44B)
struct EVec2;
struct WrapperPaneBase {
    void SetItemPos(int type, int idx, EVec2& v);
    void SetTextItemPos(int idx, EVec2& v);
};
void WrapperPaneBase::SetTextItemPos(int idx, EVec2& v) {
    SetItemPos(0, idx, v);
}
