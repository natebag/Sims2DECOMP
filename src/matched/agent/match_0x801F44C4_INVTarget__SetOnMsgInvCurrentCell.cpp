// 0x801F44C4 INVTarget::SetOnMsgInvCurrentCell(char*) (88B)
// Pattern: AtoI(msg) + SDA2 table store at m_playerIdx + conditional cheat call
extern int g_cheatMgrPtr[3];
extern int g_cellCheatTable;  // SDA2 single int, arith-indexed
extern int AtoI(char*);

struct INVTarget {
    char pad[132];
    int m_playerIdx;
    void Cheat_HandleCellChange();
    void SetOnMsgInvCurrentCell(char* msg);
};

void INVTarget::SetOnMsgInvCurrentCell(char* msg) {
    int val = AtoI(msg);
    (&g_cellCheatTable)[m_playerIdx] = val;
    if (g_cheatMgrPtr[0] != 0) {
        Cheat_HandleCellChange();
    }
}
