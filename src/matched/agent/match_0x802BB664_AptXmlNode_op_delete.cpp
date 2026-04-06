// FLAGS: -fno-elide-constructors
// 0x802BB664 (48 bytes)
// AptXmlNode::operator delete(void *, unsigned int)

extern "C" void PoolFree(void* pool, void* ptr, unsigned int size);
extern void* g_aptPool;

void AptXmlNode_op_delete(void* ptr, unsigned int size) {
    PoolFree(g_aptPool, ptr, size);
}
