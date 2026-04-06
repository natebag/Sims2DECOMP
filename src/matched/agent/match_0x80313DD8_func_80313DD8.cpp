/* auto at 0x80313DD8 (48B) [op_new_48B] */

// FLAGS: -fno-elide-constructors
extern int gHeap_80313DD8[];
void *Heap_Alloc_80313DD8(void *, int, int);

void *op_new_80313DD8(int size) {
    return Heap_Alloc_80313DD8(gHeap_80313DD8, size, 8);
}
