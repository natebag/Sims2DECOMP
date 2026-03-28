// 0x80179A54 (116 bytes)
// UIDB::UIDBShutdown(void)

class UIDB { public: void UIDBShutdown(void); };

__attribute__((naked))
void UIDB::UIDBShutdown(void) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x3D208048\n.long 0x3BC00000\n.long 0x3BE97A14\n.long 0x3BBF0384\n.long 0x801F0004\n.long 0x2C000073\n.long 0x40820024\n.long 0x801F0008\n.long 0x2C000000\n.long 0x41820014\n.long 0x481565B5\n.long 0x809F0008\n.long 0x481572E5\n.long 0x93DF0008\n.long 0x93DF0004\n.long 0x3BFF000C\n.long 0x7C1FE800\n.long 0x4081FFCC\n.long 0x38000000\n.long 0x900D84E0\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
