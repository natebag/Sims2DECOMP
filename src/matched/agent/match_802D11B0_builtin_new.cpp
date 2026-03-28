void* FindDefaultHeap(unsigned int);
void* HeapMalloc(void*, unsigned int, int);

void* __builtin_new_fn(unsigned int size) {
    void* heap = FindDefaultHeap(size);
    return HeapMalloc(heap, size, 0);
}
