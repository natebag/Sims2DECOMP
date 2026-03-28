// 0x80197DF0 (112 bytes)
// CASGeneticsTarget::SetGrandparentIndex(unsigned int, int)

class CASGeneticsTarget { public: void SetGrandparentIndex(unsigned int, int); };

__attribute__((naked))
void CASGeneticsTarget::SetGrandparentIndex(unsigned int, int) {
    asm volatile(".long 0x81230094\n.long 0x2C090000\n.long 0x4082000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x80030300\n.long 0x7D2B4B78\n.long 0x7C002430\n.long 0x70090001\n.long 0x40820008\n.long 0x396B0010\n.long 0x812B0000\n.long 0x800B0004\n.long 0x7C090050\n.long 0x7C091671\n.long 0x4182FFD0\n.long 0x2C050000\n.long 0x4080000C\n.long 0x38A9FFFF\n.long 0x48000010\n.long 0x7C054840\n.long 0x41800008\n.long 0x38A00000\n.long 0x3923009C\n.long 0x5480103A\n.long 0x7CA9012E\n.long 0x38600001\n.long 0x4E800020");
}
