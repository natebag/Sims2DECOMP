/* auto at 0x8021F1D4 (52B) [op_delete_52B] */

extern void *getDelHeap_8021F1D4(void);
extern void heapDel_8021F1D4(void *, void *);

void op_delete_8021F1D4(void *ptr) {
    void *heap = getDelHeap_8021F1D4();
    heapDel_8021F1D4(heap, ptr);
}
