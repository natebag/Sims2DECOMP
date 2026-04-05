/* ERTQuantize__DefaultFree at 0x802CEA44 (52B) */

extern void *getDelHeap_802CEA44(void);
extern void heapDel_802CEA44(void *, void *);

void ERTQuantize__DefaultFree(void *ptr) {
    void *heap = getDelHeap_802CEA44();
    heapDel_802CEA44(heap, ptr);
}
