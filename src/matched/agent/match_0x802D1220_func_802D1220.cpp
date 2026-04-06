/* auto at 0x802D1220 (52B) [op_delete_52B] */

extern void *getDelHeap_802D1220(void);
extern void heapDel_802D1220(void *, void *);

void op_delete_802D1220(void *ptr) {
    void *heap = getDelHeap_802D1220();
    heapDel_802D1220(heap, ptr);
}
