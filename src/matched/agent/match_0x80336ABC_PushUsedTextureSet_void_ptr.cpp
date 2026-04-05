/* PushUsedTextureSet_void_ptr at 0x80336ABC (48B) — auto-matched [op_new_48B] */

// FLAGS: -fno-elide-constructors
extern int gHeap_80336ABC[];
void *Heap_Alloc_80336ABC(void *, int, int);

void *op_new_80336ABC(int size) {
    return Heap_Alloc_80336ABC(gHeap_80336ABC, size, 0);
}
