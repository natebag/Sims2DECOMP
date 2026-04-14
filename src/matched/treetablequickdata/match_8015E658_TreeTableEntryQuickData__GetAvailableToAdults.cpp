/* TreeTableEntryQuickData::GetAvailableToAdults(void) const - 0x8015E658 - 20 bytes */
/* lwz r9,4(r3); lwz r3,16(r9); xori r3,r3,0x40; rlwinm r3,r3,26,31,31; blr */

struct TreeTableEntryData {
    char m_pad[16];
    int m_flags;
};

class TreeTableEntryQuickData {
public:
    int m_pad0;
    TreeTableEntryData* m_data;

    int GetAvailableToAdults() const;
};

int TreeTableEntryQuickData::GetAvailableToAdults() const {
    return ((m_data->m_flags ^ 0x40) >> 6) & 1;
}