// 0x8004AA5C (8 bytes) — li 3, 36; blr
// BBI::InventoryItems::GetContainerSize(void) const

class BBI {
public:
    void InventoryItems::GetContainerSize(void) const;
};

__attribute__((naked))
void BBI::InventoryItems::GetContainerSize(void) const {
    asm volatile(
        "li 3, 36\n"
        "blr\n"
    );
}
