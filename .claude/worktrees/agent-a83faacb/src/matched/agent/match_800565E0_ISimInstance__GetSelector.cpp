// 0x800565E0 (72 bytes)
// ISimInstance::GetSelector(void)

class ISimInstance { public: void GetSelector(void); };

__attribute__((naked))
void ISimInstance::GetSelector(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81630328\n.long 0x2C0B0000\n.long 0x4082000C\n.long 0x38600000\n.long 0x4800001C\n.long 0x812B0004\n.long 0xA8690368\n.long 0x8009036C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
