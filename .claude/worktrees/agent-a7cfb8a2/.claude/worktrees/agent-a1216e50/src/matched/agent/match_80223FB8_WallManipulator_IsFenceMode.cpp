// 0x80223FB8 (12 bytes) - InteractorModule::WallManipulator::IsFenceMode(void)
// lwz r3, 196(r3); rlwinm r3,r3,24,31,31; blr  =>  (m_flags >> 8) & 1

struct WallManipulator_FM {
    char pad[0xC4];
    int m_flags;
    int IsFenceMode();
};
int WallManipulator_FM::IsFenceMode() {
    return (m_flags >> 8) & 1;
}
