/* 0x8004ABDC BBI::InventoryItems::RemoveBuilderItem(BBI::InventoryItem::eItemSubcategory, int, int) (116B) */

namespace BBI {

class InventoryItem {
public:
    enum eItemSubcategory {};

    signed char GetItemCount(void) const;
    void SetItemCount(int count);
};

class InventoryItems {
public:
    InventoryItem* GetBuilderItem(InventoryItem::eItemSubcategory subcat, int n) const;
    int DeleteItem(InventoryItem* item);
    int RemoveBuilderItem(InventoryItem::eItemSubcategory subcat, int n, int count);
};

int InventoryItems::RemoveBuilderItem(InventoryItem::eItemSubcategory subcat, int n, int count) {
    InventoryItem* item = GetBuilderItem(subcat, n);
    if (item == 0) return 0;
    int newCount = item->GetItemCount() - count;
    if (newCount > 0) {
        item->SetItemCount(newCount);
    } else {
        count = item->GetItemCount();
        DeleteItem(item);
    }
    return count;
}

}
