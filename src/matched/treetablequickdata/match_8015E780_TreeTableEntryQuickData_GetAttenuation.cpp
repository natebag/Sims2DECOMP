// 0x8015E780 (12 bytes)
// TreeTableEntryQuickData::GetAttenuation(void) const
// lwz r9, 4(r3); lhz r3, 14(r9); blr
struct TreeTableEntryData {
    char m_pad[14];
    unsigned short m_attenuation;
};

class TreeTableEntryQuickData {
public:
    int m_pad0;
    TreeTableEntryData* m_data;
    unsigned short GetAttenuation() const;
};

unsigned short TreeTableEntryQuickData::GetAttenuation() const {
    return m_data->m_attenuation;
}
