// 0x8002193C ECheatDMI::GetVariable(void) (12 B)
// FLAGS: -fno-schedule-insns
// Pattern: lwz r9,0xc(r3); lwz r3,0x50(r9); blr

struct ECheatInfo {
    char _pad[0x4C];
    int m_type;     // 0x4C
    int m_variable; // 0x50
};

struct ECheatDMI {
    char _pad[0xC];
    ECheatInfo* m_info; // 0xC

    int GetVariable();
};

int ECheatDMI::GetVariable() {
    return m_info->m_variable;
}
