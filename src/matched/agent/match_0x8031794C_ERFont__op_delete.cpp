/* ERFont__op_delete at 0x8031794C (52B) */

extern void *getDelHeap_8031794C(void);
extern void heapDel_8031794C(void *, void *);

void ERFont__op_delete(void *ptr) {
    void *heap = getDelHeap_8031794C();
    heapDel_8031794C(heap, ptr);
}
