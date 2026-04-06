/* auto at 0x80203E04 (52B) [op_delete_52B] */

extern void *getDelHeap_80203E04(void);
extern void heapDel_80203E04(void *, void *);

void op_delete_80203E04(void *ptr) {
    void *heap = getDelHeap_80203E04();
    heapDel_80203E04(heap, ptr);
}
