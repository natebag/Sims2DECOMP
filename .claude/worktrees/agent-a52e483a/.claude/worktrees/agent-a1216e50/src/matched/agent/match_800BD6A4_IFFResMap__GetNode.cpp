// 0x800BD6A4 (120 bytes)
// IFFResMap::GetNode(Memory::HandleNode *, unsigned int *, void (*)(void *, int))

class IFFResMap { public: void GetNode(Memory::HandleNode *, unsigned int *, void (*)(void *, int)); };

__attribute__((naked))
void IFFResMap::GetNode(Memory::HandleNode *, unsigned int *, void (*)(void *, int)) {
    asm volatile(".long 0x7C6A1B78\n.long 0x812A0000\n.long 0x800A0004\n.long 0x7C090000\n.long 0x41820058\n.long 0x80690000\n.long 0x80090004\n.long 0x7C030000\n.long 0x41820038\n.long 0x7C0B0378\n.long 0x2F860000\n.long 0x8003000C\n.long 0x7C002000\n.long 0x40820018\n.long 0x419E0008\n.long 0x90C90014\n.long 0x80090010\n.long 0x90050000\n.long 0x4E800020\n.long 0x38630058\n.long 0x7C035800\n.long 0x4082FFD8\n.long 0x800A0004\n.long 0x39290018\n.long 0x7C090000\n.long 0x4082FFB0\n.long 0x38000000\n.long 0x38600000\n.long 0x90050000\n.long 0x4E800020");
}
