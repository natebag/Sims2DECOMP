// 0x801192E8 (88 bytes)
// cSampleChannel::NoteOff(void)

class cSampleChannel { public: void NoteOff(void); };

__attribute__((naked))
void cSampleChannel::NoteOff(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x817F0004\n.long 0x2C0B0000\n.long 0x41820024\n.long 0x812B0000\n.long 0x8009001C\n.long 0xA8690018\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x38000000\n.long 0x901F0004\n.long 0x38600001\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
