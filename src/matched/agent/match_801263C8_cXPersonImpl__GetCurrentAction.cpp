// 0x801263C8 (68 bytes)
// cXPersonImpl::GetCurrentAction(void)

class cXPersonImpl { public: void GetCurrentAction(void); };

__attribute__((naked))
void cXPersonImpl::GetCurrentAction(void) {
    asm volatile(".long 0x80030534\n.long 0x2C000000\n.long 0x41820030\n.long 0x39230130\n.long 0x3C00CCCC\n.long 0x816902A8\n.long 0x6000CCCD\n.long 0x7C0B0016\n.long 0x5400E8FE\n.long 0x1C00000A\n.long 0x7D605850\n.long 0x1D6B0044\n.long 0x7C695A14\n.long 0x4E800020\n.long 0x3D208048\n.long 0x386967E4\n.long 0x4E800020");
}
