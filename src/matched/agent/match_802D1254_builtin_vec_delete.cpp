void* FindHeapForPtr2(void*);
void FreeFromHeap2(void*, void*);

void __builtin_vec_delete_fn(void* ptr) {
    void* heap = FindHeapForPtr2(ptr);
    FreeFromHeap2(heap, ptr);
}
