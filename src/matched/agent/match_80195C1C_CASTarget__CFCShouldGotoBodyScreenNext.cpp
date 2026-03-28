class CASTarget {
public:
    char _pad[0xA4];
    int m_curFocus;
    char _pad2[0x5C];
    int m_viewMode;

    int CFCShouldGotoBodyScreenNext(void);
};

int CASTarget::CFCShouldGotoBodyScreenNext(void) {
    if (m_viewMode == 0 && m_curFocus == 0x13) {
        return 1;
    }
    return 0;
}
