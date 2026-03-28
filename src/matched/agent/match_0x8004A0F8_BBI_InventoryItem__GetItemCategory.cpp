/* 0x8004A0F8 (12 bytes) - BBI::InventoryItem::GetItemCategory(void) const */
namespace BBI {
class InventoryItem {
public:
    signed char m_itemCategory;
    signed char GetItemCategory(void) const;
};

signed char InventoryItem::GetItemCategory(void) const {
    return m_itemCategory;
}
}
