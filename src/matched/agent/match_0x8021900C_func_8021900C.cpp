/* auto at 0x8021900C (52B) [op_delete_52B] */

extern void *getDelHeap_8021900C(void);
extern void heapDel_8021900C(void *, void *);

void op_delete_8021900C(void *ptr) {
    void *heap = getDelHeap_8021900C();
    heapDel_8021900C(heap, ptr);
}
