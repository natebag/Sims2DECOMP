void* GetAptHeap();
void* AptHeapMalloc(void* heap, int size, int align);

void* SimsAptMalloc(int size) {
    void* heap = GetAptHeap();
    return AptHeapMalloc(heap, size, 0);
}
