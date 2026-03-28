typedef unsigned int uint;

struct EAHeap {
    void* MallocAligned(uint size, uint align, uint flags, int extra);
};

EAHeap* MainHeap();
void* memset(void*, int, uint);

struct IShrubObject {
    IShrubObject();
    static IShrubObject* New();
};

inline void* operator new(uint, void* p) { return p; }

IShrubObject* IShrubObject::New() {
    EAHeap* heap = MainHeap();
    void* p = heap->MallocAligned(1216, 16, 0, 0);
    memset(p, 0, 1216);
    IShrubObject* obj = new (p) IShrubObject;
    return obj;
}
