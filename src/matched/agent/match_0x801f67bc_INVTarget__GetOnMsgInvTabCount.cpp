// 0x801F67BC INVTarget::GetOnMsgInvTabCount(char *) (52B)

extern int Sprintf(char* dest, const char* fmt, ...);

struct INVTarget {
    char pad[0xBC];
    int m_tabCount;
    void GetOnMsgInvTabCount(char* dest);
};

void INVTarget::GetOnMsgInvTabCount(char* dest) {
    Sprintf(dest, "%d", m_tabCount);
}
