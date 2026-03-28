// 0x80021930 (12 bytes) — lwz r9, 0xC(r3); lwz r3, 0x4C(r9); blr
// Double dereference: load pointer at 0xC, then int at 0x4C

struct CheatData {
    char _pad[0x4C];
    int m_type;
};

class ECheatDMI {
public:
    char _pad[0xC];
    CheatData* m_data;

    int GetType();
};

int ECheatDMI::GetType() {
    return m_data->m_type;
}
