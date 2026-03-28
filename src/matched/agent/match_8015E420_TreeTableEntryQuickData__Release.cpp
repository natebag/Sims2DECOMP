// 0x8015E420 (92 bytes)
// TreeTableEntryQuickData::Release(void)

class TreeTableEntryQuickData { public: void Release(void); };

__attribute__((naked))
void TreeTableEntryQuickData::Release(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C6B1B78\n.long 0x812B0018\n.long 0x3869FFFF\n.long 0x906B0018\n.long 0x2C030000\n.long 0x4082002C\n.long 0x2C0B0000\n.long 0x41820020\n.long 0x812B0000\n.long 0x38800003\n.long 0xA86901E8\n.long 0x800901EC\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
