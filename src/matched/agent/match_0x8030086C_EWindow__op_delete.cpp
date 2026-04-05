/* EWindow__op_delete at 0x8030086C (52B) */

extern void *getDelHeap_8030086C(void);
extern void heapDel_8030086C(void *, void *);

void EWindow__op_delete(void *ptr) {
    void *heap = getDelHeap_8030086C();
    heapDel_8030086C(heap, ptr);
}
