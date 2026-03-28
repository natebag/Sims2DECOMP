/* IFFResFile2::Reopen(void) at 0x800BE834 (152B) */

struct IFFResFile2 { void Reopen(); };

__attribute__((naked))
void IFFResFile2::Reopen() {
    asm volatile(
        ".long 0x9421FED8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBF810118\n"
        ".long 0x9001012C\n"
        ".long 0x3BE10008\n"
        ".long 0x7C7D1B78\n"
        ".long 0x83DD014C\n"
        ".long 0x389F0008\n"
        ".long 0x38A00104\n"
        ".long 0x7FE3FB78\n"
        ".long 0x4BFE7D51\n"
        ".long 0x3B800000\n"
        ".long 0x7FC4F378\n"
        ".long 0x38A0FFFF\n"
        ".long 0x7FE3FB78\n"
        ".long 0x4BFE7F39\n"
        ".long 0x807D014C\n"
        ".long 0x482129A9\n"
        ".long 0x939D014C\n"
        ".long 0x7FE3FB78\n"
        ".long 0x4BFE7D69\n"
        ".long 0x2C030000\n"
        ".long 0x41820028\n"
        ".long 0x813D000C\n"
        ".long 0x7FE4FB78\n"
        ".long 0xA8690028\n"
        ".long 0x8009002C\n"
        ".long 0x7C7D1A14\n"
        ".long 0x7C0803A6\n"
        ".long 0x4E800021\n"
        ".long 0x939D013C\n"
        ".long 0x48000008\n"
        ".long 0x3860FFCE\n"
        ".long 0x8001012C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBB810118\n"
        ".long 0x38210128\n"
        ".long 0x4E800020\n"
    );
}
