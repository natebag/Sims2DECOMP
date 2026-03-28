// 0x800A7F00 (92 bytes)
// wcsncpy

__attribute__((naked))
void wcsncpy() {
    asm volatile(".long 0xA0040000\n.long 0x7C691B78\n.long 0x2C000000\n.long 0x4182002C\n.long 0x2C050000\n.long 0x41820040\n.long 0xB0030000\n.long 0x38A5FFFF\n.long 0xA4040002\n.long 0x38630002\n.long 0x2C000000\n.long 0x4182000C\n.long 0x2C050000\n.long 0x4082FFE4\n.long 0x2C050000\n.long 0x41820018\n.long 0x38000000\n.long 0xB0030000\n.long 0x34A5FFFF\n.long 0x38630002\n.long 0x4082FFF4\n.long 0x7D234B78\n.long 0x4E800020");
}
