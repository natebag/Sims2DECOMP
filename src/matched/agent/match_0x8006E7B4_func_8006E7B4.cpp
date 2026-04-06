/* auto at 0x8006E7B4 (52B) [op_delete_52B] */

extern void *getDelHeap_8006E7B4(void);
extern void heapDel_8006E7B4(void *, void *);

void op_delete_8006E7B4(void *ptr) {
    void *heap = getDelHeap_8006E7B4();
    heapDel_8006E7B4(heap, ptr);
}
