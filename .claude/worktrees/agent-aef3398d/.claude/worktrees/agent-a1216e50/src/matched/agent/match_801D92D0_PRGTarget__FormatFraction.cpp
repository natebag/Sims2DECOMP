// 0x801D92D0 (96 bytes)
// PRGTarget::FormatFraction(unsigned wchar_t *, int, int)

class PRGTarget { public: void FormatFraction(unsigned wchar_t *, int, int); };

__attribute__((naked))
void PRGTarget::FormatFraction(unsigned wchar_t *, int, int) {
    asm volatile(".long 0x9421FFE0\n.long 0x7C0802A6\n.long 0x93E1001C\n.long 0x90010024\n.long 0x7C9F2378\n.long 0x7C053000\n.long 0x40810008\n.long 0x7CC53378\n.long 0x3C80803F\n.long 0x38610008\n.long 0x38844BC8\n.long 0x4CC63182\n.long 0x48105589\n.long 0x38610008\n.long 0x4806A65D\n.long 0x38830001\n.long 0x7FE5FB78\n.long 0x38610008\n.long 0x4BE31A89\n.long 0x80010024\n.long 0x7C0803A6\n.long 0x83E1001C\n.long 0x38210020\n.long 0x4E800020");
}
