// 0x801dce00 R2LTarget::ScrollRightEnabled (40B)

class R2LTarget {
public:
    char pad[0x9C];
    int m_recordCount;        // 0x9C
    char pad2[0x4];
    int m_gridIndex;          // 0xA4

    int ScrollRightEnabled(void);
};

int R2LTarget::ScrollRightEnabled(void) {
    if (m_recordCount - (m_gridIndex + 1) * 6 > 0) return 1;
    return 0;
}
