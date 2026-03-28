// 0x800677B0 (108 bytes)
// SAnimator2::PropsHaveAlpha(void)

class SAnimator2 { public: void PropsHaveAlpha(void); };

__attribute__((naked))
void SAnimator2::PropsHaveAlpha(void) {
    asm volatile(".long 0x81230168\n.long 0x39400000\n.long 0x8003016C\n.long 0x7C090050\n.long 0x7C001670\n.long 0x7C0A0000\n.long 0x4080004C\n.long 0x7C0903A6\n.long 0x7D2B4B78\n.long 0x812B0000\n.long 0x396B0004\n.long 0x81290008\n.long 0x2C090000\n.long 0x4182002C\n.long 0x2C0A0000\n.long 0x39400001\n.long 0x40820008\n.long 0x39400000\n.long 0x80090100\n.long 0x38600001\n.long 0x2C000000\n.long 0x40820008\n.long 0x38600000\n.long 0x7D4A1B78\n.long 0x4200FFC4\n.long 0x7D435378\n.long 0x4E800020");
}
