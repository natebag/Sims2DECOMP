/* 0x8004A800 BBI::InventoryItems::CountItemsByGuid(int) const (120B) */

namespace BBI {

class InventoryItem {
public:
    int GetItemGuid(void) const;
    signed char GetItemCount(void) const;
};

class InventoryItems {
public:
    InventoryItem* m_items[36];

    int GetContainerSize(void) const;
    int CountItemsByGuid(int guid) const;
};

int InventoryItems::CountItemsByGuid(int guid) const {
    int total = 0;
    int size = GetContainerSize();
    if (total < size) {
        for (int i = 0; i < size; i++) {
            InventoryItem* item = m_items[i];
            if (item != 0 && item->GetItemGuid() == guid) {
                total += m_items[i]->GetItemCount();
            }
        }
    }
    return total;
}

}
