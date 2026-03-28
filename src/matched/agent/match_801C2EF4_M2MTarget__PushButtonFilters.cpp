// 0x801C2EF4 (120 bytes)
// M2MTarget::PushButtonFilters(void)

class M2MTarget { public: void PushButtonFilters(void); };

__attribute__((naked))
void M2MTarget::PushButtonFilters(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x3D208047\n.long 0x7C7F1B78\n.long 0x80095C70\n.long 0x2C000000\n.long 0x4182002C\n.long 0x801F0190\n.long 0x2C000001\n.long 0x40820020\n.long 0x38000000\n.long 0x809F007C\n.long 0x901F0170\n.long 0x38600001\n.long 0x4BFB4C11\n.long 0x907F0174\n.long 0x4800001C\n.long 0x809F007C\n.long 0x38600000\n.long 0x4BFB4BFD\n.long 0x38000000\n.long 0x907F0170\n.long 0x901F0174\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
