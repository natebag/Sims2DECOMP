// 0x8015F078 (92 bytes)
// CasClothingUnlocks::ClearUnlocks(void)

class CasClothingUnlocks { public: void ClearUnlocks(void); };

__attribute__((naked))
void CasClothingUnlocks::ClearUnlocks(void) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFC10010\n.long 0x9001001C\n.long 0x7C7E1B78\n.long 0x38000002\n.long 0x98010008\n.long 0x38800002\n.long 0x38A00A00\n.long 0x480E4549\n.long 0x88810008\n.long 0x38A001E0\n.long 0x387E0A00\n.long 0x480E4539\n.long 0x7FC3F378\n.long 0x38800000\n.long 0x38A00000\n.long 0x48000111\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBC10010\n.long 0x38210018\n.long 0x4E800020");
}
