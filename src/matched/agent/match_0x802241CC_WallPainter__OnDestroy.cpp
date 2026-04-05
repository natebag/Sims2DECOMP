/* WallPainter__OnDestroy at 0x802241CC (52B) */

extern void *getDelHeap_802241CC(void);
extern void heapDel_802241CC(void *, void *);

void WallPainter__OnDestroy(void *ptr) {
    void *heap = getDelHeap_802241CC();
    heapDel_802241CC(heap, ptr);
}
