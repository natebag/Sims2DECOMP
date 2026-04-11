// 0x8004A090 BBI_InventoryItem::~BBI_InventoryItem (52b)
// FLAGS: -fno-schedule-insns

extern int VT[];
void del_fn(void *);
void d_BBI_InventoryItem_InventoryItem(char *self, int __in_chrg) {
    *(int **)(self + 8) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
