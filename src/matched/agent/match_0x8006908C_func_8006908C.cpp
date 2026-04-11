/* auto at 0x8006908C (52B) [op_delete_52B] */

extern void *getDelHeap_8006908C(void);
extern void heapDel_8006908C(void *, void *);

void op_delete_8006908C(void *ptr) {
    void *heap = getDelHeap_8006908C();
    heapDel_8006908C(heap, ptr);
}
