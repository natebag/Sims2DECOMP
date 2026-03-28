// 0x800A76AC (80 bytes)
// QuickStringSet::GetString(int, char)

class QuickStringSet { public: void GetString(int, char); };

__attribute__((naked))
void QuickStringSet::GetString(int, char) {
    asm volatile(".long 0x81230008\n.long 0x2C090000\n.long 0x41820040\n.long 0x2C040000\n.long 0x40810020\n.long 0x81690000\n.long 0x38000000\n.long 0x2C0B0000\n.long 0x41820008\n.long 0x800BFFFC\n.long 0x7C040000\n.long 0x4081000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x3924FFFF\n.long 0x5529103A\n.long 0x7C6B482E\n.long 0x4E800020\n.long 0x38600000\n.long 0x4E800020");
}
