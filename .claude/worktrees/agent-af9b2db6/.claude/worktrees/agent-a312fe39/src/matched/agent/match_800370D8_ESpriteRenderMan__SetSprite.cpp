// 0x800370D8 (88 bytes)
// ESpriteRenderMan::SetSprite(SpriteSlot *)

class ESpriteRenderMan { public: void SetSprite(SpriteSlot *); };

__attribute__((naked))
void ESpriteRenderMan::SetSprite(SpriteSlot *) {
    asm volatile(".long 0x80630000\n.long 0x2C030000\n.long 0x4D820020\n.long 0x81630000\n.long 0x80040064\n.long 0x812B0008\n.long 0x7C0A0378\n.long 0x7C090000\n.long 0x40820010\n.long 0x38000001\n.long 0x900B0004\n.long 0x4E800020\n.long 0x80630008\n.long 0x2C030000\n.long 0x4D820020\n.long 0x81230000\n.long 0x80090008\n.long 0x7C005000\n.long 0x4082FFE8\n.long 0x38000001\n.long 0x90090004\n.long 0x4E800020");
}
