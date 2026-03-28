class INGTarget {
public:
    char _pad[0x458];
    int m_rcpState;

    int RCPOnCancel();
};

int INGTarget::RCPOnCancel() {
    m_rcpState = 2;
    return 1;
}
