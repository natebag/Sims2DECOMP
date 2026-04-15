/* 0x8004AC50 BBI::InventoryItems::GetBuilderItem(BBI::InventoryItem::eItemSubcategory, int) const (68B) */

namespace BBI {

class InventoryItem {
public:
    enum eItemSubcategory {};
};

class InventoryItems {
public:
    InventoryItem* m_items[36];

    int GetBuilderItemIndex(InventoryItem::eItemSubcategory subcat, int n) const;
    InventoryItem* GetBuilderItem(InventoryItem::eItemSubcategory subcat, int n) const;
};

InventoryItem* InventoryItems::GetBuilderItem(InventoryItem::eItemSubcategory subcat, int n) const {
    int index = GetBuilderItemIndex(subcat, n);
    if (index == -1) return 0;
    return m_items[index];
}

}
