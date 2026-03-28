// 0x8015E638 (16 bytes)
// TreeTableEntryQuickData::GetAllowConsecutive(void) const
struct TreeTableEntryData {
    char m_pad[16];
    int m_flags;
};

class TreeTableEntryQuickData {
public:
    int m_pad0;
    TreeTableEntryData* m_data;
    int GetAllowConsecutive() const;
};

int TreeTableEntryQuickData::GetAllowConsecutive() const {
    return (m_data->m_flags >> 3) & 1;
}
