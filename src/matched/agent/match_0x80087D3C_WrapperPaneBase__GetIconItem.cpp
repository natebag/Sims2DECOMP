// 0x80087D3C WrapperPaneBase::GetIconItem(int) (40B)
struct Item {};
struct WrapperPaneBase {
    Item* GetItem(int type, int idx);
    Item* GetIconItem(int idx);
};
Item* WrapperPaneBase::GetIconItem(int idx) {
    return GetItem(3, idx);
}
