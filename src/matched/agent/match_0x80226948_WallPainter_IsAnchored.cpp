struct WallPainter {
    char _pad[0x88];
    int m_flags;
    int IsAnchored();
};
int WallPainter::IsAnchored() {
    int f = m_flags;
    if ((f & 1) == 0) {
        return 0;
    }
    return 1;
}
