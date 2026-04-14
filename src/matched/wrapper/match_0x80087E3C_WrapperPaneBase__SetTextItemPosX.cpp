// 0x80087E3C WrapperPaneBase::SetTextItemPosX(int, float) (40B)
struct WrapperPaneBase {
    void SetItemPosX(int type, int idx, float v);
    void SetTextItemPosX(int idx, float v);
};
void WrapperPaneBase::SetTextItemPosX(int idx, float v) {
    SetItemPosX(0, idx, v);
}
