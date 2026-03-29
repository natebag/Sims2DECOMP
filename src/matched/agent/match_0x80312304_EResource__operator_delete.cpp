extern void* MainHeap_void();
struct EAHeap {
    void Free(void*);
};
struct EResource {
    void operator delete(void* p);
};
void EResource::operator delete(void* p) {
    EAHeap* heap = (EAHeap*)MainHeap_void();
    heap->Free(p);
}
