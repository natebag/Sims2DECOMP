// 0x80087F64 WrapperPaneBase::SetButtonItemPosX(int, float) (40B)
struct WrapperPaneBase {
    void SetItemPosX(int type, int idx, float v);
    void SetButtonItemPosX(int idx, float v);
};
void WrapperPaneBase::SetButtonItemPosX(int idx, float v) {
    SetItemPosX(2, idx, v);
}
