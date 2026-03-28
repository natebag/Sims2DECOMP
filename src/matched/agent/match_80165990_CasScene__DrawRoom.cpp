// 0x80165990 (68 bytes)
// CasScene::DrawRoom(ERC *, CasScene::RoomId, EMat4 &)

class CasScene { public: void DrawRoom(ERC *, CasScene::RoomId, EMat4 &); };

__attribute__((naked))
void CasScene::DrawRoom(ERC *, CasScene::RoomId, EMat4 &) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C6B1B78\n.long 0x2C050000\n.long 0x40820020\n.long 0x812B0004\n.long 0x7CC53378\n.long 0xA8690078\n.long 0x8009007C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
