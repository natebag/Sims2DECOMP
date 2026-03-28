// 0x8007AD28 (80 bytes)
// CopyCharStrToWString(char *, unsigned wchar_t *, unsigned int)

__attribute__((naked))
void CopyCharStrToWString(char *, unsigned wchar_t *, unsigned int) {
    asm volatile(".long 0x7C691B78\n.long 0x88090000\n.long 0x38600000\n.long 0x2C000000\n.long 0x41820034\n.long 0x38A5FFFF\n.long 0x7C032840\n.long 0x40800028\n.long 0x7C000774\n.long 0x38630001\n.long 0xB0040000\n.long 0x38840002\n.long 0x8C090001\n.long 0x2C000000\n.long 0x4182000C\n.long 0x7C032840\n.long 0x4180FFE0\n.long 0x38000000\n.long 0xB0040000\n.long 0x4E800020");
}
