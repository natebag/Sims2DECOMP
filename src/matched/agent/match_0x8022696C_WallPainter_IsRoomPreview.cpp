struct WallPainter {
    char _pad[0x88];
    unsigned int m_flags;
    int IsRoomPreview();
};
int WallPainter::IsRoomPreview() { return (m_flags >> 4) & 1; }
