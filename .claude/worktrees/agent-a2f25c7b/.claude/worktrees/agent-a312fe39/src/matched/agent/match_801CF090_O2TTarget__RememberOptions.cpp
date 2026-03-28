// 0x801CF090 (92 bytes)
// O2TTarget::RememberOptions(void)

class O2TTarget { public: void RememberOptions(void); };

__attribute__((naked))
void O2TTarget::RememberOptions(void) {
    asm volatile(".long 0x3D608047\n.long 0x812B5F14\n.long 0x88090029\n.long 0x980D8BD6\n.long 0x89690028\n.long 0x996D8BD7\n.long 0x8809001C\n.long 0x980D8BD4\n.long 0x8969001D\n.long 0x996D8BD5\n.long 0x8809001F\n.long 0x980D8BD8\n.long 0x89690020\n.long 0x996D8BD9\n.long 0x81090024\n.long 0x80090004\n.long 0x81690000\n.long 0x81490018\n.long 0x900D8BDC\n.long 0x916D8BE8\n.long 0x914D8BE4\n.long 0x910D8BE0\n.long 0x4E800020");
}
