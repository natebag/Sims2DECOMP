/* EGameState__op_delete at 0x80089DDC (52B) */

extern void *getDelHeap_80089DDC(void);
extern void heapDel_80089DDC(void *, void *);

void EGameState__op_delete(void *ptr) {
    void *heap = getDelHeap_80089DDC();
    heapDel_80089DDC(heap, ptr);
}
