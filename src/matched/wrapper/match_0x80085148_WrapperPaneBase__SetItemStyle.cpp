// 0x80085148 WrapperPaneBase::SetItemStyle(ItemType, int, ItemStyle) (52B)
struct Item {};
extern void SetStyleHelper(Item* item, int style);

struct WrapperPaneBase {
    Item* GetItem(int type, int idx);
    void SetItemStyle(int type, int idx, int style);
};

void WrapperPaneBase::SetItemStyle(int type, int idx, int style) {
    Item* item = GetItem(type, idx);
    SetStyleHelper(item, style);
}
