/* PushFreeTextureSet_void_ptr at 0x80337D68 (48B) — auto-matched [op_new_48B] */

// FLAGS: -fno-elide-constructors
extern int gHeap_80337D68[];
void *Heap_Alloc_80337D68(void *, int, int);

void *op_new_80337D68(int size) {
    return Heap_Alloc_80337D68(gHeap_80337D68, size, 0);
}
