/* TreeTableAdQuickData::GetMax(void) const - 0x8015E5A8 - 20 bytes */
/* lwz r9,4(r3); lha r0,4(r9); lha r3,2(r9); add r3,r3,r0; blr */

struct TreeTableAdData {
    short m_personalityAd;
    short m_min;
    short m_range;
};

class TreeTableAdQuickData {
public:
    int m_pad0;
    TreeTableAdData* m_data;

    int GetMax() const;
};

int TreeTableAdQuickData::GetMax() const {
    return m_data->m_min + m_data->m_range;
}