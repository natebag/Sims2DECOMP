// 0x801B0D5C (80 bytes)
// FAMTarget::DoesFamilyExistInFamilyChoice(int)

class FAMTarget { public: void DoesFamilyExistInFamilyChoice(int); };

__attribute__((naked))
void FAMTarget::DoesFamilyExistInFamilyChoice(int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x48000045\n.long 0x816DAC1C\n.long 0x7C641B78\n.long 0x812B0000\n.long 0xA8690120\n.long 0x80090124\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x2C030000\n.long 0x38600001\n.long 0x40820008\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
