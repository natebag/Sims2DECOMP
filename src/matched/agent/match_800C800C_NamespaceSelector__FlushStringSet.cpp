/* NamespaceSelector::FlushStringSet(short) - 0x800C800C (36 bytes) */

struct DataCacheList { int m_data[2]; };

struct NamespaceSelector {
    char m_pad[0x08];
    DataCacheList m_stringSets;

    void FlushStringSet(short id);
    void FlushCacheItem(short id, DataCacheList &list);
};

void NamespaceSelector::FlushStringSet(short id) {
    FlushCacheItem(id, m_stringSets);
}
