// 0x801C2E78 (124 bytes)
// M2MTarget::PrepareLoadGame(void)

class M2MTarget { public: void PrepareLoadGame(void); };

__attribute__((naked))
void M2MTarget::PrepareLoadGame(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x3BC00001\n.long 0x806D82C8\n.long 0x93DF0180\n.long 0x4BF11239\n.long 0x3D208047\n.long 0x38000000\n.long 0x39295DCC\n.long 0x7FE3FB78\n.long 0x9009044C\n.long 0x90090448\n.long 0x4BFFEE55\n.long 0x2C030000\n.long 0x41820014\n.long 0x38000009\n.long 0x93DF0168\n.long 0x901F011C\n.long 0x48000014\n.long 0x38000008\n.long 0x7FE3FB78\n.long 0x901F011C\n.long 0x4BFFF2FD\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
