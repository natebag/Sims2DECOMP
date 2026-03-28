/* IFFResFile2::ClearMap(StringBuffer &) at 0x800BE310 (144B) */

struct IFFResFile2 { void ClearMap(); };

__attribute__((naked))
void IFFResFile2::ClearMap() {
    asm volatile(
        ".long 0x9421FEC8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFC10130\n"
        ".long 0x9001013C\n"
        ".long 0x7C7E1B78\n"
        ".long 0x7C9F2378\n"
        ".long 0x813E000C\n"
        ".long 0xA8690060\n"
        ".long 0x80090064\n"
        ".long 0x7C7E1A14\n"
        ".long 0x7C0803A6\n"
        ".long 0x4E800021\n"
        ".long 0x2C030000\n"
        ".long 0x3860FFD1\n"
        ".long 0x40820044\n"
        ".long 0x38610008\n"
        ".long 0x4BFE7C55\n"
        ".long 0x38610008\n"
        ".long 0x7FE4FB78\n"
        ".long 0x4BFE7D01\n"
        ".long 0x38810008\n"
        ".long 0x38A00000\n"
        ".long 0x7FC3F378\n"
        ".long 0x48000035\n"
        ".long 0x7C7E1B78\n"
        ".long 0x38610008\n"
        ".long 0x4BFE7DFD\n"
        ".long 0x38610008\n"
        ".long 0x38800002\n"
        ".long 0x4BFE7C81\n"
        ".long 0x7FC3F378\n"
        ".long 0x8001013C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBC10130\n"
        ".long 0x38210138\n"
        ".long 0x4E800020\n"
    );
}
