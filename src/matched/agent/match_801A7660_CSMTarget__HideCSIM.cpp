class CSMTarget {
public:
    char _pad[0x90];
    int m_showCSIM;
    char _pad2[4];
    int m_csimFlag;

    void HideCSIM();
};

void CSMTarget::HideCSIM() {
    if (m_csimFlag == 0) {
        m_showCSIM = 0;
    }
}
