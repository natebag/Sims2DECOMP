/* CareersImpl__op_delete at 0x800B1C10 (52B) */

extern void *getDelHeap_800B1C10(void);
extern void heapDel_800B1C10(void *, void *);

void CareersImpl__op_delete(void *ptr) {
    void *heap = getDelHeap_800B1C10();
    heapDel_800B1C10(heap, ptr);
}
