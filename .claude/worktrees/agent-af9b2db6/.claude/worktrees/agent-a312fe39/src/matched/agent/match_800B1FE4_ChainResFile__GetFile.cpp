// 0x800B1FE4 (96 bytes)
// ChainResFile::GetFile(short)

class ChainResFile { public: void GetFile(short); };

__attribute__((naked))
void ChainResFile::GetFile(short) {
    asm volatile(".long 0x7C681B78\n.long 0x39400000\n.long 0x80080010\n.long 0x39600000\n.long 0x38600000\n.long 0x2C000000\n.long 0x4D820020\n.long 0x7C032000\n.long 0x4082000C\n.long 0x7C030378\n.long 0x4E800020\n.long 0x396B0001\n.long 0x394A0001\n.long 0x2C0B0007\n.long 0x4D810020\n.long 0x1C0B0018\n.long 0x39280010\n.long 0x7C09002E\n.long 0x2C000000\n.long 0x4D820020\n.long 0x7C0A2000\n.long 0x4082FFD8\n.long 0x7C030378\n.long 0x4E800020");
}
