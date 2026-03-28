// 0x8015E59C (12 bytes)
// TreeTableAdQuickData::GetMin(void) const
// lwz r9, 4(r3); lha r3, 2(r9); blr
struct TreeTableAdData {
    short m_personalityAd;
    short m_min;
};

class TreeTableAdQuickData {
public:
    int m_pad0;
    TreeTableAdData* m_data;
    short GetMin() const;
};

short TreeTableAdQuickData::GetMin() const {
    return m_data->m_min;
}
