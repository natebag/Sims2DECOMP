// 0x80223F88 (12 bytes) - InteractorModule::WallManipulator::IsValidWallSegment(void)
// lwz r3, 196(r3); rlwinm r3,r3,25,31,31; blr  =>  (m_flags >> 7) & 1

struct WallManipulator_V {
    char pad[0xC4];
    int m_flags;
    int IsValidWallSegment();
};
int WallManipulator_V::IsValidWallSegment() {
    return (m_flags >> 7) & 1;
}
