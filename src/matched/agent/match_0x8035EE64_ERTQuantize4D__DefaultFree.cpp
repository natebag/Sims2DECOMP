/* ERTQuantize4D__DefaultFree at 0x8035EE64 (52B) */

extern void *getDelHeap_8035EE64(void);
extern void heapDel_8035EE64(void *, void *);

void ERTQuantize4D__DefaultFree(void *ptr) {
    void *heap = getDelHeap_8035EE64();
    heapDel_8035EE64(heap, ptr);
}
