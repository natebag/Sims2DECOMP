/* TreeTableEntryQuickData::GetActivationSubtile(unsigned char &, unsigned char &) const */
/* 0x8015E7E4 - 32 bytes */

struct TreeTableEntryData {
    char m_pad[32];
    unsigned int m_activationData;
};

class TreeTableEntryQuickData {
public:
    int m_pad0;
    TreeTableEntryData* m_data;

    void GetActivationSubtile(unsigned char& x, unsigned char& y) const;
};

void TreeTableEntryQuickData::GetActivationSubtile(unsigned char& x, unsigned char& y) const {
    TreeTableEntryData* d = m_data;
    unsigned int val = d->m_activationData;
    x = (unsigned char)(val & 0xF);
    y = (unsigned char)((d->m_activationData >> 4) & 0xF);
}