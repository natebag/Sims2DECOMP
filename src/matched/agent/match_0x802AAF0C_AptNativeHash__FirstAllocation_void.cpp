// 0x802AAF0C (80B) AptNativeHash::FirstAllocation(void)
//
// Allocates the hash table's entry array from the DOGMA pool and zero-fills it.
// Each entry is 8 bytes, so the byte size is m_capacity * 8 (slwi by 3). The
// capacity is read a second time for the memset size because the intervening
// Allocate call is a memory clobber from the compiler's point of view, so the
// value cannot be reused. Clean structural C++; default scheduling fills the
// post-capacity-load gap with the pool-pointer load.

struct AptNativeHashEntry {
    void* m_key;     // 0x00
    void* m_value;   // 0x04
};

struct DOGMA_PoolManager {
    void* Allocate(unsigned int size);
};

struct AptNativeHash {
    int                 m_capacity;  // 0x00 (slot count)
    AptNativeHashEntry* m_entries;   // 0x04
    void FirstAllocation();
};

extern DOGMA_PoolManager* g_dogmaPool;          // SDA pool pointer
extern "C" void* memset(void* dst, int c, unsigned int n);

void AptNativeHash::FirstAllocation() {
    void* p = g_dogmaPool->Allocate(m_capacity * sizeof(AptNativeHashEntry));
    m_entries = (AptNativeHashEntry*)p;
    memset(p, 0, m_capacity * sizeof(AptNativeHashEntry));
}
