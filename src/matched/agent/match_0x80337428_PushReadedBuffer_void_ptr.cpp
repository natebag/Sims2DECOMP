/* PushReadedBuffer_void_ptr at 0x80337428 (48B) — auto-matched [op_new_48B] */

// FLAGS: -fno-elide-constructors
extern int gHeap_80337428[];
void *Heap_Alloc_80337428(void *, int, int);

void *op_new_80337428(int size) {
    return Heap_Alloc_80337428(gHeap_80337428, size, 1);
}
