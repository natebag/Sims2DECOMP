// 0x801F677C INVTarget::GetOnMsgInvCurrentCell(char*) (64B)
//
// Family-match with 0x801F673C GetOnMsgInvCurrentTab — same SDA2-table-indexed
// pattern but reads parallel cell-index table instead of tab-index table.
// Field name aligned with TypeArch's verified include/types/INVTarget.h
// (commit 224f219a6) — was m_idx, now m_currentTab (single field drives both
// per-tab lookups: per-tab current cell + per-tab tab index).

extern int g_currentCellTable;         // SDA2 table @ r13-28708 per TypeArch
extern char gInvCurrentCellFormat[];   // printf format string
int Sprintf(char* dst, char* fmt, ...);

struct INVTarget {
    char pad[0x84];
    int m_currentTab;
    void GetOnMsgInvCurrentCell(char* msg);
};

void INVTarget::GetOnMsgInvCurrentCell(char* msg) {
    int val = (&g_currentCellTable)[m_currentTab];
    Sprintf(msg, gInvCurrentCellFormat, val);
}
