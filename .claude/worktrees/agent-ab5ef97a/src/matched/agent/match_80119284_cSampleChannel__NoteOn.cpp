// 0x80119284 (100 bytes)
// cSampleChannel::NoteOn(void)

class cSampleChannel { public: void NoteOn(void); };

__attribute__((naked))
void cSampleChannel::NoteOn(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x38800000\n.long 0x817E0004\n.long 0x812B0000\n.long 0x80090094\n.long 0xA8690090\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x817E0004\n.long 0x812B0000\n.long 0xA8690020\n.long 0x80090024\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
