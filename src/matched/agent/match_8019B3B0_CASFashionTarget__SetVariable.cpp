// 0x8019B3B0 (68 bytes)
// CASFashionTarget::SetVariable(char *, char *)

class CASFashionTarget { public: void SetVariable(char *, char *); };

__attribute__((naked))
void CASFashionTarget::SetVariable(char *, char *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x3C60803F\n.long 0x3863C8B4\n.long 0x480A846D\n.long 0x2C030000\n.long 0x4082000C\n.long 0x7FE3FB78\n.long 0x48000019\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
