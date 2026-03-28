// 0x8003DA5C (68 bytes)
// GameData::StageStartFrame(void)

class GameData { public: void StageStartFrame(void); };

__attribute__((naked))
void GameData::StageStartFrame(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x816D985C\n.long 0x3C80804B\n.long 0x3884D210\n.long 0x812B0000\n.long 0xA8690028\n.long 0x8009002C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0xD02D9E50\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
