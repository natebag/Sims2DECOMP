// 0x80088184 WrapperPaneBase::SetIconItemSize(int, EVec2&) (44B)
struct EVec2;
struct WrapperPaneBase {
    void SetItemSize(int type, int idx, EVec2& v);
    void SetIconItemSize(int idx, EVec2& v);
};
void WrapperPaneBase::SetIconItemSize(int idx, EVec2& v) {
    SetItemSize(3, idx, v);
}
