// FLAGS: -fno-elide-constructors
// 0x8007562C SimsMemCardWrap::IsFreeplayUnlocked (16b)

extern char gSimsMemCardWrap[];

int SimsMemCardWrap_IsFreeplayUnlocked() {
    int** ptr = (int**)gSimsMemCardWrap;
    return (*ptr)[3];
}
