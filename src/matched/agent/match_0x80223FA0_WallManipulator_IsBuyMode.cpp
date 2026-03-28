struct WallManipulator {
    char _pad[0xC4];
    unsigned int m_flags;
    int IsBuyMode();
};
int WallManipulator::IsBuyMode() { return (m_flags >> 2) & 1; }
