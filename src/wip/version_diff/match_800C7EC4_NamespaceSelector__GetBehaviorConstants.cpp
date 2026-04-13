/* NamespaceSelector::GetBehaviorConstants(short) - 48 bytes */

struct DataCacheList { int m_data[2]; };

struct NamespaceSelector {
    char m_pad[0x10];
    DataCacheList m_behaviorConstants;
    DataCacheList m_soundInfo;
    DataCacheList m_stringSet;

    void *GetBehaviorConstants(short id);
    void *GetCacheItem(short id, DataCacheList &list, unsigned int hash, unsigned int type);
};

void *NamespaceSelector::GetBehaviorConstants(short id) {
    return GetCacheItem(id, m_behaviorConstants, 0xEBD8CAB4, 3);
}
