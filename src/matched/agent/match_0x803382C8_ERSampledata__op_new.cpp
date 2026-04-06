// 0x803382C8 ERSampledata::operator new (44b)

extern char g_sampleHeap[4];
extern void* AllocFromHeap(void*, unsigned int, int);

void* ERSampledata_op_new(unsigned int size) {
    return AllocFromHeap(*(void**)g_sampleHeap, size, 8);
}
