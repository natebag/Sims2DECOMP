void* GetHeapBase();
void HeapFreeFunc(void* heap, void* ptr);

void _freeMemory(void* ptr) {
    void* heap = GetHeapBase();
    HeapFreeFunc(heap, ptr);
}
