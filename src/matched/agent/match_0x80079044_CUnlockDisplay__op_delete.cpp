/* CUnlockDisplay__op_delete at 0x80079044 (52B) */

extern void *getDelHeap_80079044(void);
extern void heapDel_80079044(void *, void *);

void CUnlockDisplay__op_delete(void *ptr) {
    void *heap = getDelHeap_80079044();
    heapDel_80079044(heap, ptr);
}
