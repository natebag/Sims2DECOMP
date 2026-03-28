struct AptHeap {
    void *m_firstFree;
};

AptHeap* GetAptHeap();
void AptHeapFree(AptHeap*, void*);

void SimsAptFree(void *ptr) {
    if (ptr) {
        AptHeap *heap = GetAptHeap();
        if (heap->m_firstFree != 0) {
            heap = GetAptHeap();
            AptHeapFree(heap, ptr);
        }
    }
}
