/* PrepareReady_bool at 0x803366BC (48B) — auto-matched [op_new_48B] */

// FLAGS: -fno-elide-constructors
extern int gHeap_803366BC[];
void *Heap_Alloc_803366BC(void *, int, int);

void *op_new_803366BC(int size) {
    return Heap_Alloc_803366BC(gHeap_803366BC, size, 1);
}
