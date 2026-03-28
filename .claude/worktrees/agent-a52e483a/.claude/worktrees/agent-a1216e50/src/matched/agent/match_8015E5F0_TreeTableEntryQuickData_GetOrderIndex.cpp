// 0x8015E5F0 (12 bytes)
// TreeTableEntryQuickData::GetOrderIndex(void) const
// lwz r9, 4(r3); lha r3, 26(r9); blr
struct TreeTableEntryData {
    char m_pad[26];
    short m_orderIndex;
};

class TreeTableEntryQuickData {
public:
    int m_pad0;
    TreeTableEntryData* m_data;
    short GetOrderIndex() const;
};

short TreeTableEntryQuickData::GetOrderIndex() const {
    return m_data->m_orderIndex;
}
