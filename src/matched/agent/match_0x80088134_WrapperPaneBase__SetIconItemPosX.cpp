// 0x80088134 WrapperPaneBase::SetIconItemPosX(int, float) (40B)
struct WrapperPaneBase {
    void SetItemPosX(int type, int idx, float v);
    void SetIconItemPosX(int idx, float v);
};
void WrapperPaneBase::SetIconItemPosX(int idx, float v) {
    SetItemPosX(3, idx, v);
}
