/* IFFResFile2::GetIndType(short) at 0x800BEAD8 (160B) */

struct IFFResFile2 { void GetIndType(); };

__attribute__((naked))
void IFFResFile2::GetIndType() {
    asm volatile(
        ".long 0x9421FFF0\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFC10008\n"
        ".long 0x90010014\n"
        ".long 0x7C7F1B78\n"
        ".long 0x7C9E2378\n"
        ".long 0x813F000C\n"
        ".long 0xA8690060\n"
        ".long 0x80090064\n"
        ".long 0x7C7F1A14\n"
        ".long 0x7C0803A6\n"
        ".long 0x4E800021\n"
        ".long 0x2C030000\n"
        ".long 0x40820014\n"
        ".long 0x7FE3FB78\n"
        ".long 0x3880FFCF\n"
        ".long 0x48076B15\n"
        ".long 0x48000010\n"
        ".long 0x7FE3FB78\n"
        ".long 0x38800000\n"
        ".long 0x48076B05\n"
        ".long 0x7FE3FB78\n"
        ".long 0x48076AF5\n"
        ".long 0x2C030000\n"
        ".long 0x38600000\n"
        ".long 0x40820028\n"
        ".long 0x807F0138\n"
        ".long 0x7FC4F378\n"
        ".long 0x4BFFEE41\n"
        ".long 0x7C7E1B79\n"
        ".long 0x40820010\n"
        ".long 0x7FE3FB78\n"
        ".long 0x3880FF9C\n"
        ".long 0x48076AD1\n"
        ".long 0x7FC3F378\n"
        ".long 0x80010014\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBC10008\n"
        ".long 0x38210010\n"
        ".long 0x4E800020\n"
    );
}
