/* FastParticleEmitter__op_delete at 0x80356620 (52B) */

extern void *getDelHeap_80356620(void);
extern void heapDel_80356620(void *, void *);

void FastParticleEmitter__op_delete(void *ptr) {
    void *heap = getDelHeap_80356620();
    heapDel_80356620(heap, ptr);
}
