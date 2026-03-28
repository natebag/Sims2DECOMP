// 0x801617FC (68 bytes)
// CasGenetics::GetGrandparent(bool, unsigned int)

class CasGenetics { public: void GetGrandparent(bool, unsigned int); };

__attribute__((naked))
void CasGenetics::GetGrandparent(bool, unsigned int) {
    asm volatile(".long 0x2C040000\n.long 0x39200000\n.long 0x41820008\n.long 0x39200001\n.long 0x55292036\n.long 0x7D69182E\n.long 0x7D291A14\n.long 0x80090004\n.long 0x7C0B0050\n.long 0x7C001670\n.long 0x7C050040\n.long 0x4180000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x54A9103A\n.long 0x7C6B482E\n.long 0x4E800020");
}
