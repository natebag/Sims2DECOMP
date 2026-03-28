/* Neighbor::StartNewTree(unsigned int) at 0x800CC380 (152B) */

struct Neighbor { void StartNewTree(); };

__attribute__((naked))
void Neighbor::StartNewTree() {
    asm volatile(
        ".long 0x9421FFD8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBF810018\n"
        ".long 0x9001002C\n"
        ".long 0x7C9C2378\n"
        ".long 0x3D208047\n"
        ".long 0x7C7F1B78\n"
        ".long 0x80895EEC\n"
        ".long 0x38610008\n"
        ".long 0x83BF0194\n"
        ".long 0x1FDC000C\n"
        ".long 0x20DC000C\n"
        ".long 0x7CC63110\n"
        ".long 0x7CC600D0\n"
        ".long 0x7FE5FB78\n"
        ".long 0x4807FE41\n"
        ".long 0x81010008\n"
        ".long 0x39210008\n"
        ".long 0x81490008\n"
        ".long 0x7D7EEA14\n"
        ".long 0x80090004\n"
        ".long 0x7FE4FB78\n"
        ".long 0x7D1EE92E\n"
        ".long 0x914B0008\n"
        ".long 0x900B0004\n"
        ".long 0x807F0194\n"
        ".long 0x7C7E1A14\n"
        ".long 0x4807F35D\n"
        ".long 0x2C030000\n"
        ".long 0x41820010\n"
        ".long 0x7FE3FB78\n"
        ".long 0x7F84E378\n"
        ".long 0x4BFFEF2D\n"
        ".long 0x8001002C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBB810018\n"
        ".long 0x38210028\n"
        ".long 0x4E800020\n"
    );
}
