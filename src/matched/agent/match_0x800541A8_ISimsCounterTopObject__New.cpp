typedef unsigned int uint;

struct EAHeap {
    void* MallocAligned(uint size, uint align, uint flags, int extra);
};

EAHeap* MainHeap();
void* memset(void*, int, uint);

struct ISimsCounterTopObject {
    ISimsCounterTopObject();
    static ISimsCounterTopObject* New();
};

inline void* operator new(uint, void* p) { return p; }

ISimsCounterTopObject* ISimsCounterTopObject::New() {
    EAHeap* heap = MainHeap();
    void* p = heap->MallocAligned(1216, 16, 0, 0);
    memset(p, 0, 1216);
    ISimsCounterTopObject* obj = new (p) ISimsCounterTopObject;
    return obj;
}
