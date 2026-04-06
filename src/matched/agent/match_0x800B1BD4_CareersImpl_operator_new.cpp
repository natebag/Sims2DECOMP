// FLAGS: -msdata=eabi -G 8
// 0x800B1BD4 CareersImpl::operator_new (60b)
extern void* MainHeap();
extern void* EAHeap_Calloc(void* heap, unsigned int size, unsigned int count, int flag);

void* CareersImpl_operator_new(unsigned int size) {
    void* heap = MainHeap();
    return EAHeap_Calloc(heap, size, 1, 0);
}
