// 0x800B4C60 (72 bytes)
// CTilePt::ToFTilePt(void) const

class CTilePt { public: void ToFTilePt(void) const; };

__attribute__((naked))
void CTilePt::ToFTilePt(void) const {
    asm volatile(".long 0x9421FFF0\n.long 0x89240001\n.long 0x7C6B1B78\n.long 0x88040000\n.long 0x7D290774\n.long 0x7C000774\n.long 0x55292036\n.long 0x54002036\n.long 0x61290008\n.long 0x60000008\n.long 0x91210008\n.long 0x9001000C\n.long 0x81210008\n.long 0x8141000C\n.long 0x912B0000\n.long 0x914B0004\n.long 0x38210010\n.long 0x4E800020");
}
