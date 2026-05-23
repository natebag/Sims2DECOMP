// PRAGMA_STUB: EIStaticModel::operator delete(void *)
/* EIStaticModel__op_delete at 0x8022E174 (52B) */

extern void *getDelHeap_8022E174(void);
extern void heapDel_8022E174(void *, void *);

void EIStaticModel__op_delete(void *ptr) {
    void *heap = getDelHeap_8022E174();
    heapDel_8022E174(heap, ptr);
}
