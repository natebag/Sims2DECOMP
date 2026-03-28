// 0x8016222C (64 bytes)
// CasMediator::DrawSim(ERC *)

class CasMediator { public: void DrawSim(ERC *); };

__attribute__((naked))
void CasMediator::DrawSim(ERC *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81630014\n.long 0x2C0B0000\n.long 0x4182001C\n.long 0x812B0004\n.long 0xA8690060\n.long 0x80090064\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
