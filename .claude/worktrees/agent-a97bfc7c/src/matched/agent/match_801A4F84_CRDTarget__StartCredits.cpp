// 0x801A4F84 (124 bytes)
// CRDTarget::StartCredits(void)

class CRDTarget { public: void StartCredits(void); };

__attribute__((naked))
void CRDTarget::StartCredits(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x801F00A0\n.long 0x2C000000\n.long 0x41820014\n.long 0x2C000001\n.long 0x40820034\n.long 0x7FE3FB78\n.long 0x48000051\n.long 0x816D985C\n.long 0x3C80804B\n.long 0x3884D210\n.long 0x812B0000\n.long 0xA8690028\n.long 0x8009002C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0xD03F00A4\n.long 0x39200001\n.long 0x38000000\n.long 0x901F009C\n.long 0x913F00A0\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
