struct WallManipulator {
    char _pad[0xC4];
    unsigned int m_flags;
    int IsFenceMode();
};
int WallManipulator::IsFenceMode() { return (m_flags >> 8) & 1; }
