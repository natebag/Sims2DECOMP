// 0x801F677C INVTarget::GetOnMsgInvCurrentCell(char*) (64B)
// Pattern: SDA2 table lookup via extern int + pointer arith + Sprintf varargs
// Family-match with 0x801F673C GetOnMsgInvCurrentTab template
extern int g_table_currentCell;
extern char gFormat_CurrentCell[];
int Sprintf(char* dst, char* fmt, ...);

struct INVTarget {
    char pad[132];
    int m_idx;
    void GetOnMsgInvCurrentCell(char* msg);
};

void INVTarget::GetOnMsgInvCurrentCell(char* msg) {
    int val = (&g_table_currentCell)[m_idx];
    Sprintf(msg, gFormat_CurrentCell, val);
}
