// FLAGS: -fno-elide-constructors
// 0x800911EC LoadingScreenUpdateState::LoadingScreenUpdateState (56b)

extern int _vt_LoadingScreenUpdateState[];

struct LoadingScreenUpdateState {
    int f0;
    int f4;
    int f8;
    int f12;
    int f16;
    int f20;
    int* f24;
    LoadingScreenUpdateState(int p2);
};

LoadingScreenUpdateState::LoadingScreenUpdateState(int p2) {
    f0 = p2;
    f4 = -1;
    f8 = 0;
    f12 = -1;
    f16 = 0;
    f20 = 1;
    f24 = _vt_LoadingScreenUpdateState;
}
