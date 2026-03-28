/* Neighbor::Neighbor(Neighbor &) at 0x800C8E10 (132B) */

struct Neighbor { Neighbor(int); };

__attribute__((naked))
Neighbor::Neighbor(int) {
    asm volatile(
        ".long 0x9421FFE0\n"
        ".long 0x7C0802A6\n"
        ".long 0xBF61000C\n"
        ".long 0x90010024\n"
        ".long 0x7C7E1B78\n"
        ".long 0x7C9B2378\n"
        ".long 0x389E0030\n"
        ".long 0x38A00040\n"
        ".long 0x387E0028\n"
        ".long 0x3BA00013\n"
        ".long 0x4BFDD775\n"
        ".long 0x387E0110\n"
        ".long 0x4BFF99BD\n"
        ".long 0x386000F0\n"
        ".long 0x482083A1\n"
        ".long 0x7C7C1B78\n"
        ".long 0x7F9FE378\n"
        ".long 0x7FE3FB78\n"
        ".long 0x48081D19\n"
        ".long 0x3BFF000C\n"
        ".long 0x2C1D0000\n"
        ".long 0x3BBDFFFF\n"
        ".long 0x4082FFEC\n"
        ".long 0x939E0194\n"
        ".long 0x7FC3F378\n"
        ".long 0x7F64DB78\n"
        ".long 0x4800001D\n"
        ".long 0x7FC3F378\n"
        ".long 0x80010024\n"
        ".long 0x7C0803A6\n"
        ".long 0xBB61000C\n"
        ".long 0x38210020\n"
        ".long 0x4E800020\n"
    );
}
