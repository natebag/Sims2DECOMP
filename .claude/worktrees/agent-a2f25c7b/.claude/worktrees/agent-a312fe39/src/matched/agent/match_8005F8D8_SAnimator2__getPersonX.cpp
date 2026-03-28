// 0x8005F8D8 (64 bytes)
// SAnimator2::getPersonX(void)

class SAnimator2 { public: void getPersonX(void); };

__attribute__((naked))
void SAnimator2::getPersonX(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81230004\n.long 0x81490000\n.long 0x816A0004\n.long 0xA86B0340\n.long 0x800B0344\n.long 0x7C6A1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x80630004\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
