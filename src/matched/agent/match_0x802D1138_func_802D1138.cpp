/* auto at 0x802D1138 (52B) [op_delete_52B] */

extern void *getDelHeap_802D1138(void);
extern void heapDel_802D1138(void *, void *);

void op_delete_802D1138(void *ptr) {
    void *heap = getDelHeap_802D1138();
    heapDel_802D1138(heap, ptr);
}
