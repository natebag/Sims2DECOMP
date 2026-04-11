/* PushDecodedAudioBuffer_void_ptr at 0x80337874 (48B) — auto-matched [op_new_48B] */

// FLAGS: -fno-elide-constructors
extern int gHeap_80337874[];
void *Heap_Alloc_80337874(void *, int, int);

void *op_new_80337874(int size) {
    return Heap_Alloc_80337874(gHeap_80337874, size, 1);
}
