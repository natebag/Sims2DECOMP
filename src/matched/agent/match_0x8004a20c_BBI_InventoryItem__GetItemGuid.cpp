// 0x8004a20c BBI::InventoryItem::GetItemGuid(void) const (8B)

namespace BBI {
struct InventoryItem {
    char pad[0x04];
    int m_guid;
    int GetItemGuid(void) const;
};
}

int BBI::InventoryItem::GetItemGuid(void) const {
    return m_guid;
}
