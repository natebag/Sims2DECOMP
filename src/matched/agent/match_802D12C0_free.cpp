void* FindHeapForPtrFree(void*);
void FreeFromHeapFree(void*, void*);

void free_fn(void* ptr) {
    void* heap = FindHeapForPtrFree(ptr);
    FreeFromHeapFree(heap, ptr);
}
