// 0x80232DF8 ERLevel::ClearJustReadByLevelFlags(void) (68 B)

struct EInstance { unsigned flags[24]; };
struct ERLevel {
    char pad0[0x2A2B8];
    EInstance* instances[0x800];
    char pad1[0x2000 - 0x800 * 4];
    int instanceCount;
    void ClearJustReadByLevelFlags();
};

void ERLevel::ClearJustReadByLevelFlags() {
    for (int i = 0; i < instanceCount; i++) {
        instances[i]->flags[23] &= ~0x4000;
    }
}
