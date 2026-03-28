// 0x8015E774 (12 bytes)
// TreeTableEntryQuickData::GetCheckTreeID(void) const
// lwz r9, 4(r3); lha r3, 0(r9); blr
struct TreeTableEntryData {
    short m_checkTreeID;
};

class TreeTableEntryQuickData {
public:
    int m_pad0;
    TreeTableEntryData* m_data;
    short GetCheckTreeID() const;
};

short TreeTableEntryQuickData::GetCheckTreeID() const {
    return m_data->m_checkTreeID;
}
