/* PushFreeReadBuffer_void_ptr at 0x8033748C (48B) — auto-matched [op_new_48B] */

// FLAGS: -fno-elide-constructors
extern int gHeap_8033748C[];
void *Heap_Alloc_8033748C(void *, int, int);

void *op_new_8033748C(int size) {
    return Heap_Alloc_8033748C(gHeap_8033748C, size, 1);
}
