class CSMTarget {
public:
    char _pad[0x90];
    int m_showCSIM;
    char _pad2[4];
    int m_csimFlag;

    void ShowCSIM();
};

void CSMTarget::ShowCSIM() {
    m_showCSIM = 1;
    m_csimFlag = 0;
}
