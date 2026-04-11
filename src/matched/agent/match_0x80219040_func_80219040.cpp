/* auto at 0x80219040 (52B) [op_delete_52B] */

extern void *getDelHeap_80219040(void);
extern void heapDel_80219040(void *, void *);

void op_delete_80219040(void *ptr) {
    void *heap = getDelHeap_80219040();
    heapDel_80219040(heap, ptr);
}
