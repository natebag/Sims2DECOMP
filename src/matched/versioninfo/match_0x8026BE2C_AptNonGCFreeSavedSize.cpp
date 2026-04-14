// 0x8026BE2C AptNonGCFreeSavedSize (48B)
// FLAGS: -fno-elide-constructors
struct DOGMA_PoolManager;
extern DOGMA_PoolManager* gAptAllocator;
extern "C" void DOGMA_Free(DOGMA_PoolManager*, void* ptr, unsigned int size);

void AptNonGCFreeSavedSize(void* ptr) {
    unsigned int* p = (unsigned int*)ptr;
    p--;
    unsigned int savedSize = *p;
    DOGMA_Free(gAptAllocator, (void*)p, savedSize + 4);
}
