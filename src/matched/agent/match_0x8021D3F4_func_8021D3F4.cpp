/* auto at 0x8021D3F4 (52B) [op_delete_52B] */

extern void *getDelHeap_8021D3F4(void);
extern void heapDel_8021D3F4(void *, void *);

void op_delete_8021D3F4(void *ptr) {
    void *heap = getDelHeap_8021D3F4();
    heapDel_8021D3F4(heap, ptr);
}
