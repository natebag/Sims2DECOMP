// FLAGS: -msdata=eabi -G 8
// 0x800BB278 cGZSnd::operator new (60b)
extern void* MainHeap();
extern void* EAHeap_Calloc(void*, unsigned int, unsigned int, int);

void* cGZSnd_opnew(unsigned int size) {
    void* heap = MainHeap();
    return EAHeap_Calloc(heap, size, 1, 0);
}
