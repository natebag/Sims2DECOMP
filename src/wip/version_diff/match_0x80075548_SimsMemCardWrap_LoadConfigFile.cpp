// SimsMemCardWrap::LoadConfigFile(int)
// 72 bytes, 2 bl calls, uses SDA global

// External functions
extern "C" int sub_80058D2C(int, int);
extern "C" int sub_80058EE8(int);

// Global at r30 offset - using SDA technique
extern char gSimsMemCardWrap[4];

class SimsMemCardWrap {
public:
    int LoadConfigFile(int param);
};

int SimsMemCardWrap::LoadConfigFile(int param) {
    int* global = (int*)(gSimsMemCardWrap + 0x5DCC + 0x148);
    int v1 = sub_80058D2C(*global, param);
    int v2 = sub_80058EE8(*global);
    return v1;
}
