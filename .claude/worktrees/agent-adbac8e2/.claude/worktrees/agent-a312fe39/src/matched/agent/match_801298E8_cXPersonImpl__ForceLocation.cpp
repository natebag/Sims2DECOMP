// 0x801298E8 (76 bytes)
// cXPersonImpl::ForceLocation(void)

class cXPersonImpl { public: void ForceLocation(void); };

__attribute__((naked))
void cXPersonImpl::ForceLocation(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x817E03F4\n.long 0x812B0000\n.long 0x80090044\n.long 0xA8690040\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x38000000\n.long 0xB01E0088\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
