// 0x8015E714 (16 bytes)
// TreeTableEntryQuickData::GetMustRun(void) const
struct TreeTableEntryData {
    char m_pad[16];
    int m_flags;
};

class TreeTableEntryQuickData {
public:
    int m_pad0;
    TreeTableEntryData* m_data;
    int GetMustRun() const;
};

int TreeTableEntryQuickData::GetMustRun() const {
    return (m_data->m_flags >> 11) & 1;
}
