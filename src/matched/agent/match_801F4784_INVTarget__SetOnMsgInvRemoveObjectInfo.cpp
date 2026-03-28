class INVTarget {
public:
    char pad[0x88];
    int m_field88;
    int SetOnMsgInvRemoveObjectInfo(char *msg);
};

int INVTarget::SetOnMsgInvRemoveObjectInfo(char *msg) {
    m_field88 = 0;
    return 1;
}
