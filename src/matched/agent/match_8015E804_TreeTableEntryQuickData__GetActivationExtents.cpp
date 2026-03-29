/* TreeTableEntryQuickData::GetActivationExtents(uchar&,uchar&,uchar&,uchar&) const */
/* 0x8015E804 - 56 bytes */

struct TreeTableEntryData {
    char m_pad[32];
    unsigned int m_activationData;
};

class TreeTableEntryQuickData {
public:
    int m_pad0;
    TreeTableEntryData* m_data;

    void GetActivationExtents(unsigned char& a, unsigned char& b,
                               unsigned char& c, unsigned char& d) const;
};

void TreeTableEntryQuickData::GetActivationExtents(unsigned char& a, unsigned char& b,
                                                     unsigned char& c, unsigned char& d) const {
    TreeTableEntryData* p = m_data;
    a = (unsigned char)((p->m_activationData >> 8) & 0x3F);
    b = (unsigned char)((p->m_activationData >> 14) & 0x3F);
    c = (unsigned char)((p->m_activationData >> 20) & 0x3F);
    d = (unsigned char)((p->m_activationData >> 26) & 0x3F);
}