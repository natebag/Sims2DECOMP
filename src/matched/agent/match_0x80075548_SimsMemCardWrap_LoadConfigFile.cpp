// FLAGS: -fno-elide-constructors
// 0x80075548 SimsMemCardWrap::LoadConfigFile (72b)

extern char gSimsMemCardWrapBase[];
extern int sub_80058D2C(int, int);
extern int sub_80058EE8(int);

int SimsMemCardWrap_LoadConfigFile(int param) {
    char* base = gSimsMemCardWrapBase;
    int v1 = sub_80058D2C(*(int*)(base + 0x148), param);
    sub_80058EE8(*(int*)(base + 0x148));
    return v1;
}
