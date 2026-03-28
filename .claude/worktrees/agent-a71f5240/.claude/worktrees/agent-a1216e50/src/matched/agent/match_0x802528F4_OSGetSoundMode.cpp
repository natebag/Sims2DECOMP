/* OSGetSoundMode - 128 bytes at 0x802528F4 */

__attribute__((naked))
void func_0x802528F4() {
    asm volatile(
        ".long 0x7C0802A6\n"
        ".long 0x3C60804A\n"
        ".long 0x90010004\n"
        ".long 0x9421FFE0\n"
        ".long 0x93E1001C\n"
        ".long 0x3BE39F80\n"
        ".long 0x4BFFCC45\n"
        ".long 0x801F0048\n"
        ".long 0x389F0048\n"
        ".long 0x2C000000\n"
        ".long 0x41820010\n"
        ".long 0x4BFFCC59\n"
        ".long 0x3BE00000\n"
        ".long 0x48000010\n"
        ".long 0x907F0044\n"
        ".long 0x38000001\n"
        ".long 0x90040000\n"
        ".long 0x881F0013\n"
        ".long 0x5400077B\n"
        ".long 0x4182000C\n"
        ".long 0x3BE00001\n"
        ".long 0x48000008\n"
        ".long 0x3BE00000\n"
        ".long 0x38600000\n"
        ".long 0x38800000\n"
        ".long 0x4BFFF869\n"
        ".long 0x7FE3FB78\n"
        ".long 0x80010024\n"
        ".long 0x83E1001C\n"
        ".long 0x38210020\n"
        ".long 0x7C0803A6\n"
        "blr\n"
    );
}
