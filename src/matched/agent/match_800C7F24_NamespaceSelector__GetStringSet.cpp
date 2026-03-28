/* NamespaceSelector::GetStringSet(short) - 48 bytes */

struct DataCacheList { int m_data[2]; };

struct NamespaceSelector {
    char m_pad[0x08];
    DataCacheList m_stringSet;

    void *GetStringSet(short id);
    void *GetCacheItem(short id, DataCacheList &list, unsigned int hash, unsigned int type);
};

void *NamespaceSelector::GetStringSet(short id) {
    return GetCacheItem(id, m_stringSet, 0x6BC37BC5, 2);
}
