// 0x800C182C (112 bytes)
// Interaction::GetEntry(void) const

class Interaction { public: void GetEntry(void) const; };

__attribute__((naked))
void Interaction::GetEntry(void) const {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x817F000C\n.long 0x2C0B0000\n.long 0x4182003C\n.long 0x812B0004\n.long 0x80090364\n.long 0xA8690360\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x81230000\n.long 0x809F0014\n.long 0xA8090088\n.long 0x8129008C\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x48000008\n.long 0x38600000\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
