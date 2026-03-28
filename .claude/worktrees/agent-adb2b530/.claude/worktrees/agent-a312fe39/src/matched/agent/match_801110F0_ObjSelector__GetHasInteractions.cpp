// 0x801110F0 (88 bytes)
// ObjSelector::GetHasInteractions(void)

class ObjSelector { public: void GetHasInteractions(void); };

__attribute__((naked))
void ObjSelector::GetHasInteractions(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x4800054D\n.long 0x7C6B1B79\n.long 0x4082000C\n.long 0x38600000\n.long 0x4800002C\n.long 0x812B0000\n.long 0xA8690070\n.long 0x80090074\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x2C030000\n.long 0x38600001\n.long 0x40820008\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
