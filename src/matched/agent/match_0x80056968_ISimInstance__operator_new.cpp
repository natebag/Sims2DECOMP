typedef unsigned int uint;

struct EAHeap {
    void* MallocAligned(uint size, uint align, uint flags, int extra);
};

EAHeap* MainHeap();
void* memset(void*, int, uint);

struct ISimInstance {
    void* operator new(uint size);
};

void* ISimInstance::operator new(uint size) {
    EAHeap* heap = MainHeap();
    void* p = heap->MallocAligned(size, 16, 0, 0);
    memset(p, 0, size);
    return p;
}
