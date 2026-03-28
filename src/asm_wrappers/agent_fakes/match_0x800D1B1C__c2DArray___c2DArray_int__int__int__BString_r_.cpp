/* _c2DArray::_c2DArray(int, int, int, BString &) at 0x800D1B1C (140B) */

struct _c2DArray { _c2DArray(int); };

__attribute__((naked))
_c2DArray::_c2DArray(int) {
    asm volatile(
        ".long 0x9421FFE0\n"
        ".long 0x7C0802A6\n"
        ".long 0xBF410008\n"
        ".long 0x90010024\n"
        ".long 0x7C7E1B78\n"
        ".long 0x7CDA3378\n"
        ".long 0x7CFC3B78\n"
        ".long 0x7CBB2B78\n"
        ".long 0x7C9D2378\n"
        ".long 0x387E0010\n"
        ".long 0x4BFCBBB5\n"
        ".long 0x3920FFFF\n"
        ".long 0x38000000\n"
        ".long 0x93BE0014\n"
        ".long 0x7FC3F378\n"
        ".long 0x913E0008\n"
        ".long 0x901E000C\n"
        ".long 0x913E0004\n"
        ".long 0x480000C5\n"
        ".long 0x7F84E378\n"
        ".long 0x7FC3F378\n"
        ".long 0x480008ED\n"
        ".long 0x7F45D378\n"
        ".long 0x7F64DB78\n"
        ".long 0x7FC3F378\n"
        ".long 0x48000345\n"
        ".long 0x7FC3F378\n"
        ".long 0x38800000\n"
        ".long 0x480002ED\n"
        ".long 0x7FC3F378\n"
        ".long 0x80010024\n"
        ".long 0x7C0803A6\n"
        ".long 0xBB410008\n"
        ".long 0x38210020\n"
        ".long 0x4E800020\n"
    );
}
