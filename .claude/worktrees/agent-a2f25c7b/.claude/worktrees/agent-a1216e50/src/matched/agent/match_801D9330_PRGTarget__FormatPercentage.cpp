// 0x801D9330 (104 bytes)
// PRGTarget::FormatPercentage(unsigned wchar_t *, int, int)

class PRGTarget { public: void FormatPercentage(unsigned wchar_t *, int, int); };

__attribute__((naked))
void PRGTarget::FormatPercentage(unsigned wchar_t *, int, int) {
    asm volatile(".long 0x9421FFE0\n.long 0x7C0802A6\n.long 0x93E1001C\n.long 0x90010024\n.long 0x7C9F2378\n.long 0x7C053000\n.long 0x40810008\n.long 0x7CC53378\n.long 0x1CA50064\n.long 0x3C80803F\n.long 0x38844BD0\n.long 0x38610008\n.long 0x7CA533D6\n.long 0x4CC63182\n.long 0x48105521\n.long 0x38610008\n.long 0x4806A5F5\n.long 0x38830001\n.long 0x7FE5FB78\n.long 0x38610008\n.long 0x4BE31A21\n.long 0x80010024\n.long 0x7C0803A6\n.long 0x83E1001C\n.long 0x38210020\n.long 0x4E800020");
}
