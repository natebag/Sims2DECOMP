// 0x80223FAC (12 bytes) - InteractorModule::WallManipulator::IsSellMode(void)
// lwz r3, 196(r3); rlwinm r3,r3,29,31,31; blr  =>  (m_flags >> 3) & 1

struct WallManipulator_SM {
    char pad[0xC4];
    int m_flags;
    int IsSellMode();
};
int WallManipulator_SM::IsSellMode() {
    return (m_flags >> 3) & 1;
}
