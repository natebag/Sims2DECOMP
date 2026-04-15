/* 0x8004A524 BBI::InventoryItems::RemoveItemsByGuid(int, int, unsigned char) (120B) */

namespace BBI {

class InventoryItem {
public:
    signed char GetItemCount(void) const;
    void SetItemCount(int count);
};

class InventoryItems {
public:
    InventoryItem* GetItemByGuid(int guid, unsigned char flag) const;
    int DeleteItem(InventoryItem* item);
    int RemoveItemsByGuid(int guid, int count, unsigned char flag);
};

int InventoryItems::RemoveItemsByGuid(int guid, int count, unsigned char flag) {
    InventoryItem* item = GetItemByGuid(guid, flag);
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
