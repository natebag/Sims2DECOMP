struct MemoryCardCache;

int MemCardCacheFunc1(MemoryCardCache *);

struct NghResFile {
    char pad_00[0x140];
    MemoryCardCache* m_cache;

    int ReadHostSub1();
};

int NghResFile::ReadHostSub1() {
    return MemCardCacheFunc1(m_cache);
}
