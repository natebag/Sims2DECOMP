// FLAGS: -fno-elide-constructors
extern int gHeap[];
void *Heap_Alloc(void *, int, int);

void *ERLevel_op_new(int size) {
    return Heap_Alloc(gHeap, size, 16);
}
