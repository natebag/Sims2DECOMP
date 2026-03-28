// 0x8007AD78 (80 bytes)
// CopyWStringToCharStr(unsigned wchar_t *, char *, unsigned int)

__attribute__((naked))
void CopyWStringToCharStr(unsigned wchar_t *, char *, unsigned int) {
    asm volatile(".long 0x7C691B78\n.long 0xA0090000\n.long 0x38600000\n.long 0x2C000000\n.long 0x41820034\n.long 0x38A5FFFF\n.long 0x7C032840\n.long 0x40800028\n.long 0x88090001\n.long 0x38630001\n.long 0x98040000\n.long 0x38840001\n.long 0xA4090002\n.long 0x2C000000\n.long 0x4182000C\n.long 0x7C032840\n.long 0x4180FFE0\n.long 0x38000000\n.long 0x98040000\n.long 0x4E800020");
}
