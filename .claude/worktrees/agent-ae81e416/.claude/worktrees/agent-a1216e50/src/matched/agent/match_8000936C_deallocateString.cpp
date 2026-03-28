// 0x8000936C (124 bytes)
// deallocateString(void *, unsigned int)

__attribute__((naked))
void deallocateString(void *, unsigned int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x3BC00000\n.long 0x807F0020\n.long 0x93DF0000\n.long 0x2C030000\n.long 0x41820018\n.long 0x3D20804A\n.long 0x8009C064\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x93DF0020\n.long 0x817F0024\n.long 0x2C0B0000\n.long 0x41820024\n.long 0x812B0034\n.long 0x38800003\n.long 0xA8690008\n.long 0x8009000C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x93DF0024\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
