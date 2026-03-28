/* Neighbor::InitWantsFears(void) at 0x800CAA40 (136B) */

struct Neighbor { void InitWantsFears(); };

__attribute__((naked))
void Neighbor::InitWantsFears() {
    asm volatile(
        ".long 0x9421FFF0\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFC10008\n"
        ".long 0x90010014\n"
        ".long 0x7C7E1B78\n"
        ".long 0x3BE00000\n"
        ".long 0x48001A8D\n"
        ".long 0x7FE4FB78\n"
        ".long 0x7FC3F378\n"
        ".long 0x4800191D\n"
        ".long 0x3BFF0001\n"
        ".long 0x281F0004\n"
        ".long 0x4081FFEC\n"
        ".long 0x3BE00000\n"
        ".long 0x389F000D\n"
        ".long 0x7FC3F378\n"
        ".long 0x48001901\n"
        ".long 0x3BFF0001\n"
        ".long 0x281F0003\n"
        ".long 0x4081FFEC\n"
        ".long 0x3BE00000\n"
        ".long 0x7FE4FB78\n"
        ".long 0x7FC3F378\n"
        ".long 0x480014E9\n"
        ".long 0x3BFF0001\n"
        ".long 0x281F0006\n"
        ".long 0x4081FFEC\n"
        ".long 0x7FC3F378\n"
        ".long 0x48000019\n"
        ".long 0x80010014\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBC10008\n"
        ".long 0x38210010\n"
        ".long 0x4E800020\n"
    );
}
