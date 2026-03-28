// 0x80093250 (68 bytes)
// MUStatesDisplay::Draw(ERC *)

class MUStatesDisplay { public: void Draw(ERC *); };

__attribute__((naked))
void MUStatesDisplay::Draw(ERC *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81230008\n.long 0x81690098\n.long 0x2C0B0000\n.long 0x4182001C\n.long 0x812B0080\n.long 0xA8690030\n.long 0x80090034\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
