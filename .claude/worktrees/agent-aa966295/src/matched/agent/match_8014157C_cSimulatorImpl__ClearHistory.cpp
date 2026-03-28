// 0x8014157C (96 bytes)
// cSimulatorImpl::ClearHistory(void)

class cSimulatorImpl { public: void ClearHistory(void); };

__attribute__((naked))
void cSimulatorImpl::ClearHistory(void) {
    asm volatile(".long 0x39600008\n.long 0x38000000\n.long 0x7D6903A6\n.long 0x39230170\n.long 0x90090000\n.long 0x3929FFFC\n.long 0x4200FFF8\n.long 0x39600000\n.long 0x39400000\n.long 0x55692834\n.long 0x380B0001\n.long 0x39600008\n.long 0x7D291A14\n.long 0x7D6903A6\n.long 0x392900D0\n.long 0x91490000\n.long 0x3929FFFC\n.long 0x4200FFF8\n.long 0x7C0B0378\n.long 0x2C0B0004\n.long 0x4081FFD4\n.long 0x38000000\n.long 0xB003004C\n.long 0x4E800020");
}
