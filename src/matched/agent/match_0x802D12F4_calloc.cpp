/* calloc at 0x802D12F4 (84B) */

extern void *getHeap2(void);
extern void *heapMalloc(void *, int, int);
extern void memset_fn(void *, int, int);

void *calloc(unsigned int count, unsigned int size) {
    unsigned int total = count * size;
    void *heap = getHeap2();
    void *ptr = heapMalloc(heap, total, 0);
    if (ptr != 0) {
        memset_fn(ptr, 0, total);
    }
    return ptr;
}
