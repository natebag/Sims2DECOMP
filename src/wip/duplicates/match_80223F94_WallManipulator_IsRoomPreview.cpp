// 0x80223F94 (12 bytes) - InteractorModule::WallManipulator::IsRoomPreview(void)
// lwz r3, 196(r3); rlwinm r3,r3,28,31,31; blr  =>  (m_flags >> 4) & 1

struct WallManipulator_RP {
    char pad[0xC4];
    int m_flags;
    int IsRoomPreview();
};
int WallManipulator_RP::IsRoomPreview() {
    return (m_flags >> 4) & 1;
}
