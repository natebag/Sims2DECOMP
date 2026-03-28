struct WallPainter {
    char _pad[0x88];
    unsigned int m_flags;
    int IsValidWallSegment();
};
int WallPainter::IsValidWallSegment() { return (m_flags >> 7) & 1; }
