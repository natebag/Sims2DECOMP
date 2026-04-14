/* TreeTableEntryQuickData::GetMinRef(int) const - 0x8015E73C - 24 bytes */
/* lwz r9,4(r3); slwi r4,r4,3; lwz r3,4(r9); add r3,r3,r4; addi r3,r3,2; blr */

struct TreeTableEntryData {
    char m_pad[4];
    char* m_ads;
};

class TreeTableEntryQuickData {
public:
    int m_pad0;
    TreeTableEntryData* m_data;

    short* GetMinRef(int index) const;
};

short* TreeTableEntryQuickData::GetMinRef(int index) const {
    return (short*)(m_data->m_ads + index * 8 + 2);
}