// 0x801dcdb4 R2LTarget::OldGridIndexToRecordIndex (52B)
// FLAGS: -fno-elide-constructors -fno-schedule-insns

class R2LTarget {
public:
    char pad[0x9C];
    int m_recordCount;        // 0x9C
    char pad2[0x8];
    int m_oldGridIndex;       // 0xA8

    int OldGridIndexToRecordIndex(int index);
};

int R2LTarget::OldGridIndexToRecordIndex(int index) {
    int pos = m_oldGridIndex;
    int result = index + pos * 6;
    if (pos < 0) goto fail;
    if (result < 0) goto fail;
    if (result < m_recordCount) return result;
fail:
    return -1;
}
