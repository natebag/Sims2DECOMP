// 0x80149B20 (16 bytes)
// TreeTableAdScratch::GetMax(void) const
class TreeTableAdScratch {
    char pad[6];
    short m_field6;
    short m_field8;
public:
    int GetMax() const;
};

int TreeTableAdScratch::GetMax() const {
    return m_field6 + m_field8;
}
