// 0x8015E66C (16 bytes)
// TreeTableEntryQuickData::GetAvailableToChildrenDemo(void) const
struct TreeTableEntryData {
    char m_pad[16];
    int m_flags;
};

class TreeTableEntryQuickData {
public:
    int m_pad0;
    TreeTableEntryData* m_data;
    int GetAvailableToChildrenDemo() const;
};

int TreeTableEntryQuickData::GetAvailableToChildrenDemo() const {
    return (m_data->m_flags >> 5) & 1;
}
