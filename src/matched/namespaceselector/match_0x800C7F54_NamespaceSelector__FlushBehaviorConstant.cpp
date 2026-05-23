// 0x800C7F54 NamespaceSelector::FlushBehaviorConstant(short) (36B)
void FlushCacheItem(void* self, short key, void* list);
struct NamespaceSelector {
    char pad[0x10];
    char m_behavList[1];
    void FlushBehaviorConstant(short key);
};
void NamespaceSelector::FlushBehaviorConstant(short key) {
    FlushCacheItem(this, key, m_behavList);
}
