/* Neighbor::FindDuplicateBookmark(WantFear::Bookmark &) const at 0x800CAED4 (132B) */

struct Neighbor { void FindDuplicateBookmark(); };

__attribute__((naked))
void Neighbor::FindDuplicateBookmark() {
    asm volatile(
        ".long 0x9421FFE8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBF810008\n"
        ".long 0x9001001C\n"
        ".long 0x7C7C1B78\n"
        ".long 0x7C9D2378\n"
        ".long 0x3BE00000\n"
        ".long 0x3BC00000\n"
        ".long 0x813C0194\n"
        ".long 0x39600001\n"
        ".long 0x7C7E4A14\n"
        ".long 0x80030004\n"
        ".long 0x2C000000\n"
        ".long 0x40820008\n"
        ".long 0x39600000\n"
        ".long 0x2C0B0000\n"
        ".long 0x4182001C\n"
        ".long 0x7FA4EB78\n"
        ".long 0x4807FD9D\n"
        ".long 0x2C030000\n"
        ".long 0x4182000C\n"
        ".long 0x7FE3FB78\n"
        ".long 0x48000018\n"
        ".long 0x3BFF0001\n"
        ".long 0x3BDE000C\n"
        ".long 0x281F0013\n"
        ".long 0x4081FFB8\n"
        ".long 0x3860FFFF\n"
        ".long 0x8001001C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBB810008\n"
        ".long 0x38210018\n"
        ".long 0x4E800020\n"
    );
}
