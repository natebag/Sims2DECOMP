void* FindDefaultHeap2(unsigned int);
void* HeapMalloc2(void*, unsigned int, int);

void* __builtin_vec_new_fn(unsigned int size) {
    void* heap = FindDefaultHeap2(size);
    return HeapMalloc2(heap, size, 0);
}
