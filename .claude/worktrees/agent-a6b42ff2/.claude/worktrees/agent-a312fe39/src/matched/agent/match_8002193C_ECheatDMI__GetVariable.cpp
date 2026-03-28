// 0x8002193C (12 bytes) — lwz r9, 0xC(r3); lwz r3, 0x50(r9); blr
// Double dereference: load pointer at 0xC, then int at 0x50

struct CheatData {
    char _pad[0x50];
    int m_variable;
};

class ECheatDMI {
public:
    char _pad[0xC];
    CheatData* m_data;

    int GetVariable();
};

int ECheatDMI::GetVariable() {
    return m_data->m_variable;
}
