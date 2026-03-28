// 0x8015E628 (16 bytes)
// TreeTableEntryQuickData::GetImmediate(void) const
struct TreeTableEntryData {
    char m_pad[16];
    int m_flags;
};

class TreeTableEntryQuickData {
public:
    int m_pad0;
    TreeTableEntryData* m_data;
    int GetImmediate() const;
};

int TreeTableEntryQuickData::GetImmediate() const {
    return (m_data->m_flags >> 2) & 1;
}
