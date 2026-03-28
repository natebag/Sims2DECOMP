/* cGZSnd::FadeVolume(int, int, unsigned int) at 0x800BA79C (128B) */

struct cGZSnd { void FadeVolume(); };

__attribute__((naked))
void cGZSnd::FadeVolume() {
    asm volatile(
        ".long 0x9421FFF0\n"
        ".long 0x7C0802A6\n"
        ".long 0x90010014\n"
        ".long 0x7C681B78\n"
        ".long 0x7CA42B78\n"
        ".long 0x28060032\n"
        ".long 0x40800008\n"
        ".long 0x38C00032\n"
        ".long 0x3C004330\n"
        ".long 0x90C1000C\n"
        ".long 0x3D20803E\n"
        ".long 0xC9A99D08\n"
        ".long 0x3D40803E\n"
        ".long 0x90010008\n"
        ".long 0x7D695B78\n"
        ".long 0xC16A9D10\n"
        ".long 0x7D034378\n"
        ".long 0xC8010008\n"
        ".long 0xFC006828\n"
        ".long 0xFC000018\n"
        ".long 0xEC005824\n"
        ".long 0xFDA00090\n"
        ".long 0xFD80681E\n"
        ".long 0xD9810008\n"
        ".long 0x8121000C\n"
        ".long 0x91280034\n"
        ".long 0x4BFFFEAD\n"
        ".long 0x38600001\n"
        ".long 0x80010014\n"
        ".long 0x7C0803A6\n"
        ".long 0x38210010\n"
        ".long 0x4E800020\n"
    );
}
