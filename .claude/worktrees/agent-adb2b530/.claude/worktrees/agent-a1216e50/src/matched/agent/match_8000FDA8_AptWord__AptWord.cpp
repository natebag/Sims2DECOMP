// 0x8000FDA8 (124 bytes)
// AptWord::AptWord(void)

class AptWord { public: void AptWord(void); };

__attribute__((naked))
void AptWord::AptWord(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x3D60803D\n.long 0x3D20803D\n.long 0xC00BD8A0\n.long 0x39410008\n.long 0xC1A9D8A4\n.long 0x3D608046\n.long 0xD0010008\n.long 0x7C691B78\n.long 0xD00A0004\n.long 0x396BAD88\n.long 0x9169002C\n.long 0x38000000\n.long 0x80C10008\n.long 0x80EA0004\n.long 0xD1A10008\n.long 0xD1AA0004\n.long 0x90090018\n.long 0x810A0004\n.long 0x81610008\n.long 0x90C9001C\n.long 0x90E90020\n.long 0x91690024\n.long 0x91090028\n.long 0x90090000\n.long 0x90090008\n.long 0x9009000C\n.long 0x90090010\n.long 0x90090014\n.long 0x38210010\n.long 0x4E800020");
}
