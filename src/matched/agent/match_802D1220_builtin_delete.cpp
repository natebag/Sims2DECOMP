void* FindHeapForPtr(void*);
void FreeFromHeap(void*, void*);

void __builtin_delete_fn(void* ptr) {
    void* heap = FindHeapForPtr(ptr);
    FreeFromHeap(heap, ptr);
}
