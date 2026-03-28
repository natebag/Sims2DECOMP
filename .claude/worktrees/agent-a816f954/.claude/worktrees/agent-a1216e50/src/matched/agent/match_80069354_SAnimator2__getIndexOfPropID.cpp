// 0x80069354 (100 bytes)
// SAnimator2::getIndexOfPropID(unsigned int)

class SAnimator2 { public: void getIndexOfPropID(unsigned int); };

__attribute__((naked))
void SAnimator2::getIndexOfPropID(unsigned int) {
    asm volatile(".long 0x81230168\n.long 0x39400000\n.long 0x8003016C\n.long 0x3860FFFF\n.long 0x7D2B4B78\n.long 0x7C090050\n.long 0x7C081670\n.long 0x7C0A4000\n.long 0x4C800020\n.long 0x812B0000\n.long 0x80090000\n.long 0x7C002000\n.long 0x4082000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x394A0001\n.long 0x396B0004\n.long 0x7C0A4000\n.long 0x4C800020\n.long 0x812B0000\n.long 0x80090000\n.long 0x7C002000\n.long 0x4082FFE4\n.long 0x7D435378\n.long 0x4E800020");
}
