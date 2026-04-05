/* BBI::InventoryItems::GetItemAtIndex(int) const at 0x8004AA64 (28B) */

namespace BBI {

struct InventoryItems {
    int items[36];

    int GetItemAtIndex(int index) const;
};

int InventoryItems::GetItemAtIndex(int index) const {
    if (index > 35) return 0;
    return items[index];
}

}
