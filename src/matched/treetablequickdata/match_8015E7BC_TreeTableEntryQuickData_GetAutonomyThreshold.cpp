// 0x8015E7BC (12 bytes)
// TreeTableEntryQuickData::GetAutonomyThreshold(void) const
// lwz r9, 4(r3); lha r3, 22(r9); blr
struct TreeTableEntryData {
    char m_pad[22];
    short m_autonomyThreshold;
};

class TreeTableEntryQuickData {
public:
    int m_pad0;
    TreeTableEntryData* m_data;
    short GetAutonomyThreshold() const;
};

short TreeTableEntryQuickData::GetAutonomyThreshold() const {
    return m_data->m_autonomyThreshold;
}
