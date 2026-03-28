// 0x801B0D1C (64 bytes)
// FAMTarget::GetFamilyInFamilyList(int)

class FAMTarget { public: void GetFamilyInFamilyList(int); };

__attribute__((naked))
void FAMTarget::GetFamilyInFamilyList(int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x48000085\n.long 0x816DAC1C\n.long 0x7C641B78\n.long 0x812B0000\n.long 0xA8690120\n.long 0x80090124\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
