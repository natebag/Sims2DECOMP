// 0x80179AC8 (80 bytes)
// UIDB::UIDBGetInt(char *)

class UIDB { public: void UIDBGetInt(char *); };

__attribute__((naked))
void UIDB::UIDBGetInt(char *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x800D84E0\n.long 0x7C691B78\n.long 0x38600000\n.long 0x2C000000\n.long 0x41820024\n.long 0x7D234B78\n.long 0x38800069\n.long 0x48000215\n.long 0x7C631B79\n.long 0x4082000C\n.long 0x38600000\n.long 0x48000008\n.long 0x80630008\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
