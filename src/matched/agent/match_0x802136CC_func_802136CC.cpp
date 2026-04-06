/* auto at 0x802136CC (52B) [op_delete_52B] */

extern void *getDelHeap_802136CC(void);
extern void heapDel_802136CC(void *, void *);

void op_delete_802136CC(void *ptr) {
    void *heap = getDelHeap_802136CC();
    heapDel_802136CC(heap, ptr);
}
