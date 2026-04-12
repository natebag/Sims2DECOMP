// FLAGS: -fno-elide-constructors -msdata=eabi -G 8
// 0x8026BE2C AptNonGCFreeSavedSize (48B)
struct DOGMA_PoolManager;
extern DOGMA_PoolManager* gAptAllocator;
extern "C" void DOGMA_Free(DOGMA_PoolManager*, void* ptr, unsigned int size);

void AptNonGCFreeSavedSize(void* ptr) {
    unsigned int* p = (unsigned int*)ptr - 1;
    unsigned int savedSize = *p;
    DOGMA_Free(gAptAllocator, p, savedSize + 4);
}
