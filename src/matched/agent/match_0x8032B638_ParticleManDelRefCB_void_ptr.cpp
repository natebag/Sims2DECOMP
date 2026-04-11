/* ParticleManDelRefCB_void_ptr at 0x8032B638 (48B) — auto-matched [op_new_48B] */

// FLAGS: -fno-elide-constructors
extern int gHeap_8032B638[];
void *Heap_Alloc_8032B638(void *, int, int);

void *op_new_8032B638(int size) {
    return Heap_Alloc_8032B638(gHeap_8032B638, size, 1);
}
