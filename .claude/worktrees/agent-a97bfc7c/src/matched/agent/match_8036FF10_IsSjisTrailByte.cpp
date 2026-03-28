// 0x8036FF10 (64 bytes)
// IsSjisTrailByte

__attribute__((naked))
void IsSjisTrailByte() {
    asm volatile(".long 0x5460063E\n.long 0x28000040\n.long 0x38800000\n.long 0x38A40000\n.long 0x41800010\n.long 0x280000FC\n.long 0x41810008\n.long 0x38A00001\n.long 0x2C050000\n.long 0x41820014\n.long 0x5460063E\n.long 0x2800007F\n.long 0x41820008\n.long 0x38800001\n.long 0x7C832378\n.long 0x4E800020");
}
