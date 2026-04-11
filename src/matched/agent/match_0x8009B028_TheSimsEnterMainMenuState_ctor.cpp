// FLAGS: -fno-elide-constructors
// 0x8009B028 TheSimsEnterMainMenuState::TheSimsEnterMainMenuState (60b)

extern int _vt_TheSimsEnterMainMenuState[];

struct TheSimsEnterMainMenuState {
    int f0;
    int f4;
    int f8;
    int f12;
    int f16;
    int f20;
    int* f24;
    int f28;
    TheSimsEnterMainMenuState(int p2);
};

TheSimsEnterMainMenuState::TheSimsEnterMainMenuState(int p2) {
    f0 = p2;
    f4 = -1;
    f8 = 0;
    f12 = -1;
    f16 = 0;
    f20 = 1;
    f24 = _vt_TheSimsEnterMainMenuState;
    f28 = 0;
}
