// 0x8015E67C (12 bytes)
// TreeTableEntryQuickData::GetJoinIndex(void) const
// lwz r9, 4(r3); lha r3, 24(r9); blr
struct TreeTableEntryData {
    char m_pad[24];
    short m_joinIndex;
};

class TreeTableEntryQuickData {
public:
    int m_pad0;
    TreeTableEntryData* m_data;
    short GetJoinIndex() const;
};

short TreeTableEntryQuickData::GetJoinIndex() const {
    return m_data->m_joinIndex;
}
