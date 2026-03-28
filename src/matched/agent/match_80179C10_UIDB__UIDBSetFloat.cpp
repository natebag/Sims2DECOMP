// 0x80179C10 (88 bytes)
// UIDB::UIDBSetFloat(char *, float)

class UIDB { public: void UIDBSetFloat(char *, float); };

__attribute__((naked))
void UIDB::UIDBSetFloat(char *, float) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xDBE10008\n.long 0x90010014\n.long 0x800D84E0\n.long 0x7C691B78\n.long 0xFFE00890\n.long 0x38600000\n.long 0x2C000000\n.long 0x41820020\n.long 0x7D234B78\n.long 0x38800066\n.long 0x480000C5\n.long 0x7C631B79\n.long 0x41820008\n.long 0xD3E30008\n.long 0x38600001\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xCBE10008\n.long 0x38210010\n.long 0x4E800020");
}
