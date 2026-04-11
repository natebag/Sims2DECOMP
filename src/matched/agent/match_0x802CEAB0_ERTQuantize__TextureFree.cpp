/* ERTQuantize__TextureFree at 0x802CEAB0 (52B) */

extern void *getDelHeap_802CEAB0(void);
extern void heapDel_802CEAB0(void *, void *);

void ERTQuantize__TextureFree(void *ptr) {
    void *heap = getDelHeap_802CEAB0();
    heapDel_802CEAB0(heap, ptr);
}
