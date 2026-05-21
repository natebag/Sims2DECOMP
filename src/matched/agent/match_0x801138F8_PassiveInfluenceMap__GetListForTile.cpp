// 0x801138F8 PassiveInfluenceMap::GetListForTile(int, int) (76B)

struct PassiveListEntry {
    char _pad[16];
};

class PassiveInfluenceMap {
public:
    int m_width;
    int m_height;
    PassiveListEntry* m_array;
    PassiveListEntry* GetListForTile(int x, int y);
};

PassiveListEntry* PassiveInfluenceMap::GetListForTile(int x, int y) {
    if (x < 0) goto fail;
    if (y < 0) goto fail;
    if (x >= m_width) goto fail;
    if (y < m_height) goto success;
fail:
    return 0;
success:
    {
        unsigned int idx = (unsigned int)(x * m_height + y);
        unsigned int base = (unsigned int)m_array;
        return (PassiveListEntry*)(base + (idx << 4));
    }
}
