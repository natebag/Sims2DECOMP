// FLAGS: -fno-elide-constructors
// 0x80094024 MUStatesSaveExistingGame::MUStatesSaveExistingGame (56b)

extern int _vt_MUStatesSaveExistingGame[];

struct MUStatesSaveExistingGame {
    int f0;
    int f4;
    int f8;
    int f12;
    int f16;
    int f20;
    int* f24;
    MUStatesSaveExistingGame(int p2);
};

MUStatesSaveExistingGame::MUStatesSaveExistingGame(int p2) {
    f0 = p2;
    f4 = -1;
    f8 = 0;
    f12 = -1;
    f16 = 0;
    f20 = 1;
    f24 = _vt_MUStatesSaveExistingGame;
}
