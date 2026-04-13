// 0x8007562C SimsMemCardWrap::IsFreeplayUnlocked (16b)

extern char gSimsMemCardWrap[4];

int SimsMemCardWrap_IsFreeplayUnlocked() {
    return ((int*)gSimsMemCardWrap)[3];  // offset 0x0C / 4
}
