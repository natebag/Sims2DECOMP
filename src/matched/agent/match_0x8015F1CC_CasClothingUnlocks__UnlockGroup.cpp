// 0x8015F1CC CasClothingUnlocks::UnlockGroup(unsigned int, bool) (40B)
// Thunk: MarkGroup(group, false, flag)
struct CasClothingUnlocks {
    void MarkGroup(unsigned int group, bool lock, bool flag);
    void UnlockGroup(unsigned int group, bool flag);
};
void CasClothingUnlocks::UnlockGroup(unsigned int group, bool flag) {
    MarkGroup(group, false, flag);
}
