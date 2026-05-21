// 0x80119470 cSoundCache::cSoundCache(void) (64B)
// Zeros 256 bytes (64 void* entries) via memset, then clears trailing field at +256.

extern void* memset(void*, int, unsigned int);

struct cSoundCache_ctor {
    void* m_entries[64];   // 256 bytes
    int m_count;           // +256 = +0x100
    cSoundCache_ctor();
};

cSoundCache_ctor::cSoundCache_ctor() {
    memset(m_entries, 0, 256);
    m_count = 0;
}
