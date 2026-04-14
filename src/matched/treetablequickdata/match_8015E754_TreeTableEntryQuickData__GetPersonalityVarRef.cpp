/* TreeTableEntryQuickData::GetPersonalityVarRef(int) const - 0x8015E754 - 20 bytes */
/* lwz r9,4(r3); slwi r4,r4,3; lwz r3,4(r9); add r3,r3,r4; blr */

struct TreeTableEntryData {
    char m_pad[4];
    char* m_ads;
};

class TreeTableEntryQuickData {
public:
    int m_pad0;
    TreeTableEntryData* m_data;

    short* GetPersonalityVarRef(int index) const;
};

short* TreeTableEntryQuickData::GetPersonalityVarRef(int index) const {
    return (short*)(m_data->m_ads + index * 8);
}