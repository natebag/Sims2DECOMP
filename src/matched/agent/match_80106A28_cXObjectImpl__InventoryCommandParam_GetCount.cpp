// 0x80106A28 (100 bytes)
// cXObjectImpl::InventoryCommandParam_GetCount(InventoryCommandParam &)

class cXObjectImpl { public: void InventoryCommandParam_GetCount(InventoryCommandParam &); };

__attribute__((naked))
void cXObjectImpl::InventoryCommandParam_GetCount(InventoryCommandParam &) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x90010014\n.long 0xA1640006\n.long 0x39200000\n.long 0x88040005\n.long 0x38C00000\n.long 0xB121000C\n.long 0x7D650734\n.long 0x5404063E\n.long 0x98010008\n.long 0xB161000A\n.long 0x38E00000\n.long 0x3901000C\n.long 0x48004045\n.long 0x2C03FFFF\n.long 0x40820010\n.long 0x2C04FFFF\n.long 0x38600000\n.long 0x41820008\n.long 0xA861000C\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x38210010\n.long 0x4E800020");
}
