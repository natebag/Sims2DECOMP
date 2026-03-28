/* 0x8004A298 (12 bytes) - BBI::InventoryItem::GetItemCount(void) const */
namespace BBI {
class InventoryItem {
public:
    char pad[1];
    signed char m_itemCount;
    signed char GetItemCount(void) const;
};

signed char InventoryItem::GetItemCount(void) const {
    return m_itemCount;
}
}
