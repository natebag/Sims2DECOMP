extern void* g_aptFree_AptPseudoData2;
extern void AptFree_AptPseudoData2(void* allocator, void* ptr, unsigned int size);
void AptPseudoData2_opdel(void* ptr, unsigned int size) {
    AptFree_AptPseudoData2(g_aptFree_AptPseudoData2, ptr, size);
}
