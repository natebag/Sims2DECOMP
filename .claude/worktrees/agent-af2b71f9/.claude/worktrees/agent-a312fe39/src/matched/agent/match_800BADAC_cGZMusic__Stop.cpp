// 0x800BADAC (80 bytes)
// cGZMusic::Stop(void)

class cGZMusic { public: void Stop(void); };

__attribute__((naked))
void cGZMusic::Stop(void) {
    asm volatile(".long 0x816DA06C\n.long 0x7C6A1B78\n.long 0x800B040C\n.long 0x7C005000\n.long 0x40820030\n.long 0x800A0008\n.long 0x2C000000\n.long 0x41820018\n.long 0x39200001\n.long 0x38000000\n.long 0x900B040C\n.long 0x912B0414\n.long 0x912B0410\n.long 0x812DA06C\n.long 0x38000000\n.long 0x90090418\n.long 0x38000000\n.long 0x38600001\n.long 0x900A0008\n.long 0x4E800020");
}
