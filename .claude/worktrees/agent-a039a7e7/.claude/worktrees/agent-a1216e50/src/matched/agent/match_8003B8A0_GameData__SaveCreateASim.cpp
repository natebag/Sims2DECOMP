// 0x8003B8A0 (88 bytes)
// GameData::SaveCreateASim(void)

class GameData { public: void SaveCreateASim(void); };

__attribute__((naked))
void GameData::SaveCreateASim(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x816DAC1C\n.long 0x812B0000\n.long 0x80090194\n.long 0xA8690190\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x81230000\n.long 0x808D82C8\n.long 0xA8090068\n.long 0x8129006C\n.long 0x80AD82D8\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
