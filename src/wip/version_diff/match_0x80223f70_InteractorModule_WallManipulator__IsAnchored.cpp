// 0x80223f70 InteractorModule::WallManipulator::IsAnchored(void) (24B)

struct WallManipulator {
    char pad[0xC4];
    int m_flags;
    int IsAnchored(void);
};

int WallManipulator::IsAnchored(void) {
    return (m_flags & 1) != 0;
}
