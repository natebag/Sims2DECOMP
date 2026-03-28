// 0x80030964 (104 bytes)
// DrawSubModelShader(ERC *, ESubModelShader *)

__attribute__((naked))
void DrawSubModelShader(ERC *, ESubModelShader *) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C7E1B78\n.long 0x7C9D2378\n.long 0x813E0070\n.long 0x38800000\n.long 0xC03D0024\n.long 0x800901BC\n.long 0xA86901B8\n.long 0x7C0803A6\n.long 0x7C7E1A14\n.long 0x4E800021\n.long 0x813E0070\n.long 0x809D0000\n.long 0xA86900B8\n.long 0x800900BC\n.long 0x7C7E1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
