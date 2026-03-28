class CASSelectionTarget {
public:
    unsigned int ConvertGridIdxToOptionIdx(unsigned int gridIdx);
    unsigned int ConvertColRowToOptionIdx(char col, int row);
};

unsigned int CASSelectionTarget::ConvertColRowToOptionIdx(char col, int row) {
    return ConvertGridIdxToOptionIdx((unsigned int)(col * 4 + (row - 261)));
}
