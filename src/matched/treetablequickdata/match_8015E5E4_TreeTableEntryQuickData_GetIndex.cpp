// 0x8015E5E4 (12 bytes)
// TreeTableEntryQuickData::GetIndex(void) const
// lwz r9, 4(r3); lha r3, 20(r9); blr
struct TreeTableEntryData {
    char m_pad[20];
    short m_index;
};

class TreeTableEntryQuickData {
public:
    int m_pad0;
    TreeTableEntryData* m_data;
    short GetIndex() const;
};

short TreeTableEntryQuickData::GetIndex() const {
    return m_data->m_index;
}
