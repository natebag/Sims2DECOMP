// 0x80087CC4 WrapperPaneBase::GetTextItem(int) (40B)
struct Item {};
struct WrapperPaneBase {
    Item* GetItem(int type, int idx);
    Item* GetTextItem(int idx);
};
Item* WrapperPaneBase::GetTextItem(int idx) {
    return GetItem(0, idx);
}
