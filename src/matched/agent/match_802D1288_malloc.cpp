void* FindDefaultHeapM(unsigned int);
void* HeapMallocM(void*, unsigned int, int);

void* malloc_fn(unsigned int size) {
    void* heap = FindDefaultHeapM(size);
    return HeapMallocM(heap, size, 0);
}
