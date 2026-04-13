/* SaveAllMemoryCardCache(int) - 64 bytes */

struct MemoryCardCache {
    int SaveAllToMemoryCard(int cardSlot);
};

struct NghResFile {
    MemoryCardCache *GetMemoryCardCache(void);
};

static NghResFile *s_nghResFile;

int SaveAllMemoryCardCache(int cardSlot) {
    MemoryCardCache *cache = s_nghResFile->GetMemoryCardCache();
    return cache->SaveAllToMemoryCard(cardSlot) == 0;
}
