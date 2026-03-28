// 0x801AD568 (64 bytes)
// E2ETarget::SetDefault(char *, char *)

class E2ETarget { public: void SetDefault(char *, char *); };

__attribute__((naked))
void E2ETarget::SetDefault(char *, char *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x4BE8A371\n.long 0x4BE8BE01\n.long 0xD02D8914\n.long 0x4BE8BDAD\n.long 0xD02D8918\n.long 0x4BE8BEAD\n.long 0xD02D891C\n.long 0x4BFFCFF1\n.long 0xD02D8920\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
