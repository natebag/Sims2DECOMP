// 0x8015EFF0 (104 bytes)
// CasClothingUnlocks::IsRecentlyUnlocked(bool, eTattooTextureTypeS2C, unsigned int) const

class CasClothingUnlocks { public: void IsRecentlyUnlocked(bool, eTattooTextureTypeS2C, unsigned int) const; };

__attribute__((naked))
void CasClothingUnlocks::IsRecentlyUnlocked(bool, eTattooTextureTypeS2C, unsigned int) const {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBF810008\n.long 0x9001001C\n.long 0x7CDC3378\n.long 0x7C7F1B78\n.long 0x7C9E2378\n.long 0x7CBD2B78\n.long 0x7F84E378\n.long 0x48000055\n.long 0x2C030000\n.long 0x4082000C\n.long 0x38600000\n.long 0x48000020\n.long 0x1C1E00F0\n.long 0x1D3D001E\n.long 0x7C00FA14\n.long 0x7D290214\n.long 0x7D29E214\n.long 0x88690A00\n.long 0x5463F7FE\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBB810008\n.long 0x38210018\n.long 0x4E800020");
}
