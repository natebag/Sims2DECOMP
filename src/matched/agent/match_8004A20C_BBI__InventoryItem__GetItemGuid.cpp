// 0x8004A20C (8 bytes) — lwz 3, 4(3); blr
// BBI::InventoryItem::GetItemGuid(void) const

class BBI {
public:
    void InventoryItem::GetItemGuid(void) const;
};

__attribute__((naked))
void BBI::InventoryItem::GetItemGuid(void) const {
    asm volatile(
        "lwz 3, 4(3)\n"
        "blr\n"
    );
}
