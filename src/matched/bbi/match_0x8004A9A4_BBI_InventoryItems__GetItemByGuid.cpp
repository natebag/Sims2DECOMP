/* 0x8004A9A4 BBI::InventoryItems::GetItemByGuid(int, unsigned char) const (68B) */

namespace BBI {

class InventoryItem {};

class InventoryItems {
public:
    InventoryItem* m_items[36];

    int GetItemIndexByGuid(int guid, unsigned char flag) const;
    InventoryItem* GetItemByGuid(int guid, unsigned char flag) const;
};

InventoryItem* InventoryItems::GetItemByGuid(int guid, unsigned char flag) const {
    int index = GetItemIndexByGuid(guid, flag);
    if (index == -1) return 0;
    return m_items[index];
}

}
