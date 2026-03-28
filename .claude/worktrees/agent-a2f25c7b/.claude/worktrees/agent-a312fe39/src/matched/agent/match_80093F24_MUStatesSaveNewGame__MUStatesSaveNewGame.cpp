// 0x80093F24 (72 bytes)
// MUStatesSaveNewGame::MUStatesSaveNewGame(int)

class MUStatesSaveNewGame { public: void MUStatesSaveNewGame(int); };

__attribute__((naked))
void MUStatesSaveNewGame::MUStatesSaveNewGame(int) {
    asm volatile(".long 0x3D608046\n.long 0x7C691B78\n.long 0x3940FFFF\n.long 0x39000000\n.long 0x396BDC38\n.long 0x38000001\n.long 0x90890000\n.long 0x3CE0803E\n.long 0x9149000C\n.long 0x91090010\n.long 0x90090014\n.long 0x91690018\n.long 0x91490004\n.long 0x91090008\n.long 0xC00782F8\n.long 0xD0090034\n.long 0xD0090030\n.long 0x4E800020");
}
