// 0x801476E0 (76 bytes)
// TreeSimImpl::GetISimInstance(void)

class TreeSimImpl { public: void GetISimInstance(void); };

__attribute__((naked))
void TreeSimImpl::GetISimInstance(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81230000\n.long 0x81690010\n.long 0x2C0B0000\n.long 0x4082000C\n.long 0x38600000\n.long 0x4800001C\n.long 0x812B0000\n.long 0xA8690028\n.long 0x8009002C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
