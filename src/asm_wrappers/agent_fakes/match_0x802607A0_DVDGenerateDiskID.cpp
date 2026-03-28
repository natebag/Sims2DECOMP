/* DVDGenerateDiskID - 128 bytes at 0x802607A0 */

__attribute__((naked))
void func_0x802607A0() {
    asm volatile(
        ".long 0x7C0802A6\n"
        ".long 0x90010004\n"
        ".long 0x9421FFD0\n"
        ".long 0xBF61001C\n"
        ".long 0x3B840000\n"
        ".long 0x3BA50000\n"
        ".long 0x3B630000\n"
        ".long 0x3BC60000\n"
        ".long 0x3BE70000\n"
        ".long 0x38800000\n"
        ".long 0x38A00020\n"
        ".long 0x4BFE2E19\n"
        ".long 0x281C0000\n"
        ".long 0x41820014\n"
        ".long 0x387B0000\n"
        ".long 0x389C0000\n"
        ".long 0x38A00004\n"
        ".long 0x4BFE3389\n"
        ".long 0x281D0000\n"
        ".long 0x41820014\n"
        ".long 0x389D0000\n"
        ".long 0x387B0004\n"
        ".long 0x38A00002\n"
        ".long 0x4BFE3371\n"
        ".long 0x9BDB0006\n"
        ".long 0x7F63DB78\n"
        ".long 0x9BFB0007\n"
        ".long 0x80010034\n"
        ".long 0xBB61001C\n"
        ".long 0x38210030\n"
        ".long 0x7C0803A6\n"
        "blr\n"
    );
}
