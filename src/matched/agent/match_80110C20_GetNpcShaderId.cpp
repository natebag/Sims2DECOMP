// 0x80110C20 (96 bytes)
// GetNpcShaderId(int, bool)

__attribute__((naked))
void GetNpcShaderId(int, bool) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C9F2378\n.long 0x3D208047\n.long 0x7C641B78\n.long 0x38695DCC\n.long 0x4BF2F2CD\n.long 0x7C691B79\n.long 0x4082000C\n.long 0x38600000\n.long 0x4800001C\n.long 0x2C1F0000\n.long 0x41820010\n.long 0x80690008\n.long 0x2C030000\n.long 0x40820008\n.long 0x80690004\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
