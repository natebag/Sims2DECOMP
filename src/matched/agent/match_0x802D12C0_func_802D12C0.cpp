/* auto at 0x802D12C0 (52B) [op_delete_52B] */

extern void *getDelHeap_802D12C0(void);
extern void heapDel_802D12C0(void *, void *);

void op_delete_802D12C0(void *ptr) {
    void *heap = getDelHeap_802D12C0();
    heapDel_802D12C0(heap, ptr);
}
