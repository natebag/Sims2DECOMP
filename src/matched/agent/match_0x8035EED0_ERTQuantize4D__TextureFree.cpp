/* ERTQuantize4D__TextureFree at 0x8035EED0 (52B) */

extern void *getDelHeap_8035EED0(void);
extern void heapDel_8035EED0(void *, void *);

void ERTQuantize4D__TextureFree(void *ptr) {
    void *heap = getDelHeap_8035EED0();
    heapDel_8035EED0(heap, ptr);
}
