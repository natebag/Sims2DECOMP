/* ShaderHeapFreeMemory(...) at 0x803278F4 (40B) */
// FLAGS: -fno-elide-constructors

extern char g_shaderHeap[256];
extern void shaderFreeInner(void *, void *, unsigned int, unsigned int, char *);

void ShaderHeapFreeMemory(void *alloc, unsigned int a, unsigned int b, void *ptr) {
    shaderFreeInner(alloc, a, b, ptr, g_shaderHeap);
}
