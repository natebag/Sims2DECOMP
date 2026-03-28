// 0x801B8D0C (84 bytes)
// H2DTarget::SpawnIntroThoughtBalloon(UIDialog *)

class H2DTarget { public: void SpawnIntroThoughtBalloon(UIDialog *); };

__attribute__((naked))
void H2DTarget::SpawnIntroThoughtBalloon(UIDialog *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x7C9E2378\n.long 0x801F00C4\n.long 0x2C000000\n.long 0x40820014\n.long 0x386000A0\n.long 0x4811847D\n.long 0x48003D05\n.long 0x907F00C4\n.long 0x807F00C4\n.long 0x7FC4F378\n.long 0x48004BB5\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
