// 0x801069B4 (116 bytes)
// cXObjectImpl::InventoryCommandParam_GetGuid(InventoryCommandParam &)

class cXObjectImpl { public: void InventoryCommandParam_GetGuid(InventoryCommandParam &); };

__attribute__((naked))
void cXObjectImpl::InventoryCommandParam_GetGuid(InventoryCommandParam &) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x90010014\n.long 0x88040004\n.long 0x5409C9FF\n.long 0x40820044\n.long 0xA0040002\n.long 0x3920FFFF\n.long 0xA1640000\n.long 0x38C00000\n.long 0xB121000C\n.long 0x7C050734\n.long 0x5564063E\n.long 0x99610008\n.long 0xB001000A\n.long 0x38E00000\n.long 0x3901000C\n.long 0x480040AD\n.long 0x2C03FFFF\n.long 0x40820014\n.long 0x2C04FFFF\n.long 0x4082000C\n.long 0x38600000\n.long 0x48000008\n.long 0xA861000C\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x38210010\n.long 0x4E800020");
}
