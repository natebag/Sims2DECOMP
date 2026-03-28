// 0x8015E590 (12 bytes)
// TreeTableAdQuickData::GetPersonalityAd(void) const
// lwz r9, 4(r3); lha r3, 0(r9); blr
struct TreeTableAdData {
    short m_personalityAd;
};

class TreeTableAdQuickData {
public:
    int m_pad0;
    TreeTableAdData* m_data;
    short GetPersonalityAd() const;
};

short TreeTableAdQuickData::GetPersonalityAd() const {
    return m_data->m_personalityAd;
}
