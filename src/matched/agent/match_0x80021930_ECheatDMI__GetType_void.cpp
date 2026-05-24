// 0x80021930 ECheatDMI::GetType(void) (12 B)
// FLAGS: -fno-schedule-insns
// Pattern: lwz r9,0xc(r3); lwz r3,0x4c(r9); blr

struct ECheatInfo {
    char _pad[0x4C];
    int m_type; // 0x4C
};

struct ECheatDMI {
    char _pad[0xC];
    ECheatInfo* m_info; // 0xC

    int GetType();
};

int ECheatDMI::GetType() {
    return m_info->m_type;
}
