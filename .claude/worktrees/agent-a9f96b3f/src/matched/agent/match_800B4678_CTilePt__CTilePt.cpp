// 0x800B4678 (96 bytes)
// CTilePt::CTilePt(float, float, int)

class CTilePt { public: void CTilePt(float, float, int); };

__attribute__((naked))
void CTilePt::CTilePt(float, float, int) {
    asm volatile(".long 0x9421FFF0\n.long 0xFC00081E\n.long 0x7D2B4B78\n.long 0xD8010008\n.long 0xFC00101E\n.long 0x8121000C\n.long 0xD8010008\n.long 0x7D200774\n.long 0x99230000\n.long 0x8161000C\n.long 0x7C004800\n.long 0x99630001\n.long 0x4182000C\n.long 0x38000000\n.long 0x98030000\n.long 0x88030001\n.long 0x7C000774\n.long 0x7C005800\n.long 0x4182000C\n.long 0x38000000\n.long 0x98030001\n.long 0x98830002\n.long 0x38210010\n.long 0x4E800020");
}
