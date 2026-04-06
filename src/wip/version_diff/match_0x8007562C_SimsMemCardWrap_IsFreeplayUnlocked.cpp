// MATCH: 0x8007562C SimsMemCardWrap::IsFreeplayUnlocked (16 bytes)
// Raw: 3D 20 80 47 81 69 5F 14 80 6B 00 0C 4E 80 00 20

struct SimsMemCardWrap {
    int flags;  // offset 0x0C
};

// SDA global - accessed via lis/lwz pattern
extern SimsMemCardWrap* gSimsMemCardWrap;

extern "C" int SimsMemCardWrap_IsFreeplayUnlocked() {
    return gSimsMemCardWrap->flags;
}
