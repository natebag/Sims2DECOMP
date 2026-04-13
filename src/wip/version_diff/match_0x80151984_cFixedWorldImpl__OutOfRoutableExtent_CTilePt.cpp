// FLAGS: -fno-elide-constructors
struct CFW_OORE {
    char _pad[0x1C];
    int m_minX;
    int m_maxX;
    int m_minY;
    int m_maxY;

    int OutOfRoutableExtent(unsigned char *tilePt);
};

int CFW_OORE::OutOfRoutableExtent(unsigned char *tilePt) {
    int result = 0;
    signed char x = (signed char)tilePt[0];
    if (x >= m_minX && x <= m_maxX) {
        signed char y = (signed char)tilePt[1];
        if (y >= m_minY && y <= m_maxY) {
            result = 1;
        }
    }
    return result;
}
