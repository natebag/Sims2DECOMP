/* 0x8004A248 BBI::InventoryItem::SetItemCount(int) (80B) */

namespace BBI {

class InventoryItem {
public:
    char pad[1];
    signed char m_itemCount;

    signed char GetItemCount(void) const;
    void SetItemCount(int count);
};

void InventoryItem::SetItemCount(int count) {
    GetItemCount();
    if (count < 0) {
        count = 0;
    } else if (count > 99) {
        count = 99;
    }
    m_itemCount = (signed char)count;
}

}
