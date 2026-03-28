// 0x80104E58 (104 bytes)
// PresetHouseGameStatus(void)

__attribute__((naked))
void PresetHouseGameStatus(void) {
    asm volatile(".long 0x38000010\n.long 0x3D208048\n.long 0x7C0903A6\n.long 0x392964D0\n.long 0x39600000\n.long 0x38A00001\n.long 0x38C90004\n.long 0x38E90008\n.long 0x39400000\n.long 0x3900000F\n.long 0x380BFFF3\n.long 0x2C0B0000\n.long 0x2B800003\n.long 0x1C0B000C\n.long 0x41820008\n.long 0x419D000C\n.long 0x90A90000\n.long 0x4800000C\n.long 0x1C0B000C\n.long 0x91490000\n.long 0x7D47012E\n.long 0x3929000C\n.long 0x7D06012E\n.long 0x396B0001\n.long 0x4200FFC8\n.long 0x4E800020");
}
