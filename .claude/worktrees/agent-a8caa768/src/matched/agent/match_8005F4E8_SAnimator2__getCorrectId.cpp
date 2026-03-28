// 0x8005F4E8 (96 bytes)
// SAnimator2::getCorrectId(PropRef *)

class SAnimator2 { public: void getCorrectId(PropRef *); };

__attribute__((naked))
void SAnimator2::getCorrectId(PropRef *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x80630004\n.long 0x7C9F2378\n.long 0x81230004\n.long 0xA8090210\n.long 0x81290214\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x2C030000\n.long 0x40820014\n.long 0x801F0004\n.long 0x7C030378\n.long 0x2C000000\n.long 0x40820008\n.long 0x807F0000\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
