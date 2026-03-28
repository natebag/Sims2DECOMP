struct WallPainter {
    char _pad[0x88];
    unsigned int m_flags;
    int IsBuyMode();
};
int WallPainter::IsBuyMode() { return (m_flags >> 2) & 1; }
