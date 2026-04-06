// 0x80327970 AnimationHeapFreeMemory (40b)

extern int g_animHeapName[4];
extern void HeapFreeImpl(void*, unsigned int, void*, void*);

void AnimationHeapFreeMemory(void* alloc, unsigned int a, unsigned int b, void* ptr) {
    HeapFreeImpl(alloc, a, (void*)g_animHeapName, ptr);
}
