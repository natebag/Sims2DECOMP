// 0x800750E8 (104 bytes)
// SimsMemCardWrap::IsCardCorrupted(int, bool &)

class SimsMemCardWrap { public: void IsCardCorrupted(int, bool &); };

__attribute__((naked))
void SimsMemCardWrap::IsCardCorrupted(int, bool &) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0x93E10014\n.long 0x9001001C\n.long 0x7C9F2378\n.long 0x38000000\n.long 0x901F0000\n.long 0x7C641B78\n.long 0x38A10008\n.long 0x816D98F0\n.long 0x812B0000\n.long 0xA86900B0\n.long 0x800900B4\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x2C03FFFC\n.long 0x4082000C\n.long 0x38000001\n.long 0x901F0000\n.long 0x38600001\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0x83E10014\n.long 0x38210018\n.long 0x4E800020");
}
