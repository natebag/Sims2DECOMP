// 0x80223FC4 (12 bytes) - InteractorModule::WallManipulator::IsDestructMode(void)
// lwz r3, 196(r3); rlwinm r3,r3,23,31,31; blr  =>  (m_flags >> 9) & 1

struct WallManipulator_DM {
    char pad[0xC4];
    int m_flags;
    int IsDestructMode();
};
int WallManipulator_DM::IsDestructMode() {
    return (m_flags >> 9) & 1;
}
