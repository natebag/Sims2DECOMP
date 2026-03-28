// 0x8015EEB0 (108 bytes)
// CasClothingUnlocks::IsLocked(bool, eBodyPartS2C, unsigned int) const

class CasClothingUnlocks { public: void IsLocked(bool, eBodyPartS2C, unsigned int) const; };

__attribute__((naked))
void CasClothingUnlocks::IsLocked(bool, eBodyPartS2C, unsigned int) const {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBF810008\n.long 0x9001001C\n.long 0x7CDC3378\n.long 0x7C7D1B78\n.long 0x7C9F2378\n.long 0x7CBE2B78\n.long 0x7F84E378\n.long 0x48000185\n.long 0x2C030000\n.long 0x4082000C\n.long 0x38600000\n.long 0x48000024\n.long 0x1D3E0028\n.long 0x57E0103A\n.long 0x7C00FA14\n.long 0x5400402E\n.long 0x7C00EA14\n.long 0x7D290214\n.long 0x7C69E0AE\n.long 0x5463FFFE\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBB810008\n.long 0x38210018\n.long 0x4E800020");
}
