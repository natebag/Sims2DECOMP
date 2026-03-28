struct HeapObj_VP;
static HeapObj_VP* s_heap_vp;

void HeapValidate(HeapObj_VP*);

void EAHeap_ValidatePools(void) {
    HeapValidate(s_heap_vp);
}
