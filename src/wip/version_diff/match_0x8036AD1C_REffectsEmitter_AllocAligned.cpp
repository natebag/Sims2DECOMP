// FLAGS: -fno-elide-constructors
// 0x8036AD1C (48 bytes)
// REffectsEmitter::AllocAligned(unsigned long, unsigned long)

extern "C" void* EAHeap_Alloc(void* pool, unsigned int size, unsigned int alignment);
extern char g_effectsPool[];

void* REffectsEmitter_AllocAligned(unsigned int size, unsigned int alignment) {
    return EAHeap_Alloc(g_effectsPool, size, alignment);
}
