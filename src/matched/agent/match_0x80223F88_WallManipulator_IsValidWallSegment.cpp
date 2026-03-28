struct WallManipulator {
    char _pad[0xC4];
    unsigned int m_flags;
    int IsValidWallSegment();
};
int WallManipulator::IsValidWallSegment() { return (m_flags >> 7) & 1; }
