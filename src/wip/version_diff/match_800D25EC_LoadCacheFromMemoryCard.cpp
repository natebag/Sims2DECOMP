/* LoadCacheFromMemoryCard(int) - 64 bytes */

struct MemoryCardCache {
    int LoadCacheFromMemoryCard(int cardSlot);
};

struct NghResFile {
    MemoryCardCache *GetMemoryCardCache(void);
};

static NghResFile *s_nghResFile;

int LoadCacheFromMemoryCard(int cardSlot) {
    MemoryCardCache *cache = s_nghResFile->GetMemoryCardCache();
    return cache->LoadCacheFromMemoryCard(cardSlot) == 0;
}
