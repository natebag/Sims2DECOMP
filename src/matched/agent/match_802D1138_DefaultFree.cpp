void* FindHeapForPtrDF(void*);
void FreeFromHeapDF(void*, void*);

void DefaultFree_fn(void* ptr) {
    void* heap = FindHeapForPtrDF(ptr);
    FreeFromHeapDF(heap, ptr);
}
