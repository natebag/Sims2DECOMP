// 0x8014ADA0 (104 bytes)
// WantFear::Bookmark::GetType(void) const

class WantFear { public: void Bookmark::GetType(void) const; };

__attribute__((naked))
void WantFear::Bookmark::GetType(void) const {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x807F0004\n.long 0x4BFFFD49\n.long 0x88030002\n.long 0x2C000080\n.long 0x4182002C\n.long 0x2C000001\n.long 0x38600001\n.long 0x41820024\n.long 0x7FE3FB78\n.long 0x48000031\n.long 0x2C030000\n.long 0x38600004\n.long 0x40820010\n.long 0x38600000\n.long 0x48000008\n.long 0x38600080\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
