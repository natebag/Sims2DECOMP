// 0x8017A9AC (112 bytes)
// UIDrawTable::UnInstallAllName(char *)

class UIDrawTable { public: void UnInstallAllName(char *); };

__attribute__((naked))
void UIDrawTable::UnInstallAllName(char *) {
    asm volatile(".long 0x9421FFE0\n.long 0x7C0802A6\n.long 0xBF61000C\n.long 0x90010024\n.long 0x7C7D1B78\n.long 0x7C9B2378\n.long 0x83FD0000\n.long 0x3B800000\n.long 0x2C1F0000\n.long 0x41820034\n.long 0x807F0010\n.long 0x7F64DB78\n.long 0x83DF0004\n.long 0x480C8E59\n.long 0x2C030000\n.long 0x40820014\n.long 0x7FE4FB78\n.long 0x7FA3EB78\n.long 0x4BFFFE6D\n.long 0x3B800001\n.long 0x7FDFF379\n.long 0x4082FFD4\n.long 0x7F83E378\n.long 0x80010024\n.long 0x7C0803A6\n.long 0xBB61000C\n.long 0x38210020\n.long 0x4E800020");
}
