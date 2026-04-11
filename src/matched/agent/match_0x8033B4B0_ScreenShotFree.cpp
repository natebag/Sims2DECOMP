/* ScreenShotFree at 0x8033B4B0 (52B) */

extern void *getDelHeap_8033B4B0(void);
extern void heapDel_8033B4B0(void *, void *);

void ScreenShotFree(void *ptr) {
    void *heap = getDelHeap_8033B4B0();
    heapDel_8033B4B0(heap, ptr);
}
