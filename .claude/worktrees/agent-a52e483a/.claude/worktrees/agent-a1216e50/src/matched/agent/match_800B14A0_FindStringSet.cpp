// 0x800B14A0 (96 bytes)
// FindStringSet(VECTOR<WStringSet> &, short, int)

__attribute__((naked))
void FindStringSet(VECTOR<WStringSet> &, short, int) {
    asm volatile(".long 0x80630000\n.long 0x39600000\n.long 0x2C030000\n.long 0x41820008\n.long 0x8163FFFC\n.long 0x39400000\n.long 0x2C0B0000\n.long 0x40820008\n.long 0x38600000\n.long 0x39200000\n.long 0x4800000C\n.long 0x39290001\n.long 0x3863000C\n.long 0x7C095800\n.long 0x40800020\n.long 0x80030004\n.long 0x7C002800\n.long 0x4082FFE8\n.long 0xA8030008\n.long 0x7C002000\n.long 0x4082FFDC\n.long 0x7C6A1B78\n.long 0x7D435378\n.long 0x4E800020");
}
