// 0x8008808C WrapperPaneBase::SetMenuItemPosX(int, float) (40B)
struct WrapperPaneBase {
    void SetItemPosX(int type, int idx, float v);
    void SetMenuItemPosX(int idx, float v);
};
void WrapperPaneBase::SetMenuItemPosX(int idx, float v) {
    SetItemPosX(1, idx, v);
}
