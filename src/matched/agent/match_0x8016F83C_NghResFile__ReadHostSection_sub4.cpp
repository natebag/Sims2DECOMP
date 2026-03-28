struct MemoryCardCache;

int MemCardCacheFunc4(MemoryCardCache *);

struct NghResFile {
    char pad_00[0x140];
    MemoryCardCache* m_cache;

    int ReadHostSub4();
};

int NghResFile::ReadHostSub4() {
    return MemCardCacheFunc4(m_cache);
}
