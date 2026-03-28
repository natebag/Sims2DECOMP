class INGTarget {
public:
    char _pad[0x458];
    int m_rcpState;

    int RCPOnCancel(void);
};

int INGTarget::RCPOnCancel(void) {
    m_rcpState = 2;
    return 1;
}
