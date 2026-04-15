// 0x80223F70 (24B) InteractorModule::WallManipulator::IsAnchored(void)

struct WallManipulator {
    char pad[196];
    unsigned int m_flags;
    bool IsAnchored();
};

bool WallManipulator::IsAnchored() {
    if ((m_flags & 1) == 0) return 0;
    return 1;
}
