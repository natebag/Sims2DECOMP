/* BBI::InventoryItems::InventoryItems(void) at 0x8004A31C (32B) */

namespace BBI {

struct InventoryItems {
    int items[36];

    InventoryItems(void);
};

InventoryItems::InventoryItems(void) {
    for (int i = 35; i >= 0; i--) {
        items[i] = 0;
    }
}

}
