// 0x80199E5C CASSelectionTarget::ConvertGridIdxToOptionIdx(unsigned int) (20B)
// idx + (m_gridBase * 4 - 8)

struct CASSelectionTarget {
    char pad[1352];
    int m_gridBase;
    int ConvertGridIdxToOptionIdx(unsigned int idx);
};

int CASSelectionTarget::ConvertGridIdxToOptionIdx(unsigned int idx) {
    int v = m_gridBase;
    v <<= 2;
    v -= 8;
    return (int)idx + v;
}
