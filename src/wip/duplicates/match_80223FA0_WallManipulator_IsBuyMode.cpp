// 0x80223FA0 (12 bytes) - InteractorModule::WallManipulator::IsBuyMode(void)
// lwz r3, 196(r3); rlwinm r3,r3,30,31,31; blr  =>  (m_flags >> 2) & 1

struct WallManipulator_BM {
    char pad[0xC4];
    int m_flags;
    int IsBuyMode();
};
int WallManipulator_BM::IsBuyMode() {
    return (m_flags >> 2) & 1;
}
