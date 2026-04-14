// 0x80087EB8 WrapperPaneBase::SetButtonItemFont(int, ERFont*) (44B)
struct ERFont;
struct WrapperPaneBase {
    void SetItemFont(int type, int idx, ERFont* f);
    void SetButtonItemFont(int idx, ERFont* f);
};
void WrapperPaneBase::SetButtonItemFont(int idx, ERFont* f) {
    SetItemFont(2, idx, f);
}
