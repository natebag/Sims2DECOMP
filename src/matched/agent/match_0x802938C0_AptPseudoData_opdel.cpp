extern void* g_aptFree_AptPseudoData;
extern void AptFree_AptPseudoData(void* allocator, void* ptr, unsigned int size);
void AptPseudoData_opdel(void* ptr, unsigned int size) {
    AptFree_AptPseudoData(g_aptFree_AptPseudoData, ptr, size);
}
