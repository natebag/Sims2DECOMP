// 0x80087D14 WrapperPaneBase::GetMenuItem(int) (40B)
struct Item {};
struct WrapperPaneBase {
    Item* GetItem(int type, int idx);
    Item* GetMenuItem(int idx);
};
Item* WrapperPaneBase::GetMenuItem(int idx) {
    return GetItem(1, idx);
}
