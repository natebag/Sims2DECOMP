// 0x80087E64 WrapperPaneBase::SetTextItemPosY(int, float) (40B)
struct WrapperPaneBase {
    void SetItemPosY(int type, int idx, float v);
    void SetTextItemPosY(int idx, float v);
};
void WrapperPaneBase::SetTextItemPosY(int idx, float v) {
    SetItemPosY(0, idx, v);
}
