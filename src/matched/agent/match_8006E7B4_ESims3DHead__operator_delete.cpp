void* MainHeap();
void EAHeap_Free(void*, void*);

void ESims3DHead_operator_delete(void* ptr) {
    void* heap = MainHeap();
    EAHeap_Free(heap, ptr);
}
