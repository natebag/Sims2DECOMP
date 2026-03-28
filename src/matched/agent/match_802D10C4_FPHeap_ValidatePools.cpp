struct FPHeapObj_VP;
static FPHeapObj_VP* s_fpheap_vp;

void FPHeapValidate(FPHeapObj_VP*);

void FPHeap_ValidatePools(void) {
    FPHeapValidate(s_fpheap_vp);
}
