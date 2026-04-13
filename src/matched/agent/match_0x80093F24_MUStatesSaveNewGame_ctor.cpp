// FLAGS: -fno-elide-constructors
// 0x80093F24 MUStatesSaveNewGame::MUStatesSaveNewGame (72b)

extern int _vt_MUStatesSaveNewGame[];
extern float gFloatValue[];

struct MUStatesSaveNewGame {
    int f0;
    int f4;
    int f8;
    int f12;
    int f16;
    int f20;
    int* f24;
    char pad[20];
    float f48;
    float f52;
    MUStatesSaveNewGame(int p2);
};

MUStatesSaveNewGame::MUStatesSaveNewGame(int p2) {
    f0 = p2;
    f4 = -1;
    f8 = 0;
    f12 = -1;
    f16 = 0;
    f20 = 1;
    f24 = _vt_MUStatesSaveNewGame;
    float val = gFloatValue[0];
    struct FloatPair { float f52; float f48; };
    FloatPair* fp = (FloatPair*)((char*)this + 48);
    fp->f52 = val;
    fp->f48 = val;
}
