/* cGZSnd__op_delete at 0x800BB2B4 (52B) */

extern void *getDelHeap_800BB2B4(void);
extern void heapDel_800BB2B4(void *, void *);

void cGZSnd__op_delete(void *ptr) {
    void *heap = getDelHeap_800BB2B4();
    heapDel_800BB2B4(heap, ptr);
}
