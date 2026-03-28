// 0x8006C040 (84 bytes)
// SAnimator2::skillIsIdle(void)

class SAnimator2 { public: void skillIsIdle(void); };

__attribute__((naked))
void SAnimator2::skillIsIdle(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x80630004\n.long 0x3BE00000\n.long 0x81230004\n.long 0xA80900A8\n.long 0x812900AC\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x2C030000\n.long 0x41820008\n.long 0x3BE00001\n.long 0x7FE3FB78\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
