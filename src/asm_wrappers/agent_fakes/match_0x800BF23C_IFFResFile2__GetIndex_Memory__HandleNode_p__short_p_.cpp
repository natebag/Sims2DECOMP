/* IFFResFile2::GetIndex(Memory::HandleNode *, short *) at 0x800BF23C (136B) */

struct IFFResFile2 { void GetIndex(); };

__attribute__((naked))
void IFFResFile2::GetIndex() {
    asm volatile(
        ".long 0x9421FFE8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFA1000C\n"
        ".long 0x9001001C\n"
        ".long 0x7C7F1B78\n"
        ".long 0x7CBD2B78\n"
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
        ".long 0x480763B1\n"
        ".long 0x48000010\n"
        ".long 0x7FE3FB78\n"
        ".long 0x38800000\n"
        ".long 0x480763A1\n"
        ".long 0x7FE3FB78\n"
        ".long 0x48076391\n"
        ".long 0x7C7E1B79\n"
        ".long 0x40820014\n"
        ".long 0x7FE3FB78\n"
        ".long 0x3880FFA1\n"
        ".long 0x48076385\n"
        ".long 0xB3DD0000\n"
        ".long 0x8001001C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBA1000C\n"
        ".long 0x38210018\n"
        ".long 0x4E800020\n"
    );
}
