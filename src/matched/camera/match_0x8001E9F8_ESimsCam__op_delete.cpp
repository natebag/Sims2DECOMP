/* ESimsCam::operator delete(void *) at 0x8001E9F8 (52B) */

extern void *getDelHeap(void);
extern void heapDel(void *, void *);

void ESimsCam_op_delete(void *ptr) {
    void *heap = getDelHeap();
    heapDel(heap, ptr);
}
