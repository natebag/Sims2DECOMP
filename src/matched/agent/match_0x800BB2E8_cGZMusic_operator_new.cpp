// FLAGS: -msdata=eabi -G 8
// 0x800BB2E8 cGZMusic::operator new (60b)
extern void* MainHeap();
extern void* EAHeap_Calloc(void*, unsigned int, unsigned int, int);

void* cGZMusic_opnew(unsigned int size) {
    void* heap = MainHeap();
    return EAHeap_Calloc(heap, size, 1, 0);
}
