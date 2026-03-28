extern void* g_aptAllocator;
extern void* AptAllocator_alloc(void* allocator, unsigned int size);
void* AptCharAnimInst_opnew(unsigned int size) {
    return AptAllocator_alloc(g_aptAllocator, size);
}
