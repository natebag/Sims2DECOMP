// 0x800C800C NamespaceSelector::FlushStringSet(short) (36B)
void FlushCacheItem(void* self, short key, void* list);
struct NamespaceSelector {
    char pad[0x08];
    char m_strList[1];
    void FlushStringSet(short key);
};
void NamespaceSelector::FlushStringSet(short key) {
    FlushCacheItem(this, key, m_strList);
}
