/* _c2DArray::~_c2DArray(void) at 0x800D1BA8 (128B) */

struct _c2DArray { ~_c2DArray(); };

__attribute__((naked))
_c2DArray::~_c2DArray() {
    asm volatile(
        ".long 0x9421FFF0\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFC10008\n"
        ".long 0x90010014\n"
        ".long 0x7C7F1B78\n"
        ".long 0x7C9E2378\n"
        ".long 0x807F000C\n"
        ".long 0x2C030000\n"
        ".long 0x41820010\n"
        ".long 0x812D8338\n"
        ".long 0x7D2803A6\n"
        ".long 0x4E800021\n"
        ".long 0x7FE3FB78\n"
        ".long 0x4800005D\n"
        ".long 0x38000000\n"
        ".long 0x3920FFFF\n"
        ".long 0x901F0014\n"
        ".long 0x387F0010\n"
        ".long 0x901F000C\n"
        ".long 0x38800002\n"
        ".long 0x913F0008\n"
        ".long 0x913F0004\n"
        ".long 0x4BFCBD95\n"
        ".long 0x73C00001\n"
        ".long 0x4182000C\n"
        ".long 0x7FE3FB78\n"
        ".long 0x481FF611\n"
        ".long 0x80010014\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBC10008\n"
        ".long 0x38210010\n"
        ".long 0x4E800020\n"
    );
}
