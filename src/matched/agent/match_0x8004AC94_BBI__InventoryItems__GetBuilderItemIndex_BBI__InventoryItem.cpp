// 0x8004AC94 BBI::InventoryItems::GetBuilderItemIndex(BBI::InventoryItem::eItemSubcategory, int) const (144 B)

namespace BBI {

struct InventoryItem {
    int GetItemSubcategory() const;
    int GetItemGuid() const;
};

struct InventoryItems {
    InventoryItem* m_items[36];
    int GetContainerSize() const;
    int GetBuilderItemIndex(int subcategory, int guid) const;
};

int InventoryItems::GetBuilderItemIndex(int subcategory, int guid) const {
    unsigned int count = GetContainerSize();
    for (unsigned int i = 0; i < count; ++i) {
        InventoryItem* item = m_items[i];
        if (item != 0 && item->GetItemSubcategory() == subcategory && item->GetItemGuid() == guid) {
            return i;
        }
    }
    return -1;
}

}
