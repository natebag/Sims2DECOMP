// 0x800B43EC (68 bytes)
// CTilePt::CTilePt(EVec3 &)

class CTilePt { public: void CTilePt(EVec3 &); };

__attribute__((naked))
void CTilePt::CTilePt(EVec3 &) {
    asm volatile(".long 0x9421FFF0\n.long 0xC0040000\n.long 0x7D2B4B78\n.long 0x7C6A1B78\n.long 0x38000001\n.long 0xFDA0001E\n.long 0xD9A10008\n.long 0x8121000C\n.long 0x992A0000\n.long 0xC0040004\n.long 0x980A0002\n.long 0xFD80001E\n.long 0xD9810008\n.long 0x8161000C\n.long 0x996A0001\n.long 0x38210010\n.long 0x4E800020");
}
