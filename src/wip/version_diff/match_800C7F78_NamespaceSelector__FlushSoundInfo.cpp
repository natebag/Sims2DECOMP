/* NamespaceSelector::FlushSoundInfo(short) - 0x800C7F78 (36 bytes) */

struct DataCacheList { int m_data[2]; };

struct NamespaceSelector {
    char m_pad[0x18];
    DataCacheList m_soundInfos;

    void FlushSoundInfo(short id);
    void FlushCacheItem(short id, DataCacheList &list);
};

void NamespaceSelector::FlushSoundInfo(short id) {
    FlushCacheItem(id, m_soundInfos);
}
