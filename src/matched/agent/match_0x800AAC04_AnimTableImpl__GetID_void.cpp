// 0x800AAC04 AnimTableImpl::GetID(void) (12 B)
// FLAGS: -fno-schedule-insns
// Pattern: lwz r9,0x4(r3); lha r3,0x4(r9); blr

struct AnimTableData {
    short m_unknown0; // 0x0
    short m_unknown2; // 0x2
    short m_id;       // 0x4
};

struct AnimTableImpl {
    char _pad[0x4];
    AnimTableData* m_data; // 0x4

    short GetID();
};

short AnimTableImpl::GetID() {
    return m_data->m_id;
}
