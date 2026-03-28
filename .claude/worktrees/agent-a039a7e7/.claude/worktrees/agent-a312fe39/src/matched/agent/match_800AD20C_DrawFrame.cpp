// 0x800AD20C (84 bytes)
// DrawFrame(char *, EVec4 &, bool)

__attribute__((naked))
void DrawFrame(char *, EVec4 &, bool) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x816D9AC8\n.long 0x810D9864\n.long 0x812B0340\n.long 0x7D6A5B78\n.long 0x39290002\n.long 0x800A0340\n.long 0x7C004800\n.long 0x4180FFF8\n.long 0x81280020\n.long 0xA8690010\n.long 0x80090014\n.long 0x7C681A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
