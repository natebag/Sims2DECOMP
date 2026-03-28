// 0x800922F4 (76 bytes)
// MUStatesSaveNewGame::Draw(ERC *)

class MUStatesSaveNewGame { public: void Draw(ERC *); };

__attribute__((naked))
void MUStatesSaveNewGame::Draw(ERC *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x8123001C\n.long 0x3929FFF7\n.long 0x28090002\n.long 0x41810024\n.long 0x81630008\n.long 0x814B0098\n.long 0x812A0080\n.long 0xA8690030\n.long 0x80090034\n.long 0x7C6A1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
