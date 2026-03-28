// 0x801B3204 (64 bytes)
// FAMTarget::GetFamilyInLot(int)

class FAMTarget { public: void GetFamilyInLot(int); };

__attribute__((naked))
void FAMTarget::GetFamilyInLot(int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x4BFFF7E1\n.long 0x816DAC1C\n.long 0x7C641B78\n.long 0x812B0000\n.long 0xA8690128\n.long 0x8009012C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
