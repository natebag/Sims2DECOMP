// 0x8036FEB8 (88 bytes)
// IsSjisLeadByte

__attribute__((naked))
void IsSjisLeadByte() {
    asm volatile(".long 0x5460063E\n.long 0x28000081\n.long 0x38800001\n.long 0x38A00000\n.long 0x41800010\n.long 0x2800009F\n.long 0x41810008\n.long 0x7C852378\n.long 0x2C050000\n.long 0x4082002C\n.long 0x5460063E\n.long 0x280000E0\n.long 0x38600000\n.long 0x41800010\n.long 0x280000FC\n.long 0x41810008\n.long 0x38600001\n.long 0x2C030000\n.long 0x40820008\n.long 0x38800000\n.long 0x7C832378\n.long 0x4E800020");
}
