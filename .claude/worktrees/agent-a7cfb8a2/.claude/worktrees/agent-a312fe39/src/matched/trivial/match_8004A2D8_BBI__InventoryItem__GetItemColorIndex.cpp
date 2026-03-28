// 0x8004A2D8 (8 bytes)
class BBI {
public:
    class InventoryItem {
    public:
        int GetItemColorIndex();
    };
};

int BBI::InventoryItem::GetItemColorIndex() {
    return *(unsigned char*)((char*)this + 0x2);
}
