// 0x8015E618 (16 bytes)
// TreeTableEntryQuickData::GetCanJoin(void) const
struct TreeTableEntryData {
    char m_pad[16];
    int m_flags;
};

class TreeTableEntryQuickData {
public:
    int m_pad0;
    TreeTableEntryData* m_data;
    int GetCanJoin() const;
};

int TreeTableEntryQuickData::GetCanJoin() const {
    return (m_data->m_flags >> 1) & 1;
}
