typedef unsigned char u8;

void* MainHeap();
void EAHeap_Free(void*, void*);

void SAnimator2_operator_delete(void* ptr) {
    void* heap = MainHeap();
    EAHeap_Free(heap, ptr);
}
