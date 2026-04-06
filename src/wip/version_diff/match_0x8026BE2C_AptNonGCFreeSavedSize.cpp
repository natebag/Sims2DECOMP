// FLAGS: -fno-elide-constructors
struct DOGMA_PoolManager;
extern DOGMA_PoolManager* gAptAllocator;
extern "C" void DOGMA_Free(DOGMA_PoolManager*, void* ptr, unsigned int size);

void AptNonGCFreeSavedSize(void* ptr) {
    unsigned int savedSize = *((unsigned int*)ptr - 1);
    void* realPtr = (char*)ptr - 4;
    DOGMA_Free(gAptAllocator, realPtr, savedSize + 4);
}
