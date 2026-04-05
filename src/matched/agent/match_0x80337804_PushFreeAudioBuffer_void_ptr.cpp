/* PushFreeAudioBuffer_void_ptr at 0x80337804 (48B) — auto-matched [op_new_48B] */

// FLAGS: -fno-elide-constructors
extern int gHeap_80337804[];
void *Heap_Alloc_80337804(void *, int, int);

void *op_new_80337804(int size) {
    return Heap_Alloc_80337804(gHeap_80337804, size, 0);
}
