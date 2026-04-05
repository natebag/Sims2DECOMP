/* EIWallPart__op_delete at 0x800297BC (52B) */

extern void *getDelHeap_800297BC(void);
extern void heapDel_800297BC(void *, void *);

void EIWallPart__op_delete(void *ptr) {
    void *heap = getDelHeap_800297BC();
    heapDel_800297BC(heap, ptr);
}
