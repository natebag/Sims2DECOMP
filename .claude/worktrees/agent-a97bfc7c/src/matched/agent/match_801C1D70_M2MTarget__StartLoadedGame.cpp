// 0x801C1D70 (112 bytes)
// M2MTarget::StartLoadedGame(void)

class M2MTarget { public: void StartLoadedGame(void); };

__attribute__((naked))
void M2MTarget::StartLoadedGame(void) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C7D1B78\n.long 0x3D208047\n.long 0x801D0114\n.long 0x39295DCC\n.long 0x3BC00000\n.long 0x90090448\n.long 0x93C9044C\n.long 0x4BFCE779\n.long 0xB3DD00CE\n.long 0x3C60803F\n.long 0x93DD00C0\n.long 0x38800005\n.long 0xB3DD00CC\n.long 0x386320DC\n.long 0x4BFB7DF9\n.long 0x7FA3EB78\n.long 0x48000419\n.long 0x38000003\n.long 0x901D0168\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
