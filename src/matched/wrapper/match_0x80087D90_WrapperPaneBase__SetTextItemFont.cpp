// 0x80087D90 WrapperPaneBase::SetTextItemFont(int, ERFont*) (44B)
struct ERFont;
struct WrapperPaneBase {
    void SetItemFont(int type, int idx, ERFont* f);
    void SetTextItemFont(int idx, ERFont* f);
};
void WrapperPaneBase::SetTextItemFont(int idx, ERFont* f) {
    SetItemFont(0, idx, f);
}
