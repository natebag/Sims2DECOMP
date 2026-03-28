// 0x8015E7D4 (16 bytes)
// TreeTableEntryQuickData::GetUseCustomActivation(void) const
struct TreeTableEntryData {
    char m_pad[16];
    int m_flags;
};

class TreeTableEntryQuickData {
public:
    int m_pad0;
    TreeTableEntryData* m_data;
    int GetUseCustomActivation() const;
};

int TreeTableEntryQuickData::GetUseCustomActivation() const {
    return (m_data->m_flags >> 12) & 1;
}
