/* NghResFile::FlushCharacterData(bool) at 0x800D3FE0 (156B) */

struct NghResFile { void FlushCharacterData(); };

__attribute__((naked))
void NghResFile::FlushCharacterData() {
    asm volatile(
        ".long 0x9421FFE0\n"
        ".long 0x7C0802A6\n"
        ".long 0x7D800026\n"
        ".long 0xBF810010\n"
        ".long 0x90010024\n"
        ".long 0x9181000C\n"
        ".long 0x2D840000\n"
        ".long 0x3BA00000\n"
        ".long 0x4E0C0000\n"
        ".long 0x7C7E1B78\n"
        ".long 0x2C1D0001\n"
        ".long 0x3B800000\n"
        ".long 0x3BE00000\n"
        ".long 0x40920008\n"
        ".long 0x41820018\n"
        ".long 0x813E017C\n"
        ".long 0x7C7F482E\n"
        ".long 0x4BFFF8FD\n"
        ".long 0x813E017C\n"
        ".long 0x7F9F492E\n"
        ".long 0x3BBD0001\n"
        ".long 0x3BFF0004\n"
        ".long 0x2C1D0001\n"
        ".long 0x4081FFD8\n"
        ".long 0x418E0020\n"
        ".long 0x39200024\n"
        ".long 0x387E0220\n"
        ".long 0x7D2903A6\n"
        ".long 0x38000000\n"
        ".long 0x90030000\n"
        ".long 0x3863FFFC\n"
        ".long 0x4200FFF8\n"
        ".long 0x80010024\n"
        ".long 0x8181000C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBB810010\n"
        ".long 0x7D818120\n"
        ".long 0x38210020\n"
        ".long 0x4E800020\n"
    );
}
