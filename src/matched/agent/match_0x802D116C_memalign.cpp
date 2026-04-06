/* memalign at 0x802D116C (68B) */

extern void *getHeap(void);
extern void *heapAlloc(void *, int, int, int, int);

void *memalign(int alignment, int size) {
    void *heap = getHeap();
    return heapAlloc(heap, size, alignment, 0, 0);
}
