/* ERAudioStream__op_delete at 0x803C631C (52B) */

extern void *getDelHeap_803C631C(void);
extern void heapDel_803C631C(void *, void *);

void ERAudioStream__op_delete(void *ptr) {
    void *heap = getDelHeap_803C631C();
    heapDel_803C631C(heap, ptr);
}
