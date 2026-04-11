/* ERMovie__op_delete at 0x8031B7C0 (52B) */

extern void *getDelHeap_8031B7C0(void);
extern void heapDel_8031B7C0(void *, void *);

void ERMovie__op_delete(void *ptr) {
    void *heap = getDelHeap_8031B7C0();
    heapDel_8031B7C0(heap, ptr);
}
