void* GetHeapBase();
void* HeapAllocAligned(void* heap, int size, int align);

void* _allocateMemory(int size) {
    void* heap = GetHeapBase();
    return HeapAllocAligned(heap, size, 0);
}
