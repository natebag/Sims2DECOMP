/* Neighbor::ShuffleWantFear(int) at 0x800CC554 (128B) */

struct Neighbor { void ShuffleWantFear(); };

__attribute__((naked))
void Neighbor::ShuffleWantFear() {
    asm volatile(
        ".long 0x9421FFF0\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFC10008\n"
        ".long 0x90010014\n"
        ".long 0x7C9F2378\n"
        ".long 0x7C7E1B78\n"
        ".long 0x2C1FFFFF\n"
        ".long 0x40820034\n"
        ".long 0x3BE00000\n"
        ".long 0x7FE4FB78\n"
        ".long 0x7FC3F378\n"
        ".long 0x4BFFFA05\n"
        ".long 0x7FE4FB78\n"
        ".long 0x7FC3F378\n"
        ".long 0x38A00002\n"
        ".long 0x3BFF0001\n"
        ".long 0x4BFFFE85\n"
        ".long 0x281F0006\n"
        ".long 0x4081FFDC\n"
        ".long 0x48000020\n"
        ".long 0x7FE4FB78\n"
        ".long 0x7FC3F378\n"
        ".long 0x4BFFF9D9\n"
        ".long 0x7FC3F378\n"
        ".long 0x7FE4FB78\n"
        ".long 0x38A00002\n"
        ".long 0x4BFFFE5D\n"
        ".long 0x80010014\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBC10008\n"
        ".long 0x38210010\n"
        ".long 0x4E800020\n"
    );
}
