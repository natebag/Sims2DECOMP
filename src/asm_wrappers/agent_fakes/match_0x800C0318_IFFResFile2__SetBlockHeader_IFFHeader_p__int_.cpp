/* IFFResFile2::SetBlockHeader(IFFHeader *, int) at 0x800C0318 (136B) */

struct IFFResFile2 { void SetBlockHeader(); };

__attribute__((naked))
void IFFResFile2::SetBlockHeader() {
    asm volatile(
        ".long 0x9421FFE0\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFA10014\n"
        ".long 0x90010024\n"
        ".long 0x7C7F1B78\n"
        ".long 0x38000001\n"
        ".long 0x813F0140\n"
        ".long 0x7C9D2378\n"
        ".long 0x7CBE2B78\n"
        ".long 0x901F0144\n"
        ".long 0x2C090000\n"
        ".long 0x41820018\n"
        ".long 0x389F0010\n"
        ".long 0x38A00000\n"
        ".long 0x4BFFE051\n"
        ".long 0x7C631B79\n"
        ".long 0x40820034\n"
        ".long 0x3BFF0010\n"
        ".long 0x7FC4F378\n"
        ".long 0x7FE3FB78\n"
        ".long 0x4BFE5F31\n"
        ".long 0x7C631B79\n"
        ".long 0x4082001C\n"
        ".long 0x3800004C\n"
        ".long 0x7FE3FB78\n"
        ".long 0x90010008\n"
        ".long 0x7FA4EB78\n"
        ".long 0x38A10008\n"
        ".long 0x4BFE5901\n"
        ".long 0x80010024\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBA10014\n"
        ".long 0x38210020\n"
        ".long 0x4E800020\n"
    );
}
