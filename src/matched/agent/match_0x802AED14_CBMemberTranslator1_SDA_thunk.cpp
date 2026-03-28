
extern void* g_aptAllocator;

void* AptAllocate(void* allocator, unsigned int size);

void* AptString_operator_new(unsigned int size) {
    return AptAllocate(g_aptAllocator, size);
}
