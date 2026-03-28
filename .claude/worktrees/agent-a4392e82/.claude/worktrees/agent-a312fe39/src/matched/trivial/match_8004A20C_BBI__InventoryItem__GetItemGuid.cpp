// 0x8004A20C (8 bytes)
class BBI {
public:
    class InventoryItem {
    public:
        int GetItemGuid();
    };
};

int BBI::InventoryItem::GetItemGuid() {
    return *(int*)((char*)this + 0x4);
}
