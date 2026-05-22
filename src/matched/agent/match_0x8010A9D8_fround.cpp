// 0x8010A9D8 fround(float) (76B)
// Round float to nearest int, half away from zero.

extern float lbl_803DC220[];
extern double lbl_803DC228[];

int fround(float x) {
    if (x < lbl_803DC220[0]) {
        return (int)((double)x - lbl_803DC228[0]);
    }
    return (int)((double)x + lbl_803DC228[0]);
}
