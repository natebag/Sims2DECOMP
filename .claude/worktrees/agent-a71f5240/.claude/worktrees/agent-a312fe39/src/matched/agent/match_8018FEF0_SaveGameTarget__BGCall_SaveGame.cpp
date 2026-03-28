// 0x8018FEF0 (76 bytes)
// SaveGameTarget::BGCall_SaveGame(void)

class SaveGameTarget { public: void BGCall_SaveGame(void); };

__attribute__((naked))
void SaveGameTarget::BGCall_SaveGame(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x816DA71C\n.long 0x7C651B78\n.long 0x3C808019\n.long 0x38000000\n.long 0x812B0000\n.long 0x3884FF3C\n.long 0xA8690048\n.long 0x8129004C\n.long 0x7C6B1A14\n.long 0x900DAC18\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
