struct WallManipulator {
    char _pad[0xC4];
    unsigned int m_flags;
    int IsRoomPreview();
};
int WallManipulator::IsRoomPreview() { return (m_flags >> 4) & 1; }
