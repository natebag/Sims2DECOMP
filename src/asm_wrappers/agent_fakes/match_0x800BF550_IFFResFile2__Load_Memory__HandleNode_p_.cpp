/* IFFResFile2::Load(Memory::HandleNode *) at 0x800BF550 (128B) */

struct IFFResFile2 { void Load(); };

__attribute__((naked))
void IFFResFile2::Load() {
    asm volatile(
        ".long 0x9421FFF0\n"
        ".long 0x7C0802A6\n"
        ".long 0x93E1000C\n"
        ".long 0x90010014\n"
        ".long 0x7C7F1B78\n"
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
        ".long 0x480760A1\n"
        ".long 0x48000010\n"
        ".long 0x7FE3FB78\n"
        ".long 0x38800000\n"
        ".long 0x48076091\n"
        ".long 0x7FE3FB78\n"
        ".long 0x48076081\n"
        ".long 0x2C030000\n"
        ".long 0x40820010\n"
        ".long 0x7FE3FB78\n"
        ".long 0x3880FFA1\n"
        ".long 0x48076075\n"
        ".long 0x80010014\n"
        ".long 0x7C0803A6\n"
        ".long 0x83E1000C\n"
        ".long 0x38210010\n"
        ".long 0x4E800020\n"
    );
}
