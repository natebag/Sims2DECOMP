// 0x801f4550 INVTarget::SetOnMsgInvPrevTab(char *) (52B)

extern int g_invTabTable[]; // SDA at r13-28708

struct INVTarget {
    char pad[0x84];
    int m_tabIndex;
    void OnSetCurrentTab(int);
    void SetOnMsgInvPrevTab(char* str);
};

void INVTarget::SetOnMsgInvPrevTab(char* str) {
    int tab = g_invTabTable[m_tabIndex];
    OnSetCurrentTab(tab - 1);
}
