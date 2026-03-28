// 0x8015E768 (12 bytes)
// TreeTableEntryQuickData::GetActionTreeID(void) const
// lwz r9, 4(r3); lha r3, 2(r9); blr
struct TreeTableEntryData {
    short m_checkTreeID;
    short m_actionTreeID;
};

class TreeTableEntryQuickData {
public:
    int m_pad0;
    TreeTableEntryData* m_data;
    short GetActionTreeID() const;
};

short TreeTableEntryQuickData::GetActionTreeID() const {
    return m_data->m_actionTreeID;
}
