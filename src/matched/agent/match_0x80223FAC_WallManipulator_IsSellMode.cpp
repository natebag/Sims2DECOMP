struct WallManipulator {
    char _pad[0xC4];
    unsigned int m_flags;
    int IsSellMode();
};
int WallManipulator::IsSellMode() { return (m_flags >> 3) & 1; }
