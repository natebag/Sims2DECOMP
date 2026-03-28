// 0x80179BB0 (96 bytes)
// UIDB::UIDBSetInt(char *, int)

class UIDB { public: void UIDBSetInt(char *, int); };

__attribute__((naked))
void UIDB::UIDBSetInt(char *, int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x800D84E0\n.long 0x7C691B78\n.long 0x7C9F2378\n.long 0x38600000\n.long 0x2C000000\n.long 0x41820028\n.long 0x7D234B78\n.long 0x38800069\n.long 0x48000125\n.long 0x7C631B79\n.long 0x4082000C\n.long 0x38600000\n.long 0x4800000C\n.long 0x93E30008\n.long 0x38600001\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
