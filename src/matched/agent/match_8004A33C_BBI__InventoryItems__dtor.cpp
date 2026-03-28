/* BBI::InventoryItems::~InventoryItems(void) at 0x8004A33C (64B) */

void operator delete(void *);

namespace BBI {

struct InventoryItems {
    void Clear(void);
    ~InventoryItems(void);
};

InventoryItems::~InventoryItems(void) {
    Clear();
}

}
