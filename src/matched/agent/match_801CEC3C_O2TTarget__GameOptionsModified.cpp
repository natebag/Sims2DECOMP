// 0x801CEC3C (84 bytes)
// O2TTarget::GameOptionsModified(void)

class O2TTarget { public: void GameOptionsModified(void); };

__attribute__((naked))
void O2TTarget::GameOptionsModified(void) {
    asm volatile(".long 0x3D208047\n.long 0x816D8BDC\n.long 0x81495F14\n.long 0x800A0004\n.long 0x7C005800\n.long 0x40820038\n.long 0x812A0018\n.long 0x800D8BE4\n.long 0x7C090000\n.long 0x40820028\n.long 0x812A0024\n.long 0x800D8BE0\n.long 0x7C090000\n.long 0x40820018\n.long 0x812A0000\n.long 0x38600000\n.long 0x800D8BE8\n.long 0x7C090000\n.long 0x4D820020\n.long 0x38600001\n.long 0x4E800020");
}
