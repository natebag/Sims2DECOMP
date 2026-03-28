/* NamespaceSelector::GetSoundInfo(short) - 48 bytes */

struct DataCacheList { int m_data[2]; };

struct NamespaceSelector {
    char m_pad[0x18];
    DataCacheList m_soundInfo;

    void *GetSoundInfo(short id);
    void *GetCacheItem(short id, DataCacheList &list, unsigned int hash, unsigned int type);
};

void *NamespaceSelector::GetSoundInfo(short id) {
    return GetCacheItem(id, m_soundInfo, 0x6BF17876, 1);
}
