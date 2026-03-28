struct MemoryCardCache;

int MemCardCacheFunc2(MemoryCardCache *);

struct NghResFile {
    char pad_00[0x140];
    MemoryCardCache* m_cache;

    int ReadHostSub2();
};

int NghResFile::ReadHostSub2() {
    return MemCardCacheFunc2(m_cache);
}
