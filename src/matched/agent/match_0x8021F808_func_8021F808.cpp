/* auto at 0x8021F808 (52B) [op_delete_52B] */

extern void *getDelHeap_8021F808(void);
extern void heapDel_8021F808(void *, void *);

void op_delete_8021F808(void *ptr) {
    void *heap = getDelHeap_8021F808();
    heapDel_8021F808(heap, ptr);
}
