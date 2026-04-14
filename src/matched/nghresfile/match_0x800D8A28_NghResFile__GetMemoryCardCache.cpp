/* NghResFile::GetMemoryCardCache(void) - 0x800D8A28 (72 bytes) */

struct NghLayout;
extern NghLayout s_nghLayout;

struct MemoryCardCache {
    char _pad[0x10];
    void *m_data;

    void Init(NghLayout *);
};

struct NghResFile {
    char _pad[0x190];
    MemoryCardCache *m_cache;

    MemoryCardCache *GetMemoryCardCache(void);
};

MemoryCardCache *NghResFile::GetMemoryCardCache(void)
{
    if (m_cache->m_data == 0) {
        m_cache->Init(&s_nghLayout);
    }
    return m_cache;
}
