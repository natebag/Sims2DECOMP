/* 0x8004A7A0 BBI::InventoryItems::GetItemCount(void) const (96B) */

namespace BBI {

class InventoryItem {};

class InventoryItems {
public:
    InventoryItem* m_items[36];

    int GetContainerSize(void) const;
    int GetItemCount(void) const;
};

int InventoryItems::GetItemCount(void) const {
    int count = 0;
    int size = GetContainerSize();
    if (count < size) {
        InventoryItem* const* p = m_items;
        for (int i = 0; i < size; i++) {
            if (*p++ != 0) count++;
        }
    }
    return count;
}

}
