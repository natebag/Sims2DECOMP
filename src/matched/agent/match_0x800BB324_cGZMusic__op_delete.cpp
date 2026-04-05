/* cGZMusic__op_delete at 0x800BB324 (52B) */

extern void *getDelHeap_800BB324(void);
extern void heapDel_800BB324(void *, void *);

void cGZMusic__op_delete(void *ptr) {
    void *heap = getDelHeap_800BB324();
    heapDel_800BB324(heap, ptr);
}
