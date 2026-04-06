/* auto at 0x80203E38 (52B) [op_delete_52B] */

extern void *getDelHeap_80203E38(void);
extern void heapDel_80203E38(void *, void *);

void op_delete_80203E38(void *ptr) {
    void *heap = getDelHeap_80203E38();
    heapDel_80203E38(heap, ptr);
}
