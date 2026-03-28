// 0x80119110 (72 bytes)
// cSampleChannel::SetVolume(int)

class cSampleChannel { public: void SetVolume(int); };

__attribute__((naked))
void cSampleChannel::SetVolume(int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81630004\n.long 0x2C0B0000\n.long 0x4082000C\n.long 0x38600000\n.long 0x4800001C\n.long 0x812B0000\n.long 0xA8690060\n.long 0x80090064\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
