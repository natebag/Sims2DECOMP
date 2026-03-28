// 0x8015E6C4 (16 bytes)
// TreeTableEntryQuickData::GetAutoFirstSelect(void) const
struct TreeTableEntryData {
    char m_pad[16];
    int m_flags;
};

class TreeTableEntryQuickData {
public:
    int m_pad0;
    TreeTableEntryData* m_data;
    int GetAutoFirstSelect() const;
};

int TreeTableEntryQuickData::GetAutoFirstSelect() const {
    return (m_data->m_flags >> 8) & 1;
}
