// 0x8015F1F4 CasClothingUnlocks::LockGroup(unsigned int) (40B)
// Thunk: MarkGroup(group, true, false)
struct CasClothingUnlocks {
    void MarkGroup(unsigned int group, bool lock, bool flag);
    void LockGroup(unsigned int group);
};
void CasClothingUnlocks::LockGroup(unsigned int group) {
    MarkGroup(group, true, false);
}
