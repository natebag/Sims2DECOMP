extern void* g_aptFree_AptPseudoCIH;
extern void AptFree_AptPseudoCIH(void* allocator, void* ptr, unsigned int size);
void AptPseudoCIH_opdel(void* ptr, unsigned int size) {
    AptFree_AptPseudoCIH(g_aptFree_AptPseudoCIH, ptr, size);
}
