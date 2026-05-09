// InfluenceMap::GetObjectList(int, int) at 0x80049294 (76 bytes)
// Bounds-checked array indexer: returns &m_array[x * m_height + y] or NULL.

struct ObjectListEntry {
    char _pad[16];
};

class InfluenceMap {
public:
    int m_width;                 // offset 0
    int m_height;                // offset 4
    ObjectListEntry* m_array;    // offset 8
    ObjectListEntry* GetObjectList(int x, int y);
};

ObjectListEntry* InfluenceMap::GetObjectList(int x, int y) {
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
        return (ObjectListEntry*)((idx << 4) + base);
    }
}
