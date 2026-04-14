/* TreeTableQuickData::CountMotiveAds(void) const - 0x8015E8E8 - 24 bytes */
/* lwz r9,4(r3); cmpwi r9,0; li r3,0; beqlr; lha r3,4(r9); blr */

struct TreeTable {
    char m_pad[4];
    short m_motiveAdCount;
};

class TreeTableQuickData {
public:
    int m_pad0;
    TreeTable* m_impl;

    int CountMotiveAds() const;
};

int TreeTableQuickData::CountMotiveAds() const {
    if (m_impl == 0) return 0;
    return m_impl->m_motiveAdCount;
}