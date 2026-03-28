// 0x80129878 (112 bytes)
// cXPersonImpl::IsPersonInFamily(int) const

class cXPersonImpl { public: void IsPersonInFamily(int) const; };

__attribute__((naked))
void cXPersonImpl::IsPersonInFamily(int) const {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x812DAC1C\n.long 0x7C7F1B78\n.long 0x81690000\n.long 0xA86B0120\n.long 0x800B0124\n.long 0x7C691A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x7C6B1B79\n.long 0x41820024\n.long 0x812B0000\n.long 0x809F0004\n.long 0xA8690050\n.long 0x80090054\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x48000008\n.long 0x38600000\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
