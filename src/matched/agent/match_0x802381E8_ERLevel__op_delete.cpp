/* ERLevel::operator delete(void *) at 0x802381E8 (44B) */

extern char g_heap44del[256];
extern void heapFree44(void *, void *);

void ERLevel_op_delete(void *ptr) {
    heapFree44(g_heap44del, ptr);
}
