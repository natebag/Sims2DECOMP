struct WallManipulator {
    char _pad[0xC4];
    unsigned int m_flags;
    int IsDestructMode();
};
int WallManipulator::IsDestructMode() { return (m_flags >> 9) & 1; }
