/* EFile__op_delete at 0x802C68D0 (52B) */

extern void *getDelHeap_802C68D0(void);
extern void heapDel_802C68D0(void *, void *);

void EFile__op_delete(void *ptr) {
    void *heap = getDelHeap_802C68D0();
    heapDel_802C68D0(heap, ptr);
}
