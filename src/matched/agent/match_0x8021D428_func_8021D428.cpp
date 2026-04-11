/* auto at 0x8021D428 (52B) [op_delete_52B] */

extern void *getDelHeap_8021D428(void);
extern void heapDel_8021D428(void *, void *);

void op_delete_8021D428(void *ptr) {
    void *heap = getDelHeap_8021D428();
    heapDel_8021D428(heap, ptr);
}
