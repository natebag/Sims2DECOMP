// 0x8004AFA8 (68B) BBI::InventoryItems::GetNewItemIndex()

struct InventoryItem {};

struct BBI_InventoryItems {
    InventoryItem* m_items[36];
    int GetNewItemIndex() const;
};

int BBI_InventoryItems::GetNewItemIndex() const {
    int result = -1;
    for (int i = 0; i <= 35; i++) {
        if (m_items[i] == 0) {
            result = i;
            break;
        }
    }
    return result;
}
