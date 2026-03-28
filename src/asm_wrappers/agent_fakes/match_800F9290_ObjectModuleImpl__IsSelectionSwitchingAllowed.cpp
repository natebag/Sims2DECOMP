// 0x800F9290 (128 bytes)
// ObjectModuleImpl::IsSelectionSwitchingAllowed(void)

class ObjectModuleImpl { public: void IsSelectionSwitchingAllowed(void); };

__attribute__((naked))
void ObjectModuleImpl::IsSelectionSwitchingAllowed(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x800DAC1C\n.long 0x2C000000\n.long 0x41820050\n.long 0x3D208047\n.long 0x39295B84\n.long 0x800900E8\n.long 0x2C000000\n.long 0x40820044\n.long 0x800900F0\n.long 0x2C000000\n.long 0x40820038\n.long 0x816DAC08\n.long 0x2C0B0000\n.long 0x41820024\n.long 0x812B0000\n.long 0xA86900E8\n.long 0x800900EC\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x2C03005B\n.long 0x4181000C\n.long 0x38600000\n.long 0x48000008\n.long 0x38600001\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
