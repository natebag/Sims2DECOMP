/* PerfFree at 0x8033B43C (52B) */

extern void *getDelHeap_8033B43C(void);
extern void heapDel_8033B43C(void *, void *);

void PerfFree(void *ptr) {
    void *heap = getDelHeap_8033B43C();
    heapDel_8033B43C(heap, ptr);
}
