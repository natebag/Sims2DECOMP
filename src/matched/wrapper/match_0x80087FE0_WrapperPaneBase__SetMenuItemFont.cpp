// 0x80087FE0 WrapperPaneBase::SetMenuItemFont(int, ERFont*) (44B)
struct ERFont;
struct WrapperPaneBase {
    void SetItemFont(int type, int idx, ERFont* f);
    void SetMenuItemFont(int idx, ERFont* f);
};
void WrapperPaneBase::SetMenuItemFont(int idx, ERFont* f) {
    SetItemFont(1, idx, f);
}
