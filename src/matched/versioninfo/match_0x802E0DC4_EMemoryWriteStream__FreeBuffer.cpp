/* EMemoryWriteStream__FreeBuffer at 0x802E0DC4 (52B) */

extern void *getDelHeap_802E0DC4(void);
extern void heapDel_802E0DC4(void *, void *);

void EMemoryWriteStream__FreeBuffer(void *ptr) {
    void *heap = getDelHeap_802E0DC4();
    heapDel_802E0DC4(heap, ptr);
}
