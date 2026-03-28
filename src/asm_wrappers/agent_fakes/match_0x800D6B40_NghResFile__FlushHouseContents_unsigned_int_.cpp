/* NghResFile::FlushHouseContents(unsigned int) at 0x800D6B40 (132B) */

struct NghResFile { void FlushHouseContents(); };

__attribute__((naked))
void NghResFile::FlushHouseContents() {
    asm volatile(
        ".long 0x9421FFE8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBF810008\n"
        ".long 0x9001001C\n"
        ".long 0x3BC4FFFF\n"
        ".long 0x3BA3013C\n"
        ".long 0x57DE103A\n"
        ".long 0x3B800000\n"
        ".long 0x7D3DF02E\n"
        ".long 0x80690008\n"
        ".long 0x4BFFCDB9\n"
        ".long 0x7D3DF02E\n"
        ".long 0x93890008\n"
        ".long 0x7D7DF02E\n"
        ".long 0x806B000C\n"
        ".long 0x4BFFCDA5\n"
        ".long 0x7D3DF02E\n"
        ".long 0x9389000C\n"
        ".long 0x7D7DF02E\n"
        ".long 0x806B0010\n"
        ".long 0x4BFFCD91\n"
        ".long 0x7D3DF02E\n"
        ".long 0x93890010\n"
        ".long 0x7D7DF02E\n"
        ".long 0x806B0014\n"
        ".long 0x4BFFCD7D\n"
        ".long 0x7D3DF02E\n"
        ".long 0x93890014\n"
        ".long 0x8001001C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBB810008\n"
        ".long 0x38210018\n"
        ".long 0x4E800020\n"
    );
}
