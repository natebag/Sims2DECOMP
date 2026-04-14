// 0x80087CEC WrapperPaneBase::GetButtonItem(int) (40B)
struct Item {};
struct WrapperPaneBase {
    Item* GetItem(int type, int idx);
    Item* GetButtonItem(int idx);
};
Item* WrapperPaneBase::GetButtonItem(int idx) {
    return GetItem(2, idx);
}
