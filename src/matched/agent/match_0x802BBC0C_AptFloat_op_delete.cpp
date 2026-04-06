// FLAGS: -fno-elide-constructors
// 0x802BBC0C (48 bytes)
// AptFloat::operator delete(void *, unsigned int)

extern "C" void PoolFree(void* pool, void* ptr, unsigned int size);
extern void* g_aptPool;

void AptFloat_op_delete(void* ptr, unsigned int size) {
    PoolFree(g_aptPool, ptr, size);
}
