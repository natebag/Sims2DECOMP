// 0x8015230C (80 bytes)
// ValidateTheWorld(void)

__attribute__((naked))
void ValidateTheWorld(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x83EDAC10\n.long 0x2C1F0000\n.long 0x41820024\n.long 0x807F003C\n.long 0x2C030000\n.long 0x41820008\n.long 0x4BEF6FB5\n.long 0x807F0040\n.long 0x2C030000\n.long 0x41820008\n.long 0x4BFC3EF9\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
