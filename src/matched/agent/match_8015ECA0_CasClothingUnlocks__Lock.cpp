// 0x8015ECA0 (120 bytes)
// CasClothingUnlocks::Lock(bool, eTattooTextureTypeS2C, unsigned int)

class CasClothingUnlocks { public: void Lock(bool, eTattooTextureTypeS2C, unsigned int); };

__attribute__((naked))
void CasClothingUnlocks::Lock(bool, eTattooTextureTypeS2C, unsigned int) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBF810008\n.long 0x9001001C\n.long 0x7CDF3378\n.long 0x7C7E1B78\n.long 0x7C9D2378\n.long 0x7CBC2B78\n.long 0x7FE4FB78\n.long 0x480003A5\n.long 0x2C030000\n.long 0x41820038\n.long 0x1C1D00F0\n.long 0x1D7C001E\n.long 0x7C00F214\n.long 0x7D4B0214\n.long 0x7D4B5378\n.long 0x7D4AFA14\n.long 0x7D6BFA14\n.long 0x8C0A0A00\n.long 0x60000002\n.long 0x980A0000\n.long 0x8D2B0A00\n.long 0x552907B8\n.long 0x992B0000\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBB810008\n.long 0x38210018\n.long 0x4E800020");
}
