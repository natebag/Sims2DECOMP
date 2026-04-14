// 0x80087F38 WrapperPaneBase::SetButtonItemPos(int, EVec2&) (44B)
struct EVec2;
struct WrapperPaneBase {
    void SetItemPos(int type, int idx, EVec2& v);
    void SetButtonItemPos(int idx, EVec2& v);
};
void WrapperPaneBase::SetButtonItemPos(int idx, EVec2& v) {
    SetItemPos(2, idx, v);
}
