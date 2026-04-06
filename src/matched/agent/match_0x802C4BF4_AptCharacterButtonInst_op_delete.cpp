// FLAGS: -fno-elide-constructors
// 0x802C4BF4 (48 bytes)
// AptCharacterButtonInst::operator delete(void *, unsigned int)

extern "C" void PoolFree(void* pool, void* ptr, unsigned int size);
extern void* g_aptPool;

void AptCharacterButtonInst_op_delete(void* ptr, unsigned int size) {
    PoolFree(g_aptPool, ptr, size);
}
