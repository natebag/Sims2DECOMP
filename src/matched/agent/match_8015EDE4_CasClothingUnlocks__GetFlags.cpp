// 0x8015EDE4 (104 bytes)
// CasClothingUnlocks::GetFlags(bool, eBodyPartS2C, unsigned int) const

class CasClothingUnlocks { public: void GetFlags(bool, eBodyPartS2C, unsigned int) const; };

__attribute__((naked))
void CasClothingUnlocks::GetFlags(bool, eBodyPartS2C, unsigned int) const {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBF810008\n.long 0x9001001C\n.long 0x7CDD3378\n.long 0x7C7C1B78\n.long 0x7C9F2378\n.long 0x7CBE2B78\n.long 0x7FA4EB78\n.long 0x48000251\n.long 0x2C030000\n.long 0x4082000C\n.long 0x38600000\n.long 0x48000020\n.long 0x1D3E0028\n.long 0x57E0103A\n.long 0x7C00FA14\n.long 0x5400402E\n.long 0x7D3D4A14\n.long 0x7D290214\n.long 0x7C7C48AE\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBB810008\n.long 0x38210018\n.long 0x4E800020");
}
