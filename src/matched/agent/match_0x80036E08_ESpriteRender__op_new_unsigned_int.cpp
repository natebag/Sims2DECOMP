/* ESpriteRender__op_new_unsigned_int at 0x80036E08 (52B) — auto-matched [op_new_52B] */

extern void *getNewHeap_80036E08(void);
extern void *heapAlloc_80036E08(void *, int, int, int, int);

void *op_new_80036E08(unsigned int) {
    void *heap = getNewHeap_80036E08();
    return heapAlloc_80036E08(heap, 236, 16, 0, 0);
}
