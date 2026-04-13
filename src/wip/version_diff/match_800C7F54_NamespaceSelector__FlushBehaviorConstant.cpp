/* NamespaceSelector::FlushBehaviorConstant(short) - 0x800C7F54 (36 bytes) */

struct DataCacheList { int m_data[2]; };

struct NamespaceSelector {
    char m_pad[0x10];
    DataCacheList m_behaviorConstants;

    void FlushBehaviorConstant(short id);
    void FlushCacheItem(short id, DataCacheList &list);
};

void NamespaceSelector::FlushBehaviorConstant(short id) {
    FlushCacheItem(id, m_behaviorConstants);
}
