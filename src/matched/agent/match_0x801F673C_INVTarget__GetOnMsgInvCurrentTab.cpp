// 0x801F673C INVTarget::GetOnMsgInvCurrentTab(char*) (64B)
// SDA2 table lookup via extern int + pointer arith + Sprintf varargs
extern int g_table;
extern char gFormat[];
int Sprintf(char* dst, char* fmt, ...);

struct INVTarget {
    char pad[132];
    int m_idx;
    void GetOnMsgInvCurrentTab(char* msg);
};

void INVTarget::GetOnMsgInvCurrentTab(char* msg) {
    int val = (&g_table)[m_idx];
    Sprintf(msg, gFormat, val);
}
