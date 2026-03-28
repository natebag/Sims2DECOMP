// 0x800A76FC (92 bytes)
// QuickStringSet::GetLocString(int)

class QuickStringSet { public: void GetLocString(int); };

__attribute__((naked))
void QuickStringSet::GetLocString(int) {
    asm volatile(".long 0x81240004\n.long 0x2C090000\n.long 0x41820048\n.long 0x2C050000\n.long 0x40810020\n.long 0x81690000\n.long 0x38000000\n.long 0x2C0B0000\n.long 0x41820008\n.long 0x800BFFFC\n.long 0x7C050000\n.long 0x40810010\n.long 0x8004000C\n.long 0x90030000\n.long 0x4E800020\n.long 0x3925FFFF\n.long 0x5529103A\n.long 0x7C0B482E\n.long 0x90030000\n.long 0x4E800020\n.long 0x8004000C\n.long 0x90030000\n.long 0x4E800020");
}
