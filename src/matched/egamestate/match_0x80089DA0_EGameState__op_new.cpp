// EGameState::operator new(unsigned int) - 0x80089DA0 (60B)
// Pool alloc via MainHeap()->Calloc(size, 1, 0).

extern void *getMainHeap_op_new(void);
extern void *heapCalloc_op_new(void *heap, unsigned int size, int a, int b);

void *op_new_EGameState(unsigned int size) {
    void *heap = getMainHeap_op_new();
    return heapCalloc_op_new(heap, size, 1, 0);
}
