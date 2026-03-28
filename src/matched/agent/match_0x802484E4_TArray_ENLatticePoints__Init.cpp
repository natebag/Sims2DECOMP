// TArray<ENLatticePoints, TArrayDefaultAllocator>::Init(void)
// Address: 0x802484E4 | Size: 40 bytes

extern char gDefaultAllocator_ENLatticePoints[];

extern void TArray_Init_impl(void* self, void* allocator);

void TArray_ENLatticePoints_Init(void* self) {
    TArray_Init_impl(self, gDefaultAllocator_ENLatticePoints);
}
