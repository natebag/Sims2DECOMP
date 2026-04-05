/* ESpriteRender__op_delete at 0x80036E3C (52B) */

extern void *getDelHeap_80036E3C(void);
extern void heapDel_80036E3C(void *, void *);

void ESpriteRender__op_delete(void *ptr) {
    void *heap = getDelHeap_80036E3C();
    heapDel_80036E3C(heap, ptr);
}
