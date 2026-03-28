// 0x8015E704 (16 bytes)
// TreeTableEntryQuickData::GetIgnorePrefixTree(void) const
struct TreeTableEntryData {
    char m_pad[16];
    int m_flags;
};

class TreeTableEntryQuickData {
public:
    int m_pad0;
    TreeTableEntryData* m_data;
    int GetIgnorePrefixTree() const;
};

int TreeTableEntryQuickData::GetIgnorePrefixTree() const {
    return (m_data->m_flags >> 10) & 1;
}
