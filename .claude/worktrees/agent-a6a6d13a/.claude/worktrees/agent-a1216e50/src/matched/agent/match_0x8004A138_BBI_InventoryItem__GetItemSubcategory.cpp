/* 0x8004A138 (12 bytes) - BBI::InventoryItem::GetItemSubcategory(void) const */
namespace BBI {
class InventoryItem {
public:
    char pad[3];
    signed char m_itemSubcategory;
    signed char GetItemSubcategory(void) const;
};

signed char InventoryItem::GetItemSubcategory(void) const {
    return m_itemSubcategory;
}
}
