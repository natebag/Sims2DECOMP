// 0x8015E6D4 (16 bytes)
// TreeTableEntryQuickData::GetAvailableToVisitingPlayers(void) const
struct TreeTableEntryData {
    char m_pad[16];
    int m_flags;
};

class TreeTableEntryQuickData {
public:
    int m_pad0;
    TreeTableEntryData* m_data;
    int GetAvailableToVisitingPlayers() const;
};

int TreeTableEntryQuickData::GetAvailableToVisitingPlayers() const {
    return (m_data->m_flags >> 9) & 1;
}
