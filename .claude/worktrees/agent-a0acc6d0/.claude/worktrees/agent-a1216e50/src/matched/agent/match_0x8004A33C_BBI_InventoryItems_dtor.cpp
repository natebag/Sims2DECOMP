/* InventoryItems::~InventoryItems(void) - 0x8004A33C (64 bytes) */

struct InventoryItems {
    void Cleanup();
    ~InventoryItems();
};

InventoryItems::~InventoryItems()
{
    Cleanup();
}
