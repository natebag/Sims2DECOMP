// 0x80149B30 (16 bytes)
// TreeTableAdScratch::SetMax(int)
class TreeTableAdScratch {
    char pad[6];
    short m_field6;
    short m_field8;
public:
    void SetMax(int val);
};

void TreeTableAdScratch::SetMax(int val) {
    m_field8 = val - m_field6;
}
