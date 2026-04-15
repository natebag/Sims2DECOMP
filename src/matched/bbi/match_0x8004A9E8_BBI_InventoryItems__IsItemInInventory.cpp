/* 0x8004A9E8 BBI::InventoryItems::IsItemInInventory(int) const (116B) */

namespace BBI {

class InventoryItem {
public:
    int GetItemGuid(void) const;
};

class InventoryItems {
public:
    InventoryItem* m_items[36];

    int GetContainerSize(void) const;
    bool IsItemInInventory(int guid) const;
};

bool InventoryItems::IsItemInInventory(int guid) const {
    InventoryItem* const* p = m_items;
    int i = 0;
    int size = GetContainerSize();
    while (i < size) {
        InventoryItem* item = *p++;
        if (item != 0 && item->GetItemGuid() == guid) {
            return true;
        }
        i++;
    }
    return false;
}

}
