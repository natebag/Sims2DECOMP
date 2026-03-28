// 0x800BAC14 (128 bytes)
// cGZMusic::Release(void)

class cGZMusic { public: void Release(void); };

__attribute__((naked))
void cGZMusic::Release(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x807F0004\n.long 0x2C030001\n.long 0x40820048\n.long 0x813F0000\n.long 0xA8690030\n.long 0x80090034\n.long 0x7C7F1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x2C1F0000\n.long 0x41820020\n.long 0x813F0000\n.long 0x38800003\n.long 0xA8690098\n.long 0x8009009C\n.long 0x7C7F1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x38600000\n.long 0x4800000C\n.long 0x3863FFFF\n.long 0x907F0004\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
