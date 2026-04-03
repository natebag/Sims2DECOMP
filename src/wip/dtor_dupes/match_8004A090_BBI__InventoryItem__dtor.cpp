/* BBI::InventoryItem::~InventoryItem(void) at 0x8004A090 (52B) */

extern int BBI_InventoryItem_vtable[];
void __builtin_delete(void *ptr);

void BBI_InventoryItem_dtor(void *self, int delFlag) {
    *(int *)((char *)self + 8) = (int)BBI_InventoryItem_vtable;
    if (delFlag & 1) {
        __builtin_delete(self);
    }
}
