// 0x80087F8C WrapperPaneBase::SetButtonItemPosY(int, float) (40B)
struct WrapperPaneBase {
    void SetItemPosY(int type, int idx, float v);
    void SetButtonItemPosY(int idx, float v);
};
void WrapperPaneBase::SetButtonItemPosY(int idx, float v) {
    SetItemPosY(2, idx, v);
}
