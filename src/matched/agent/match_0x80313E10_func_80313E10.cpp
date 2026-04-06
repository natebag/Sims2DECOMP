/* auto at 0x80313E10 (44B) [op_delete_44B] */

// FLAGS: -fno-elide-constructors
extern int g_heap_80313E10[];
extern void heapFree_80313E10(void *, void *);

void op_delete_80313E10(void *ptr) {
    heapFree_80313E10(g_heap_80313E10, ptr);
}
