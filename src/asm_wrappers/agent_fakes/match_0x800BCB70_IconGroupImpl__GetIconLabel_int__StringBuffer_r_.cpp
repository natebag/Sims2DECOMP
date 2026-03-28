/* IconGroupImpl::GetIconLabel(int, StringBuffer &) at 0x800BCB70 (156B) */

struct IconGroupImpl { void GetIconLabel(); };

__attribute__((naked))
void IconGroupImpl::GetIconLabel() {
    asm volatile(
        ".long 0x9421FFE8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFA1000C\n"
        ".long 0x9001001C\n"
        ".long 0x7C7E1B78\n"
        ".long 0x7C9D2378\n"
        ".long 0x7CBF2B78\n"
        ".long 0x4BFFFFE1\n"
        ".long 0x817E0008\n"
        ".long 0x2C0B0000\n"
        ".long 0x41820030\n"
        ".long 0x812B0000\n"
        ".long 0x389D0001\n"
        ".long 0x38A0FFFF\n"
        ".long 0xA8690080\n"
        ".long 0x80090084\n"
        ".long 0x7C6B1A14\n"
        ".long 0x7C0803A6\n"
        ".long 0x4E800021\n"
        ".long 0x7C641B78\n"
        ".long 0x7FE3FB78\n"
        ".long 0x4BFE9B65\n"
        ".long 0x7FE3FB78\n"
        ".long 0x4BFE9A21\n"
        ".long 0x2C030000\n"
        ".long 0x40820024\n"
        ".long 0x3C80803E\n"
        ".long 0x7FE3FB78\n"
        ".long 0x38849E38\n"
        ".long 0x38A0FFFF\n"
        ".long 0x4BFE9A39\n"
        ".long 0x7FE3FB78\n"
        ".long 0x7FA4EB78\n"
        ".long 0x4BFE9E21\n"
        ".long 0x8001001C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBA1000C\n"
        ".long 0x38210018\n"
        ".long 0x4E800020\n"
    );
}
