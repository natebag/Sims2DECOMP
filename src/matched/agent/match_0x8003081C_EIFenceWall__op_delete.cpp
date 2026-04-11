/* EIFenceWall__op_delete at 0x8003081C (52B) */

extern void *getDelHeap_8003081C(void);
extern void heapDel_8003081C(void *, void *);

void EIFenceWall__op_delete(void *ptr) {
    void *heap = getDelHeap_8003081C();
    heapDel_8003081C(heap, ptr);
}
