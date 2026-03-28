// 0x8004B1E0 (128 bytes)
// BBI::InventoryItems::GetItemCategoryFromObjDefinition(ObjDefinition *)

class BBI { public: void InventoryItems::GetItemCategoryFromObjDefinition(ObjDefinition *); };

__attribute__((naked))
void BBI::InventoryItems::GetItemCategoryFromObjDefinition(ObjDefinition *) {
    asm volatile(".long 0x7C631B79\n.long 0x4082000C\n.long 0x38600000\n.long 0x4E800020\n.long 0xA8030050\n.long 0x2C000200\n.long 0x4082000C\n.long 0x38600003\n.long 0x4E800020\n.long 0xA8630012\n.long 0x2C030007\n.long 0x41810020\n.long 0x2C030005\n.long 0x40800044\n.long 0x2C030000\n.long 0x4180003C\n.long 0x2C030003\n.long 0x40810034\n.long 0x48000020\n.long 0x2C03000E\n.long 0x41810010\n.long 0x2C030009\n.long 0x40800020\n.long 0x48000014\n.long 0x2C03000F\n.long 0x40820014\n.long 0x38600001\n.long 0x4E800020\n.long 0x38600002\n.long 0x4E800020\n.long 0x38600000\n.long 0x4E800020");
}
