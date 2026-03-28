// 0x8015ED18 (104 bytes)
// CasClothingUnlocks::ClearRecentlyUnlocked(bool, eBodyPartS2C, unsigned int)

class CasClothingUnlocks { public: void ClearRecentlyUnlocked(bool, eBodyPartS2C, unsigned int); };

__attribute__((naked))
void CasClothingUnlocks::ClearRecentlyUnlocked(bool, eBodyPartS2C, unsigned int) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBF810008\n.long 0x9001001C\n.long 0x7CDF3378\n.long 0x7C7C1B78\n.long 0x7C9E2378\n.long 0x7CBD2B78\n.long 0x7FE4FB78\n.long 0x4800031D\n.long 0x2C030000\n.long 0x41820028\n.long 0x1D3D0028\n.long 0x57C0103A\n.long 0x7C00F214\n.long 0x5400402E\n.long 0x7C00E214\n.long 0x7D290214\n.long 0x7D69F8EE\n.long 0x556B07B8\n.long 0x99690000\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBB810008\n.long 0x38210018\n.long 0x4E800020");
}
