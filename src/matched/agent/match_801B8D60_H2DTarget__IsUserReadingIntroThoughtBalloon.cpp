// 0x801B8D60 (80 bytes)
// H2DTarget::IsUserReadingIntroThoughtBalloon(void)

class H2DTarget { public: void IsUserReadingIntroThoughtBalloon(void); };

__attribute__((naked))
void H2DTarget::IsUserReadingIntroThoughtBalloon(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x806300C4\n.long 0x3BE00000\n.long 0x2C030000\n.long 0x4182001C\n.long 0x48004CD1\n.long 0x3D20803F\n.long 0xC0091424\n.long 0xFC010000\n.long 0x40810008\n.long 0x3BE00001\n.long 0x7FE3FB78\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
