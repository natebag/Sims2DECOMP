// 0x8003540C _Default2dArrayFree (52b)

extern void *getDelHeap_8003540C(void);
extern void heapDel_8003540C(void *, void *);

void Default2dArrayFree(void *ptr) {
    void *heap = getDelHeap_8003540C();
    heapDel_8003540C(heap, ptr);
}
