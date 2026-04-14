// 0x800881B0 WrapperPaneBase::SetIconItemSizeX(int, float) (40B)
struct WrapperPaneBase {
    void SetItemSizeX(int type, int idx, float v);
    void SetIconItemSizeX(int idx, float v);
};
void WrapperPaneBase::SetIconItemSizeX(int idx, float v) {
    SetItemSizeX(3, idx, v);
}
