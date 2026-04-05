/* PushReadedBuffer2_void_ptr at 0x803374F0 (48B) — auto-matched [op_new_48B] */

// FLAGS: -fno-elide-constructors
extern int gHeap_803374F0[];
void *Heap_Alloc_803374F0(void *, int, int);

void *op_new_803374F0(int size) {
    return Heap_Alloc_803374F0(gHeap_803374F0, size, 1);
}
