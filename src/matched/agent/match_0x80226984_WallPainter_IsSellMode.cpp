struct WallPainter {
    char _pad[0x88];
    unsigned int m_flags;
    int IsSellMode();
};
int WallPainter::IsSellMode() { return (m_flags >> 3) & 1; }
