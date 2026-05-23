struct MemoryCardCache;

int MemCardCacheFunc3(MemoryCardCache *);

struct NghResFile {
    char pad_00[0x140];
    MemoryCardCache* m_cache;

    int ReadHostSub3();
};

int NghResFile::ReadHostSub3() {
    return MemCardCacheFunc3(m_cache);
}
