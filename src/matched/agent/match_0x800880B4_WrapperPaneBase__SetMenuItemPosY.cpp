// 0x800880B4 WrapperPaneBase::SetMenuItemPosY(int, float) (40B)
struct WrapperPaneBase {
    void SetItemPosY(int type, int idx, float v);
    void SetMenuItemPosY(int idx, float v);
};
void WrapperPaneBase::SetMenuItemPosY(int idx, float v) {
    SetItemPosY(1, idx, v);
}
