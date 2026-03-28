// 0x8012C698 (68 bytes)
// cXPerson::CAST_IMPL(void)

class cXPerson { public: void CAST_IMPL(void); };

__attribute__((naked))
void cXPerson::CAST_IMPL(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C6B1B79\n.long 0x4082000C\n.long 0x38600000\n.long 0x4800001C\n.long 0x812B0004\n.long 0xA8690308\n.long 0x8009030C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
