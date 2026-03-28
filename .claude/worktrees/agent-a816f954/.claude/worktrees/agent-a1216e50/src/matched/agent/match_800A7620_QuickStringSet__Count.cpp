// 0x800A7620 (84 bytes)
// QuickStringSet::Count(char)

class QuickStringSet { public: void Count(char); };

__attribute__((naked))
void QuickStringSet::Count(char) {
    asm volatile(".long 0x81230008\n.long 0x2C090000\n.long 0x4182001C\n.long 0x81290000\n.long 0x38600000\n.long 0x2C090000\n.long 0x4D820020\n.long 0x8069FFFC\n.long 0x4E800020\n.long 0x80630004\n.long 0x2C030000\n.long 0x41820020\n.long 0x80630000\n.long 0x38000000\n.long 0x2C030000\n.long 0x41820008\n.long 0x8003FFFC\n.long 0x7C030378\n.long 0x4E800020\n.long 0x38600000\n.long 0x4E800020");
}
