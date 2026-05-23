// 0x801F673C INVTarget::GetOnMsgInvCurrentTab(char*) (64B)
//
// Reads m_currentTab @ 0x84, uses as index into SDA2 tab table, formats result
// via Sprintf. Field name aligned with TypeArch's verified include/types/INVTarget.h
// (commit 224f219a6) — was m_idx, now m_currentTab.

extern int g_currentTabTable;          // SDA2 table, indexed by m_currentTab
extern char gInvCurrentTabFormat[];    // printf format string
int Sprintf(char* dst, char* fmt, ...);

struct INVTarget {
    char pad[0x84];
    int m_currentTab;
    void GetOnMsgInvCurrentTab(char* msg);
};

void INVTarget::GetOnMsgInvCurrentTab(char* msg) {
    int val = (&g_currentTabTable)[m_currentTab];
    Sprintf(msg, gInvCurrentTabFormat, val);
}
