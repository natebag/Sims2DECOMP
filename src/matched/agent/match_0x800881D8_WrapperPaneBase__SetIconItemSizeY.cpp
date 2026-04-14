// 0x800881D8 WrapperPaneBase::SetIconItemSizeY(int, float) (40B)
struct WrapperPaneBase {
    void SetItemSizeY(int type, int idx, float v);
    void SetIconItemSizeY(int idx, float v);
};
void WrapperPaneBase::SetIconItemSizeY(int idx, float v) {
    SetItemSizeY(3, idx, v);
}
