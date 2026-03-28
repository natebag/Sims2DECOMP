// 0x800BB19C (88 bytes)
// cGZMusic::reset(void)

class cGZMusic { public: void reset(void); };

__attribute__((naked))
void cGZMusic::reset(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x812DA06C\n.long 0x8149040C\n.long 0x7C0A1800\n.long 0x40820030\n.long 0x816D983C\n.long 0x38000000\n.long 0x900A0008\n.long 0x90090418\n.long 0x9009040C\n.long 0x812B0000\n.long 0xA8690048\n.long 0x8009004C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
