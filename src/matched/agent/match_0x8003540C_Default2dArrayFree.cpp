/* Default2dArrayFree at 0x8003540C (52B) */

extern void *getDelHeap_8003540C(void);
extern void heapDel_8003540C(void *, void *);

void Default2dArrayFree(void *ptr) {
    void *heap = getDelHeap_8003540C();
    heapDel_8003540C(heap, ptr);
}
