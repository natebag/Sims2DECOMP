// 0x801C2E28 (80 bytes)
// M2MTarget::PrepareNewGame(void)

class M2MTarget { public: void PrepareNewGame(void); };

__attribute__((naked))
void M2MTarget::PrepareNewGame(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x38000001\n.long 0x39200005\n.long 0x3C60803F\n.long 0x901E0180\n.long 0x386320DC\n.long 0x913E011C\n.long 0x38800007\n.long 0x4BFB6D59\n.long 0x38000003\n.long 0x901E0168\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
