/* MemoryCardCache::LoadCacheFromMemoryCard(int) - 36 bytes */

struct NghResFile { int m_data; };

static NghResFile *s_nghResFile;

struct MemoryCardCache {
    int LoadCacheFromMemoryCard(int cardSlot);
    int LoadCacheFromMemoryCard(int cardSlot, NghResFile *nghFile);
};

int MemoryCardCache::LoadCacheFromMemoryCard(int cardSlot) {
    return LoadCacheFromMemoryCard(cardSlot, s_nghResFile);
}
