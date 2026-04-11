/* ERTQuantize4D__op_delete at 0x8036041C (52B) */

extern void *getDelHeap_8036041C(void);
extern void heapDel_8036041C(void *, void *);

void ERTQuantize4D__op_delete(void *ptr) {
    void *heap = getDelHeap_8036041C();
    heapDel_8036041C(heap, ptr);
}
