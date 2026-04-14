// 0x80088108 WrapperPaneBase::SetIconItemPos(int, EVec2&) (44B)
struct EVec2;
struct WrapperPaneBase {
    void SetItemPos(int type, int idx, EVec2& v);
    void SetIconItemPos(int idx, EVec2& v);
};
void WrapperPaneBase::SetIconItemPos(int idx, EVec2& v) {
    SetItemPos(3, idx, v);
}
