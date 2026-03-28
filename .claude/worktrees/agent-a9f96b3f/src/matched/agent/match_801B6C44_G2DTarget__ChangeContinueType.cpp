// 0x801B6C44 (124 bytes)
// G2DTarget::ChangeContinueType(int)

class G2DTarget { public: void ChangeContinueType(int); };

__attribute__((naked))
void G2DTarget::ChangeContinueType(int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C9F2378\n.long 0x7C7E1B78\n.long 0x281F0003\n.long 0x40810014\n.long 0x3C60803F\n.long 0x38630F78\n.long 0x4CC63182\n.long 0x48200731\n.long 0x801E00A4\n.long 0x2C000000\n.long 0x40820014\n.long 0x2C1F0000\n.long 0x4082000C\n.long 0x7FC3F378\n.long 0x4BFFED35\n.long 0x3C60803F\n.long 0x809E00A4\n.long 0x93FE00AC\n.long 0x38630FB4\n.long 0x7FE5FB78\n.long 0x4CC63182\n.long 0x482006F9\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
