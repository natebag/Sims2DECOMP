// 0x80327A14 AptHeapFreeMemory (40b)

extern int g_aptHeapName[4];
extern void HeapFreeImpl3(void*, unsigned int, void*, void*);

void AptHeapFreeMemory(void* alloc, unsigned int a, unsigned int b, void* ptr) {
    HeapFreeImpl3(alloc, a, (void*)g_aptHeapName, ptr);
}
