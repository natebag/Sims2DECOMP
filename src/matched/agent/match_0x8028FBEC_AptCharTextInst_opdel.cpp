extern void* g_aptFree_AptCharTextInst;
extern void AptFree_AptCharTextInst(void* allocator, void* ptr, unsigned int size);
void AptCharTextInst_opdel(void* ptr, unsigned int size) {
    AptFree_AptCharTextInst(g_aptFree_AptCharTextInst, ptr, size);
}
