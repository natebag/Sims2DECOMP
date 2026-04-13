// 0x800D2FBC MemoryCardCache::LoadCacheFromMemoryCard(int) (36B)
extern int gMemCardInstance;
void MemoryCardCache_LoadCacheFromMemoryCard2(void* self, int port, void* instance);
struct MemoryCardCache {
    void LoadCacheFromMemoryCard(int port);
};
void MemoryCardCache::LoadCacheFromMemoryCard(int port) {
    MemoryCardCache_LoadCacheFromMemoryCard2(this, port, (void*)gMemCardInstance);
}
