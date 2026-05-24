// FLAGS: -fno-schedule-insns
// 0x8018CCE8 LoadGameTarget::GetPlayerNum(void) (12B)
// lwz r9,0x118(r3); lwz r3,0x190(r9); blr
struct GameModeState {
    char pad[0x190];
    int m_playerNum;  // offset 0x190
};
struct LoadGameTarget {
    char pad[0x118];
    GameModeState* m_state;  // offset 0x118
    int GetPlayerNum() const;
};
int LoadGameTarget::GetPlayerNum() const {
    return m_state->m_playerNum;
}
