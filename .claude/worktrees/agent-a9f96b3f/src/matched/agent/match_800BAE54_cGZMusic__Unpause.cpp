// 0x800BAE54 (88 bytes)
// cGZMusic::Unpause(void)

class cGZMusic { public: void Unpause(void); };

__attribute__((naked))
void cGZMusic::Unpause(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x812DA06C\n.long 0x8009040C\n.long 0x7C001800\n.long 0x4082002C\n.long 0x816D983C\n.long 0x812B0000\n.long 0x8009005C\n.long 0xA8690058\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x812DA06C\n.long 0x38000000\n.long 0x90090418\n.long 0x38600001\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
