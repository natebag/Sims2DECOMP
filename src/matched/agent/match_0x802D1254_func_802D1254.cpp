/* auto at 0x802D1254 (52B) [op_delete_52B] */

extern void *getDelHeap_802D1254(void);
extern void heapDel_802D1254(void *, void *);

void op_delete_802D1254(void *ptr) {
    void *heap = getDelHeap_802D1254();
    heapDel_802D1254(heap, ptr);
}
