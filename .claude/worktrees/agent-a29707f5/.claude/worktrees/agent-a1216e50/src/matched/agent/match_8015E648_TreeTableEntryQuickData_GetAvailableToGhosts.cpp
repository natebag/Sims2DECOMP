// 0x8015E648 (16 bytes)
// TreeTableEntryQuickData::GetAvailableToGhosts(void) const
struct TreeTableEntryData {
    char m_pad[16];
    int m_flags;
};

class TreeTableEntryQuickData {
public:
    int m_pad0;
    TreeTableEntryData* m_data;
    int GetAvailableToGhosts() const;
};

int TreeTableEntryQuickData::GetAvailableToGhosts() const {
    return (m_data->m_flags >> 4) & 1;
}
