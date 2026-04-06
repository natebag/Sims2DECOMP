// 0x803279EC FlashesHeapFreeMemory (40b)

extern int g_flashesHeapName[4];
extern void HeapFreeImpl2(void*, unsigned int, void*, void*);

void FlashesHeapFreeMemory(void* alloc, unsigned int a, unsigned int b, void* ptr) {
    HeapFreeImpl2(alloc, a, (void*)g_flashesHeapName, ptr);
}
