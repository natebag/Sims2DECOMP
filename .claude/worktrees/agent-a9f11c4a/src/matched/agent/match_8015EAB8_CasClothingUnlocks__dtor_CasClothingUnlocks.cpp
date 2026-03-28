// 0x8015EAB8 (104 bytes)
// CasClothingUnlocks::~CasClothingUnlocks(void)

class CasClothingUnlocks { public: void ~CasClothingUnlocks(void); };

__attribute__((naked))
void CasClothingUnlocks::~CasClothingUnlocks(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x35230A00\n.long 0x4182001C\n.long 0x38030BE0\n.long 0x7C090000\n.long 0x41820010\n.long 0x380001E0\n.long 0x7C0903A6\n.long 0x42000000\n.long 0x2C030000\n.long 0x4182001C\n.long 0x38030A00\n.long 0x7C030000\n.long 0x41820010\n.long 0x38000A00\n.long 0x7C0903A6\n.long 0x42000000\n.long 0x70800001\n.long 0x41820008\n.long 0x48172715\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
