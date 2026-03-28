typedef unsigned char u8;

void* MainHeap();
void* EAHeap_MallocAligned(void*, unsigned int, unsigned int, unsigned int, int);
void memset_func(void*, int, unsigned int);

void* SAnimator2_operator_new(unsigned int size) {
    void* heap = MainHeap();
    void* ptr = EAHeap_MallocAligned(heap, size, 16, 0, 0);
    memset_func(ptr, 0, size);
    return ptr;
}
