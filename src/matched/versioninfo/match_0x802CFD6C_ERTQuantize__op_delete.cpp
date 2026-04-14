/* ERTQuantize__op_delete at 0x802CFD6C (52B) */

extern void *getDelHeap_802CFD6C(void);
extern void heapDel_802CFD6C(void *, void *);

void ERTQuantize__op_delete(void *ptr) {
    void *heap = getDelHeap_802CFD6C();
    heapDel_802CFD6C(heap, ptr);
}
