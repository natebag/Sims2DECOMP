class INVTarget {
public:
    char pad[0x88];
    int m_field88;
    void SetOnMsgInvShpRemoveObjectInfo(char *msg);
};

void INVTarget::SetOnMsgInvShpRemoveObjectInfo(char *msg) {
    m_field88 = 0;
}
