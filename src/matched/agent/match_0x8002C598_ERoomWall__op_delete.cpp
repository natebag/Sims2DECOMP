/* ERoomWall__op_delete at 0x8002C598 (52B) */

extern void *getDelHeap_8002C598(void);
extern void heapDel_8002C598(void *, void *);

void ERoomWall__op_delete(void *ptr) {
    void *heap = getDelHeap_8002C598();
    heapDel_8002C598(heap, ptr);
}
