/* PushDecodedTextureSet_void_ptr at 0x80337DD8 (48B) — auto-matched [op_new_48B] */

// FLAGS: -fno-elide-constructors
extern int gHeap_80337DD8[];
void *Heap_Alloc_80337DD8(void *, int, int);

void *op_new_80337DD8(int size) {
    return Heap_Alloc_80337DD8(gHeap_80337DD8, size, 1);
}
