/* ShaderHeapFreeMemory(...) at 0x803278F4 (40B) */

extern char g_shaderHeap[];
extern void shaderFreeInner(void *, unsigned int, char *, void *);

void ShaderHeapFreeMemory(void *alloc, unsigned int a, unsigned int b, void *ptr) {
    shaderFreeInner(alloc, a, g_shaderHeap, ptr);
}
