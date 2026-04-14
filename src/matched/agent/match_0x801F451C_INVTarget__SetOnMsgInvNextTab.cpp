// 0x801F451C INVTarget::SetOnMsgInvNextTab(char*) (40B)
struct INVTarget {
    char pad[132];
    int m_tabIndex;
};

extern char* g_invTabStrings[1];  // SDA table (small size)

extern void INVTarget__SetOnMsgCommon(INVTarget* self, char* s);

void INVTarget__SetOnMsgInvNextTab(INVTarget* self, char* msg) {
    (void)msg;
    INVTarget__SetOnMsgCommon(self, g_invTabStrings[self->m_tabIndex] + 1);
}
