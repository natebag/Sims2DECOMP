// 0x80313310 EResPrefetchFile::ValidateStreamPos(void) (40B)

struct EResPrefetchFile {
    char _pad0[0x30];
    unsigned m_30;   // 0x30
    unsigned m_34;   // 0x34
    char _pad38[4];  // 0x38
    unsigned m_3c;   // 0x3c
    unsigned m_40;   // 0x40
    int ValidateStreamPos();
};

int EResPrefetchFile::ValidateStreamPos() {
    return (m_40 - m_3c) >= (m_30 - m_34);
}
