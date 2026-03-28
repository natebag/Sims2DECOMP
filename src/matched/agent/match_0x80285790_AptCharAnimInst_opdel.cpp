extern void* g_aptAllocator2;
extern void AptAllocator_free(void* allocator, void* ptr, unsigned int size);
void AptCharAnimInst_opdel(void* ptr, unsigned int size) {
    AptAllocator_free(g_aptAllocator2, ptr, size);
}
