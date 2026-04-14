// 0x8008815C WrapperPaneBase::SetIconItemPosY(int, float) (40B)
struct WrapperPaneBase {
    void SetItemPosY(int type, int idx, float v);
    void SetIconItemPosY(int idx, float v);
};
void WrapperPaneBase::SetIconItemPosY(int idx, float v) {
    SetItemPosY(3, idx, v);
}
