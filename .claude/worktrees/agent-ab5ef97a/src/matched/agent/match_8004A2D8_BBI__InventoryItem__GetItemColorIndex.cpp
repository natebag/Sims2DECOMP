// 0x8004A2D8 (8 bytes) — lbz 3, 2(3); blr
// BBI::InventoryItem::GetItemColorIndex(void) const

class BBI {
public:
    void InventoryItem::GetItemColorIndex(void) const;
};

__attribute__((naked))
void BBI::InventoryItem::GetItemColorIndex(void) const {
    asm volatile(
        "lbz 3, 2(3)\n"
        "blr\n"
    );
}
