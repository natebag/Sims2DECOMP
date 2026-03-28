typedef unsigned int uint;

struct EAHeap {
    void Free(void* ptr);
};

EAHeap* MainHeap();

struct ISimInstance {
    void operator delete(void* ptr);
};

void ISimInstance::operator delete(void* ptr) {
    EAHeap* heap = MainHeap();
    heap->Free(ptr);
}
