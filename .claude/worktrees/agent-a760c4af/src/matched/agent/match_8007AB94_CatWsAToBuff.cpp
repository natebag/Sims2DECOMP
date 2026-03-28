// 0x8007AB94 (128 bytes)
// CatWsAToBuff(unsigned wchar_t *, unsigned wchar_t *, unsigned int)

__attribute__((naked))
void CatWsAToBuff(unsigned wchar_t *, unsigned wchar_t *, unsigned int) {
    asm volatile(".long 0x7C892378\n.long 0x7C681B78\n.long 0xA0090000\n.long 0x39600000\n.long 0x2C000000\n.long 0x41820014\n.long 0xA4090002\n.long 0x396B0001\n.long 0x2C000000\n.long 0x4082FFF4\n.long 0xA0630000\n.long 0x7C0B5A14\n.long 0x7D240214\n.long 0x39400000\n.long 0x2C030000\n.long 0x41820034\n.long 0x38A5FFFF\n.long 0x7C0B2840\n.long 0x40800028\n.long 0xB0690000\n.long 0x396B0001\n.long 0xA4680002\n.long 0x39290002\n.long 0x394A0001\n.long 0x2C030000\n.long 0x4182000C\n.long 0x7C0B2840\n.long 0x4180FFE0\n.long 0x38000000\n.long 0x7D435378\n.long 0xB0090000\n.long 0x4E800020");
}
