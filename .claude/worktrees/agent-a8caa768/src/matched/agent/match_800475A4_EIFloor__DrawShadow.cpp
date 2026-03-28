// 0x800475A4 (92 bytes)
// EIFloor::DrawShadow(ELevelDrawData &)

class EIFloor { public: void DrawShadow(ELevelDrawData &); };

__attribute__((naked))
void EIFloor::DrawShadow(ELevelDrawData &) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x83E30104\n.long 0x83C40098\n.long 0x2C1F0000\n.long 0x4182002C\n.long 0x813E0070\n.long 0x809F0004\n.long 0xA86900B8\n.long 0x800900BC\n.long 0x7C7E1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x83FF0000\n.long 0x2C1F0000\n.long 0x4082FFDC\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
