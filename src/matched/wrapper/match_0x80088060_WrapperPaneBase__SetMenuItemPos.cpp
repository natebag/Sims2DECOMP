// 0x80088060 WrapperPaneBase::SetMenuItemPos(int, EVec2&) (44B)
struct EVec2;
struct WrapperPaneBase {
    void SetItemPos(int type, int idx, EVec2& v);
    void SetMenuItemPos(int idx, EVec2& v);
};
void WrapperPaneBase::SetMenuItemPos(int idx, EVec2& v) {
    SetItemPos(1, idx, v);
}
