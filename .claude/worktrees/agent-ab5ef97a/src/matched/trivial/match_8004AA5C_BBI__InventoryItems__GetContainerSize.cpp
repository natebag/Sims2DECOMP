// 0x8004AA5C (8 bytes)
class BBI {
public:
    class InventoryItems {
    public:
        int GetContainerSize();
    };
};

int BBI::InventoryItems::GetContainerSize() {
    return 36;
}
