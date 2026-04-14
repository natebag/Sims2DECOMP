// 0x8004a2d8 BBI::InventoryItem::GetItemColorIndex(void) const (8B)

namespace BBI {
struct InventoryItem {
    char pad[0x02];
    unsigned char m_colorIndex;
    unsigned char GetItemColorIndex(void) const;
};
}

unsigned char BBI::InventoryItem::GetItemColorIndex(void) const {
    return m_colorIndex;
}
