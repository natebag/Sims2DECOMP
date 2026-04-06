// FLAGS: -fno-elide-constructors
// 0x802C4FAC (48 bytes)
// AptXmlAttributes::operator delete(void *, unsigned int)

extern "C" void PoolFree(void* pool, void* ptr, unsigned int size);
extern void* g_aptPool;

void AptXmlAttributes_op_delete(void* ptr, unsigned int size) {
    PoolFree(g_aptPool, ptr, size);
}
