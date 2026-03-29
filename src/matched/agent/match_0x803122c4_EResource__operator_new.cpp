extern void* MainHeap_void();
struct EAHeap {
    void* Malloc(unsigned int, int);
};
struct EResource {
    void* operator new(unsigned int size);
};
void* EResource::operator new(unsigned int size) {
    EAHeap* heap = (EAHeap*)MainHeap_void();
    return heap->Malloc(size, 0);
}
