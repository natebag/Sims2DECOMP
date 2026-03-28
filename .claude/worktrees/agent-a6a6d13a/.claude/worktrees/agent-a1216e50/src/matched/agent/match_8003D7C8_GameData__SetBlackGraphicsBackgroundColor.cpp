// 0x8003D7C8 (92 bytes)
// GameData::SetBlackGraphicsBackgroundColor(void)

class GameData { public: void SetBlackGraphicsBackgroundColor(void); };

__attribute__((naked))
void GameData::SetBlackGraphicsBackgroundColor(void) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0x9001001C\n.long 0x814D98E8\n.long 0x3D20803D\n.long 0xC0091E9C\n.long 0x39610008\n.long 0x812A0000\n.long 0x7D645B78\n.long 0x38A000FF\n.long 0x38C00001\n.long 0xA8690048\n.long 0xD00B0008\n.long 0xD00B0004\n.long 0x7C6A1A14\n.long 0xD0010008\n.long 0x8009004C\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0x38210018\n.long 0x4E800020");
}
