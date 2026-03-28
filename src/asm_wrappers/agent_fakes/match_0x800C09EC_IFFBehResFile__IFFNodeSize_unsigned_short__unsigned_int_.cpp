/* IFFBehResFile::IFFNodeSize(unsigned short, unsigned int) at 0x800C09EC (144B) */

struct IFFBehResFile { void IFFNodeSize(); };

__attribute__((naked))
void IFFBehResFile::IFFNodeSize() {
    asm volatile(
        ".long 0x9421FF90\n"
        ".long 0x7C0802A6\n"
        ".long 0xBF61005C\n"
        ".long 0x90010074\n"
        ".long 0x7C9D2378\n"
        ".long 0x3BE00001\n"
        ".long 0x7C7E1B78\n"
        ".long 0x7CBB2B78\n"
        ".long 0x3B800000\n"
        ".long 0x7C1FE840\n"
        ".long 0x41810050\n"
        ".long 0x807E0138\n"
        ".long 0x7F64DB78\n"
        ".long 0x7FE5FB78\n"
        ".long 0x38C00000\n"
        ".long 0x4BFFCCF5\n"
        ".long 0x7C631B79\n"
        ".long 0x41820024\n"
        ".long 0x80A30000\n"
        ".long 0x38810008\n"
        ".long 0x7FC3F378\n"
        ".long 0x4BFFF875\n"
        ".long 0x2C030000\n"
        ".long 0x4082000C\n"
        ".long 0x8001000C\n"
        ".long 0x7F9C0214\n"
        ".long 0x381F0001\n"
        ".long 0x541F043E\n"
        ".long 0x7C1FE840\n"
        ".long 0x4081FFB8\n"
        ".long 0x7F83E378\n"
        ".long 0x80010074\n"
        ".long 0x7C0803A6\n"
        ".long 0xBB61005C\n"
        ".long 0x38210070\n"
        ".long 0x4E800020\n"
    );
}
