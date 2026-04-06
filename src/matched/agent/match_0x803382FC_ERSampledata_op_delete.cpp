// FLAGS: -fno-elide-constructors
// 0x803382FC (40 bytes)
// ERSampledata::operator delete(void *)

extern "C" void PoolFree2(void* pool, void* ptr);
extern void* g_samplePool;

void ERSampledata_op_delete(void* ptr) {
    PoolFree2(g_samplePool, ptr);
}
