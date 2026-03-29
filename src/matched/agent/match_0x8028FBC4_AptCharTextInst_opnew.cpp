extern void* g_aptAlloc_AptCharTextInst;
extern void* AptAlloc_AptCharTextInst(void* allocator, unsigned int size);
void* AptCharTextInst_opnew(unsigned int size) {
    return AptAlloc_AptCharTextInst(g_aptAlloc_AptCharTextInst, size);
}
