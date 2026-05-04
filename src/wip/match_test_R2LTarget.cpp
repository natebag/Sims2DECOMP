// R2LTarget remaining functions

class R2LTarget {
public:
    char pad[0x9C];
    int m_recordCount;        // 0x9C
    int m_gridIndex;          // 0xA4
    int m_oldGridIndex;       // 0xA8

    int GridIndexToRecordIndex(int index);
    int OldGridIndexToRecordIndex(int index);
    int ScrollRightEnabled(void);
};

int R2LTarget::GridIndexToRecordIndex(int index) {
    int result = m_gridIndex * 6 + index;
    if (result < 0) return -1;
    if (result >= m_recordCount) return -1;
    return result;
}

int R2LTarget::OldGridIndexToRecordIndex(int index) {
    int oldGrid = m_oldGridIndex;
    if (oldGrid < 0) return -1;
    int result = oldGrid * 6 + index;
    if (result < 0) return -1;
    if (result >= m_recordCount) return -1;
    return result;
}

int R2LTarget::ScrollRightEnabled(void) {
    if (m_recordCount - (m_gridIndex + 1) * 6 > 0) return 1;
    return 0;
}
