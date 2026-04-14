// 0x801f6570 INVTarget::SetOnMsgInvShpCurrentCell(char *) (52B)

extern int AtoI(char*);

struct INVTarget {
    char pad[0x3251];
    char m_cell;
    void SetOnMsgInvShpCurrentCell(char* str);
};

void INVTarget::SetOnMsgInvShpCurrentCell(char* str) {
    m_cell = (char)AtoI(str);
}
