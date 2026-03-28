// 0x8014ABE4 (80 bytes)
// WantFear::Bookmark::ResetCountdown(void)

class WantFear { public: void Bookmark::ResetCountdown(void); };

__attribute__((naked))
void WantFear::Bookmark::ResetCountdown(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x807F0004\n.long 0x4BFFFF05\n.long 0x8803000B\n.long 0x2C000002\n.long 0x40820010\n.long 0x813F0004\n.long 0xA0090008\n.long 0x48000008\n.long 0x38000000\n.long 0xB01F0008\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
