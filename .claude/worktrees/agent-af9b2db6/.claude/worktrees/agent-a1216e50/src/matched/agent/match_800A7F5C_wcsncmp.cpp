// 0x800A7F5C (64 bytes)
// wcsncmp

__attribute__((naked))
void wcsncmp() {
    asm volatile(".long 0x39600000\n.long 0xA0030000\n.long 0x396B0001\n.long 0xA1240000\n.long 0x7D490051\n.long 0x40820024\n.long 0x2C000000\n.long 0x38630002\n.long 0x41820018\n.long 0x2C090000\n.long 0x38840002\n.long 0x4182000C\n.long 0x7C0B2800\n.long 0x4180FFD0\n.long 0x7D435378\n.long 0x4E800020");
}
