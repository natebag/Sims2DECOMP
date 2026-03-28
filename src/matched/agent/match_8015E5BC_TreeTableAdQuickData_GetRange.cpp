// 0x8015E5BC (12 bytes)
// TreeTableAdQuickData::GetRange(void) const
// lwz r9, 4(r3); lha r3, 4(r9); blr
struct TreeTableAdData {
    char m_pad[4];
    short m_range;
};

class TreeTableAdQuickData {
public:
    int m_pad0;
    TreeTableAdData* m_data;
    short GetRange() const;
};

short TreeTableAdQuickData::GetRange() const {
    return m_data->m_range;
}
